#include "global.h"
#include "util.h"

TreeNode* newNode(int kind){
    int i;
    TreeNode* t=(TreeNode*)malloc(sizeof(TreeNode));
    if(t==NULL)
      fprintf(listing,"Out of memory error at line %d\n",lineno);
    else{
        for(i=0;i<MAXCHILDREN;i++)
          t->child[i]=NULL;
        t->sibling=NULL;
        t->nodekind=kind>>4;

        switch(t->nodekind){
            case NODE_STATEMENT: t->kind = kind&0xF; break;
            case NODE_EXPRESSION: t->kind = kind&0xF; t->type = EXPTYPE_VOID; break;
            case NODE_DECLARE: t->kind = kind&0xF; break;
            case NODE_TYPE: t->kind = kind&0xF; break;
            default: break;
        }
        t->lineno=lineno;
        t->ERROR_STATE=0;
    }
    return t;
}

void printToken(TokenType token, const char * tokenString){
    switch(token){
        case ENDFILE:
            fprintf(listing,"EOF\n");break;
        case ERROR:
            fprintf(listing,"ERROR:%s\n",tokenString);
        case TOKEN_PROGRAM:
        case TOKEN_CONST:
        case TOKEN_TYPE:
        case TOKEN_VAR:
        case TOKEN_PROCEDURE:
        case TOKEN_FUNCTION:
        case TOKEN_OF:
        case TOKEN_BEGIN:
        case TOKEN_END:
        case TOKEN_IF:
        case TOKEN_THEN:
        case TOKEN_ELSE:
            fprintf(listing,"reserved word: %s\n", tokenString); break;
        case TOKEN_TO:
            fprintf(listing,"to\n"); break;
        case TOKEN_DOWNTO:
            fprintf(listing,"down to\n"); break;
        case TOKEN_READ:
            fprintf(listing,"read\n"); break;
        case TOKEN_WRITE:
            fprintf(listing,"write\n"); break;
        case TOKEN_WRITELN:
            fprintf(listing,"writeln\n"); break;            

        case TOKEN_EQUAL:   
            fprintf(listing,"= %s\n",tokenString); break;
        case TOKEN_UNEQUAL:   
            fprintf(listing,"<> %s\n",tokenString); break;
        case TOKEN_GE:   
            fprintf(listing,">= %s\n",tokenString); break;
        case TOKEN_GT:   
            fprintf(listing,"> %s\n",tokenString); break;
        case TOKEN_LE:   
            fprintf(listing,"<= %s\n",tokenString); break;
        case TOKEN_LT:   
            fprintf(listing,"< %s\n",tokenString); break;
        case TOKEN_PLUS:    
            fprintf(listing,"+\n"); break;
        case TOKEN_MINUS:   
            fprintf(listing,"-\n"); break;
        case TOKEN_MUL:     
            fprintf(listing,"*\n"); break;
        case TOKEN_DIV:     
            fprintf(listing,"\\n"); break;
        case TOKEN_OR:      
            fprintf(listing,"or\n"); break;
        case TOKEN_AND:     
            fprintf(listing,"and\n"); break; 
        case TOKEN_MOD:     
            fprintf(listing,"mod\n"); break; 
        case TOKEN_LB:     
            fprintf(listing,"[\n"); break;
        case TOKEN_RB:      
            fprintf(listing,"]\n"); break;
        case TOKEN_SEMI:    
            fprintf(listing,";\n"); break;
        case TOKEN_DOT:     
            fprintf(listing,".\n"); break;
        case TOKEN_DOTDOT:  
            fprintf(listing,".\n"); break;
        case TOKEN_LP:      
            fprintf(listing,"(\n"); break;
        case TOKEN_RP:      
            fprintf(listing,")\n"); break;
        case TOKEN_COMMA:   
            fprintf(listing,",\n"); break;
        case TOKEN_COLON:   
            fprintf(listing,":\n"); break;

        case TOKEN_INTEGER_TYPE:
        case TOKEN_BOOLEAN_TYPE:
        case TOKEN_CHAR_TYPE:
        case TOKEN_REAL_TYPE:
        case TOKEN_ARRAY:
            fprintf(listing,"TYPE, name=%s\n",tokenString); break;

        case TOKEN_TRUE:
        case TOKEN_FALSE:
            fprintf(listing,"BOOLEAN, val=%s\n",tokenString); break;

        case TOKEN_INT: fprintf(listing,"INT, val=%s\n",tokenString); break;
        case TOKEN_REAL: fprintf(listing,"REAL, val=%s\n",tokenString); break;
        case TOKEN_CHAR: fprintf(listing,"CHAR, val=%s\n",tokenString); break;
        case TOKEN_STRING: fprintf(listing,"STRING, val=%s\n",tokenString); break;

        case TOKEN_ID: fprintf(listing,"ID name=%s\n",tokenString); break;

        case TOKEN_ABS: fprintf(listing,"abs\n"); break;
        case TOKEN_CHR: fprintf(listing,"chr\n"); break;
        case TOKEN_ODD: fprintf(listing,"odd\n"); break;
        case TOKEN_ORD: fprintf(listing,"ord\n"); break;
        case TOKEN_PRED:fprintf(listing,"pred\n"); break;
        case TOKEN_SQR: fprintf(listing,"sqr\n"); break;
        case TOKEN_SQRT:fprintf(listing,"sqrt\n"); break;
        case TOKEN_SUCC:fprintf(listing,"succ\n"); break;
        
        default:
            fprintf(listing,"Ttoken:%s\n",tokenString);
    }
}

