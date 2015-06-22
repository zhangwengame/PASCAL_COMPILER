#ifndef _UTIL_H_
#define _UTIL_H_

void printToken(TokenType, const char *);

/*TreeNode * newStmtNode(StmtKind s);

TreeNode * newExpNode(ExpKind e);
TreeNode * newOpExpNode(TreeNode*, TreeNode*,TokenType);
TreeNode * newFuncSysExpNode(TokenType op, TreeNode* args);

TreeNode * newDeclNode(DeclKind d);

TreeNode * newTypeNode(TypeKind type);*/
TreeNode * newStmtNode(int s);

TreeNode * newExpNode(int e);
TreeNode * newOpExpNode(TreeNode*, TreeNode*,TokenType);
TreeNode * newFuncSysExpNode(TokenType op, TreeNode* args);

TreeNode * newDeclNode(int d);

TreeNode * newTypeNode(int type);

TreeNode * newNode(int kind);
void freeNode(TreeNode*);

char * copyString(char*);

void printTree(TreeNode *);

#endif