TreeNode * newOpExpNode(TreeNode * first, TreeNode * second, TokenType op){
    TreeNode * t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if(t==NULL)
      fprintf(listing,"Out of memory error at line %d\n",lineno);
    else{
        t->kind=EXP_OP&0xF;
        for(i=0;i<MAXCHILDREN;i++)
          t->child[i]=NULL;
        t->sibling=NULL;
        t->nodekind=NODE_EXPRESSION;
        t->attr.op=op;
        t->lineno=lineno;
        t->child[0]=first;
        t->child[1]=second;
    }
    return t;

}


TreeNode * newFuncSysExpNode(TokenType op, TreeNode* args){
    TreeNode * t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if(t==NULL)
      fprintf(listing,"Out of memory error at line %d\n",lineno);
    else{
        t->kind=EXP_FUNC_SYS&0xF;
        for(i=0;i<MAXCHILDREN;i++)
          t->child[i]=NULL;
        t->sibling=NULL;
        t->nodekind=NODE_EXPRESSION;
        t->child[0]=args;
        t->attr.op=op;
        t->lineno=lineno;
    }
    return t;

}

void freeNode(TreeNode *node){
    int i;
    for(i=0;i<MAXCHILDREN;i++)
      free(node->child[i]);
    free(node->sibling);
    free(node);
}


char* copyString(char *s){
    int n;
    char *t;
    if(s==NULL)
      return NULL;
    n=strlen(s)+1;
    t=malloc(n);
    if(t==NULL)
      fprintf(listing,"Out of memory error at line %d\n",lineno);
    else
      strcpy(t,s);
    return t;
}

//used for printTree
static indentno=0;
#define INDENT indentno+=2
#define UNINDENT indentno-=2

static void printSpaces(void){
    int i;
    for(i=0;i<indentno;i++)
      fprintf(listing," ");
}

void printTree(TreeNode * tree){
    int i;
    INDENT;
    while(tree!=NULL){
        printSpaces();
        switch(tree->nodekind){
            case(NODE_STATEMENT):
                switch((NODE_STATEMENT<<4)+tree->kind){
                    case STMT_LABEL:    
                        fprintf(listing,"Statement label%d\n",tree->attr.val); break;
                    case STMT_ASSIGN:   
                        fprintf(listing,"Statement assign\n"); break;
                    case STMT_GOTO:     
                        fprintf(listing,"goto %d\n",tree->attr.val); break;
                    case STMT_IF:       
                        fprintf(listing,"if\n"); break;
                    case STMT_REPEAT:   
                        fprintf(listing,"repeat\n"); break;
                    case STMT_WHILE:    
                        fprintf(listing,"while\n"); break;
                    case STMT_CASE:     
                        fprintf(listing,"case\n"); break;
                    case STMT_FOR:      
                        fprintf(listing,"for direction:");printToken(tree->attr.op,"\0"); break;
                    case STMT_PROC_SYS:  
                        fprintf(listing,"system procedure:");printToken(tree->attr.op,"\0"); break;
                    case STMT_PROC_ID:   
                        fprintf(listing,"procedure:"); break;
                    default: fprintf(listing,"Other Statement type\n"); break;
                }
                //printf("STATEMENT:%0x",(NODE_STATEMENT<<4)+tree->kind.stmt);
            break;
        
            case(NODE_EXPRESSION):
               switch((NODE_EXPRESSION<<4)+tree->kind){
                    case EXP_OP:
                        fprintf(listing,"EXP op: "); printToken(tree->attr.op,"\0"); break;
                    case EXP_ID: 
                        fprintf(listing,"Exp: %s\n",tree->attr.name); break;
                    case EXP_CASE: 
                        fprintf(listing,"Exp case:"); break;
                    case EXP_FUNC_ID: 
                        fprintf(listing,"Func:"); break;
                    case EXP_FUNC_SYS: 
                        fprintf(listing,"Sys func:");
                        printToken(tree->attr.op,"\0"); break;
                    case EXP_CONST:
                        switch(tree->type){
                            case EXPTYPE_INT: 
                                fprintf(listing,"const int, val=%d\n",tree->attr.val); break;
                            case EXPTYPE_REAL: 
                                fprintf(listing,"const real, val%lf\n",tree->attr.real_val); break;
                            case EXPTYPE_CHAR: 
                                fprintf(listing,"const char, val%c\n",tree->attr.char_val); break;
                            case EXPTYPE_STRING: 
                                fprintf(listing,"const string, val%s\n",tree->attr.string_val); break;
                        }
                        break;                   
                    default: fprintf(listing,"Other Expression type\n");
                }
                //printf("EXPRESSION:%0x",tree->kind);
            break;
        
            case(NODE_DECLARE):
                switch((NODE_DECLARE<<4)+tree->kind){
                    case DECL_ROUTINEHEAD: 
                        fprintf(listing,"Routine head\n");break;
                    case DECL_PROCEDURE: 
                        fprintf(listing,"Declare procedure\n");break;
                    case DECL_PROCEDUREHEAD: 
                        fprintf(listing,"Procedure head %s\n",tree->attr.name);break;
                    case DECL_CONST: 
                        fprintf(listing,"Const:\n");break;
                    case DECL_TYPE: 
                        fprintf(listing,"Type:\n");break;
                    case DECL_VAR: 
                        fprintf(listing,"Var:\n");break;
                    case DECL_FUNCTION: 
                        fprintf(listing,"Function \n");break;
                    case DECL_FUNCTIONHEAD:
                        fprintf(listing,"Function Head:%s\n",tree->attr.name);break;
                    case DECL_VAR_PARA:
                        fprintf(listing,"var parameter:\n");break;
                    case DECL_VAL_PARA:
                        fprintf(listing,"val parameters:\n");break;
                }
                //printf("DECLARE:%0x",(NODE_DECLARE<<4)+tree->kind);
            break;
            
            case(NODE_TYPE):
                switch((NODE_TYPE<<4)+tree->kind){
                    case TYPE_SIMPLE_ID: 
                        fprintf(listing,"type id\n"); break;
                    case TYPE_SIMPLE_ENUM: 
                        fprintf(listing,"type enum\n"); break;
                    case TYPE_SIMPLE_LIMIT: 
                        fprintf(listing,"type limit\n"); break;
                    case TYPE_SIMPLE_SYS:
                        switch(tree->type){
                            case EXPTYPE_INT:
                                fprintf(listing,"type integer\n");break;
                            case EXPTYPE_REAL:
                                fprintf(listing,"type real\n");break;
                            case EXPTYPE_CHAR:
                                fprintf(listing,"type char\n");break;
                            case EXPTYPE_BOOL:
                                fprintf(listing,"type boolean\n");break;
                        }
                    break;                    
                    case TYPE_ARRAY: 
                        fprintf(listing,"type array\n");break;
                    case TYPE_RECORD: 
                        fprintf(listing,"type record\n");break;
                    default: 
                        fprintf(listing,"Other type\n");break;
                }
                //printf("TYPE:%0x",(NODE_TYPE<<4)+tree->kind);
            break;

            default: fprintf(listing,"Other nodes\n"); break;
        }

        for(i=0;i<MAXCHILDREN;i++)
          printTree(tree->child[i]);
        tree=tree->sibling;
    }
    UNINDENT;
}

















