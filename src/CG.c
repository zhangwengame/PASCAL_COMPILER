#include "CG.h"
#include "util.h"
#include "analyze.h"
#include "symtab.h"
#define EMITCODE(asm) fprintf(codename, "%s", asm);
#define EMITDATA(asm) fprintf(dataname, "%s", asm);

FILE* codename = NULL;
FILE* dataname = NULL;
FILE* ff=NULL;

char tmp[200];


void HandleExpOp(TreeNode* pnode){

	
	if (pnode->child[0]!=NULL && pnode->child[1]!=NULL){
		GenCode(pnode->child[0]);
		EMITCODE("pushl %eax\n");
	

		GenCode(pnode->child[1]);
		EMITCODE("pushl %eax\n");


		if ((pnode->child[0]->RuningType>EXPTYPE_REAL||pnode->child[0]->RuningType>EXPTYPE_REAL)&&(pnode->child[0]->RuningType != (pnode->child[1])->RuningType)){
			if (!(pnode->child[0]->ERROR_STATE||pnode->child[1]->ERROR_STATE)){
 				ErrorHandler(ERROR_TYPE_MISMATCH, pnode);
 			}
 			pnode->ERROR_STATE=ERROR_TYPE_MISMATCH;
 			return;			
 		}
 		else if (pnode->child[0]->ERROR_STATE||pnode->child[1]->ERROR_STATE){
 			pnode->ERROR_STATE=ERROR_TYPE_MISMATCH;
 			return;
 		}
 		
		if ((pnode->child[0])->RuningType==EXPTYPE_REAL && (pnode->child[1])->RuningType==EXPTYPE_REAL)
			pnode->RuningType=EXPTYPE_REAL;
		if ((pnode->child[0])->RuningType==EXPTYPE_INT && (pnode->child[1])->RuningType==EXPTYPE_INT)
			pnode->RuningType=EXPTYPE_INT; 

	}
	else {
		EMITCODE("pushl $0\n");
		GenCode(pnode->child[0]);
		EMITCODE("pushl %eax\n");
		pnode->RuningType=(pnode->child[0])->RuningType;
	}



	if (pnode->RuningType==EXPTYPE_INT){
		EMITCODE("popl %ebx\n");
		EMITCODE("popl %eax\n");
		switch(pnode->attr.op)
		{
		case TOKEN_PLUS:
			EMITCODE("addl %ebx, %eax\n");
			break;
		case TOKEN_MINUS:
			EMITCODE("subl %ebx, %eax\n");
			break;
		case TOKEN_MUL:
			EMITCODE("xorl %edx, %edx\nimull %ebx\n");
			break;
		case TOKEN_DIV:
			EMITCODE("xorl %edx, %edx\nidivl %ebx\n");
			break;
		case TOKEN_MOD:
			EMITCODE("xorl %edx, %edx\nidivl %ebx\n");
			EMITCODE("movl %edx, %eax\n");
			break;
		case TOKEN_LT:
			EMITCODE("cmpl %ebx, %eax\n");
			EMITCODE("movl $0, %eax\n");
			EMITCODE("setlb %al\n");
			break;
		case TOKEN_LE:
			EMITCODE("cmpl %ebx, %eax\n");
			EMITCODE("movl $0, %eax\n");
			EMITCODE("setngb %al\n");
			break;
		case TOKEN_GT:
			EMITCODE("cmpl %ebx, %eax\n");
			EMITCODE("movl $0, %eax\n");
			EMITCODE("setgb %al\n");
			break;
		case TOKEN_GE:
			EMITCODE("cmpl %ebx, %eax\n");
			EMITCODE("movl $0, %eax\n");
			EMITCODE("setnlb %eax\n");
			break;
		case TOKEN_EQUAL:
			EMITCODE("cmpl %ebx, %eax\n");
			EMITCODE("movl $0, %eax\n");
			EMITCODE("seteb %al\n");
			break;
		case TOKEN_UNEQUAL:
			EMITCODE("cmpl %ebx, %eax\n");
			EMITCODE("movl $0, %eax\n");
			EMITCODE("setneb %al\n");
			break;
		}	
	}
	else {
		// EMITCODE("flds (%esp)\n");		
		// to be decided
		//char fcom_lable_false[100], fcom_lable_end[100]; 
		if (pnode->child[1]!=NULL&&((pnode->child[1])->RuningType == EXPTYPE_INT)){
			EMITCODE("filds (%esp)\n");	
		}
		else EMITCODE("flds (%esp)\n");			
		if ((pnode->child[0])->RuningType == EXPTYPE_INT){
			EMITCODE("filds 4(%esp)\n");	
		}
		else EMITCODE("flds 4(%esp)\n");	
		EMITCODE("popl %eax\n");
		EMITCODE("popl %eax\n");
		
		switch(pnode->attr.op){
			case TOKEN_PLUS:
				EMITCODE("faddp\n");
				break;
			case TOKEN_MINUS:
				EMITCODE("fsubp\n");
				break;
			case TOKEN_MUL:
				EMITCODE("fmulp\n");
				break;
			case TOKEN_DIV:
				EMITCODE("fdivp\n");
				break;
			case TOKEN_LT:
			case TOKEN_LE:
			case TOKEN_GT:
			case TOKEN_GE:
			case TOKEN_EQUAL:	
				// EMITCODE("fxch %st(1)\n");			
				EMITCODE("fucomip %st(1),%st\n");
				EMITCODE("fstp %st(0)\n");
				EMITCODE("movl $0x0, %eax\n");
				break;
		}
		switch(pnode->attr.op){
			case TOKEN_PLUS:
			case TOKEN_MINUS:
			case TOKEN_MUL:
			case TOKEN_DIV:				
				EMITCODE("subl $4, %esp\n");
				EMITCODE("fstps (%esp)\n");
				EMITCODE("popl %eax\n");	
				break;
			case TOKEN_LT:				
				// if (pnode->attr.op == TOKEN_LT){
				// 	strcpy(fcom_lable_false, GetLabel());
				// 	strcpy(fcom_lable_end, GetLabel());
				// 	sprintf(tmp, "jnb %s\n", fcom_lable_false);
				// 	EMITCODE(tmp);
				// }				
				EMITCODE("setb %al\n");
				break;
			case TOKEN_LE:			
				// if (pnode->attr.op == TOKEN_LE){
				// 	strcpy(fcom_lable_false, GetLabel());
				// 	strcpy(fcom_lable_end, GetLabel());
				// 	sprintf(tmp, "jnbe %s\n", fcom_lable_false);
				// 	EMITCODE(tmp);	
				// }
				EMITCODE("setbe %al\n");
				break;
			case TOKEN_GT:				
				// if (pnode->attr.op == TOKEN_GT){
				// 	strcpy(fcom_lable_false, GetLabel());
				// 	strcpy(fcom_lable_end, GetLabel());
				// 	sprintf(tmp, "jna %s\n", fcom_lable_false);
				// 	EMITCODE(tmp);
				// }
				EMITCODE("seta %al\n");
				break;
			case TOKEN_GE:				
				// if (pnode->attr.op == TOKEN_GE){
				// 	strcpy(fcom_lable_false, GetLabel());
				// 	strcpy(fcom_lable_end, GetLabel());
				// 	sprintf(tmp, "jnae %s\n", fcom_lable_false);
				// 	EMITCODE(tmp);
				// }
				EMITCODE("setae %al\n");
				break;
			case TOKEN_EQUAL:
				// if (pnode->attr.op == TOKEN_EQUAL){
				// 	strcpy(fcom_lable_false, GetLabel());
				// 	strcpy(fcom_lable_end, GetLabel());
				// 	sprintf(tmp, "jne %s\n", fcom_lable_false);
				// 	EMITCODE(tmp);
				// }
				// EMITCODE("movl $1, (%esp)\n");
				// sprintf(tmp, "jmp %s\n", fcom_lable_end);
				// EMITCODE(tmp);
				// sprintf(tmp, "%s:\n", fcom_lable_false);
				// EMITCODE(tmp);
				// EMITCODE("movl $0, (%esp)\n");
				// sprintf(tmp, "%s:\n", fcom_lable_end);
				// EMITCODE(tmp);
				EMITCODE("sete %al\n");
				break;
			default: break;
		}	
		
		// EMITCODE("subl $4, %esp\n");
		// EMITCODE("fstps (%esp)\n");
		// EMITCODE("popl %eax\n");
		
	}
}



void HandleExpId(TreeNode* pnode){
	
	int level;
	int offset;
	int lower;
	ExpType cgtype;
	LookupRet st_var;


	VariableList ssvar=varListLookup(pnode->attr.name);
 	if (ssvar==NULL){
 		if (!pnode->ERROR_STATE){
 			ErrorHandler(ERROR_VAR_MISS, pnode);
 			pnode->ERROR_STATE=ERROR_VAR_MISS;
 		}
 		return;
 	}

 	cgtype=ssvar->type;

	if (cgtype==EXPTYPE_ARRAY){  // array of int real bool char

		//st_var=arrayLookup(pnode->attr.name,(pnode->child[0])->attr.val);
		if (ssvar->pAttr==NULL){
			if (!pnode->ERROR_STATE){
 				ErrorHandler(ERROR_VAR_NOTARRAY, pnode);
 				pnode->ERROR_STATE=ERROR_VAR_NOTARRAY;
 			}
 			return;
 		}

		lower=(((ArrayDef)ssvar->pAttr)->subBound)->LowerBound.i;
		level=ssvar->memloc.baseLoc;
		offset=ssvar->memloc.offset;
		//offset=st_var.totalOff;

	}
	else if (cgtype==EXPTYPE_RECORD){ // record {int real bool char}
		st_var=recordLookup(pnode->attr.name,(pnode->child[0])->attr.name);
		level=st_var.jumpLevel;
		offset=st_var.totalOff;
	}
	else {	 //int real bool char
		level=ssvar->memloc.baseLoc;
		offset=ssvar->memloc.offset;
	}

	if (cgtype==EXPTYPE_ARRAY){
		CGNodeExpression(pnode->child[0]);
		sprintf(tmp,"movl $%d, %%ebx\n",lower);                 
		EMITCODE(tmp);	

		EMITCODE("subl %ebx, %eax\n");
		EMITCODE("movl $4, %ebx\n");
		EMITCODE("imull %ebx, %eax\n");
		sprintf(tmp,"movl $%d, %%edi\n",offset);
		EMITCODE(tmp);
		EMITCODE("addl %eax, %edi\n");
	}
	else {
		sprintf(tmp, "movl $%d, %%edi\n", offset);
		EMITCODE(tmp);	
	}

	//printf("%d\n",cgtype);
	if (cgtype==EXPTYPE_ARRAY){ 
		cgtype=((ArrayDef)ssvar->pAttr)->arrayType;
	}
	else if (cgtype==EXPTYPE_RECORD){
		cgtype=st_var.type;	
	}		
	//printf("%d\n",cgtype);
	EMITCODE("movl %ecx, %esi\n");
	while (level){
		EMITCODE("movl (%esi), %eax\n");
		EMITCODE("movl %eax, %esi\n");
		level=level-1;
	}
	EMITCODE("addl %edi, %esi\n");


	if (cgtype==EXPTYPE_INT || cgtype==EXPTYPE_CHAR || cgtype==EXPTYPE_BOOL){
		EMITCODE("movl (%esi), %eax\t# calculate ExpId \n");
		pnode->RuningType=EXPTYPE_INT;
		//printf("EXPTYPE_INT\n");
	}
	else if (cgtype==EXPTYPE_REAL){
		EMITCODE("movl (%esi), %eax\n"); 		// TODO: UNDONE
		pnode->RuningType=EXPTYPE_REAL;
		//printf("EXPTYPE_REAL\n");
	}

}

void HandleConstExp(TreeNode* pnode){
	char const_real_data[100];	

	switch (pnode->type){
		case EXPTYPE_INT:
			sprintf(tmp, "movl $%d, %%eax\t# calculate int ExpConst \n", pnode->attr.val);
			EMITCODE(tmp);		
			pnode->RuningType=EXPTYPE_INT;
			break;
		case EXPTYPE_CHAR:
			sprintf(tmp, "movl $%d, %%eax\t# calculate char ExpConst \n", pnode->attr.char_val);
			EMITCODE(tmp);
			pnode->RuningType=EXPTYPE_INT;
			break;
		case EXPTYPE_BOOL:
			sprintf(tmp, "movl $%d, %%eax\t# calculate bool ExpConst \n", pnode->attr.val);
			EMITCODE(tmp);
			pnode->RuningType=EXPTYPE_INT;
			break;
		case EXPTYPE_REAL:
			strcpy(const_real_data, GetDataLabel());	
			sprintf(tmp, ".%s:\n\t.float %lf\n",const_real_data, pnode->attr.real_val);							// UNDONE
		    EMITDATA(tmp);
        	sprintf(tmp,"movl $.%s, %%ebx\t# calculate real ExpConst \n",const_real_data); 	// UNDONE
        	EMITCODE(tmp);
        	EMITCODE("movl (%ebx), %eax\n");			// Make const pointer the const value
        	pnode->RuningType=EXPTYPE_REAL;
			break;			
	}
}


void PopParam(TreeNode* pnode,SimpleTypeList judge_var){
	
	if (pnode==NULL || judge_var==NULL)
		return;

	if (judge_var->isVar==1){
		CGNodeExpression(pnode);
		EMITCODE("popl %eax\n");
		EMITCODE("movl %eax, (%esi)\n");
	}
	else EMITCODE("popl %eax\n");

	PopParam(pnode->sibling,judge_var->next);
}

void PushParam(TreeNode* pnode){
	if (pnode->sibling!=NULL){
		PushParam(pnode->sibling);
	}

	CGNodeExpression(pnode);
	EMITCODE("pushl %eax\n");

}

void HandleFuncExc(TreeNode* pnode){

	FuncList judge_var=funcListLookup(pnode->attr.name);

	EMITCODE("pushl %eax\n");  // pushl return value	

	PushParam(pnode->child[0]);


	EMITCODE("pushl %ecx\n");  // save access link
	EMITCODE("movl %esp, %ecx\n");

	sprintf(tmp, "call %s\n", pnode->attr.name);
	EMITCODE(tmp);

	EMITCODE("popl %ecx\n");


	PopParam(pnode->child[0],judge_var->paraList);

	EMITCODE("popl %eax\n");  // popl return value

}


void HandleProcExc(TreeNode* pnode){

	ProcList judge_var=procListLookup(pnode->attr.name);

	PushParam(pnode->child[0]);


	EMITCODE("pushl %ecx\n");  // save access link
	EMITCODE("movl %esp, %ecx\n");

	sprintf(tmp, "call %s\n", pnode->attr.name);
	EMITCODE(tmp);

	EMITCODE("popl %ecx\n");

	PopParam(pnode->child[0],judge_var->paraList);
}



void HandleAssignStmt(TreeNode* pnode){
	//if  (pnode->attr.op==TOKEN_ID){   // x:=1;
		FuncList r_ssfuc=NULL;
		VariableList l_ssvar=varListLookup((pnode->child[0])->attr.name);
		//printf("%d,%d\n",(pnode->child[1])->nodekind,(pnode->child[1])->kind);
		if ((pnode->child[1])->nodekind==2&&(pnode->child[1])->kind>4)
			r_ssfuc=funcListLookup((pnode->child[1])->attr.name);
		GenCode(pnode->child[1]);
		EMITCODE("pushl %eax\n");
		//VariableList r_ssvar=funcListLookup((pnode->child[1])->attr.name);
		if (l_ssvar==NULL){
			if (!pnode->child[1]->ERROR_STATE){
 			ErrorHandler(ERROR_VAR_MISS, (pnode->child[0]));
 			pnode->child[0]->ERROR_STATE=ERROR_VAR_MISS;
 			pnode->ERROR_STATE=ERROR_VAR_MISS;
 			}
 			return;
			//printf("here2\n");
		}
		else if (l_ssvar->isConst){
			if (!(pnode->child[0]->ERROR_STATE||pnode->child[1]->ERROR_STATE)){
 			ErrorHandler(ERROR_VAR_MODIFYCONST, (pnode->child[0]));
 			//pnode->child[0]->ERROR_STATE=ERROR_VAR_MODIFYCONST;
 			pnode->ERROR_STATE=ERROR_VAR_MODIFYCONST;
 			}		
 			return;
		}
		if (r_ssfuc&&l_ssvar->type<r_ssfuc->retType){
			if (!(pnode->child[0]->ERROR_STATE||pnode->child[1]->ERROR_STATE)){
				ErrorHandler(ERROR_TYPE_MISMATCH,pnode);
				//pnode->child[0]->ERROR_STATE=ERROR_TYPE_MISMATCH;
 				pnode->ERROR_STATE=ERROR_TYPE_MISMATCH;
			}
			return;
		}
		else if (!r_ssfuc&&(l_ssvar->type<5)&&l_ssvar->type<pnode->child[1]->RuningType){
			//printf("%d,%d\n",l_ssvar->type,pnode->child[1]->RuningType);
			//printf("%d,%d\n",pnode->child[0]->ERROR_STATE,pnode->child[1]->ERROR_STATE);
			if (!(pnode->child[0]->ERROR_STATE||pnode->child[1]->ERROR_STATE)){
				ErrorHandler(ERROR_TYPE_MISMATCH,pnode);
				//pnode->child[0]->ERROR_STATE=ERROR_TYPE_MISMATCH;
 				pnode->ERROR_STATE=ERROR_TYPE_MISMATCH;
			}
			return;
		}
		else{
		GenCode(pnode->child[0]);
		EMITCODE("popl %eax\n");
		EMITCODE("movl %eax, -0(%esi)\t# assign\n");
		}
	/*}
	else if (pnode->attr.op==TOKEN_ARRAY){ //x[1]:=1
		GenCode(pnode->child[2]);
		EMITCODE("pushl %eax\n");
		GenCode(pnode->child[1]);
		EMITCODE("pushl %eax\n");
		GenCode(pnode->child[0]);
		EMITCODE("popl %eax\n");
		EMITCODE("movl %ebx,$4\n");  //int = 4  
		EMITCODE("xor %edx, %edx\nimull %ebx\n");
		EMITCODE("addl %esi,%eax\n");

		EMITCODE("popl %eax\n");
		EMITCODE("movl %eax, -0(%esi); assign\n");		


	}
	else if (pnode->attr.op==TOKEN_RECORD){  //x.x:=1
    	
	}*/
}

char* GetLabel()
{
	static int label_cnt = 0;
	char tmp2[1024];
	static char label[1024];
	strcpy(label, "__CG__label");
	sprintf(tmp2, "%d", label_cnt);
	strcat(label, tmp2);
	label_cnt++;
	return label;
}

char* GetSysLabel(int val)
{
	char tmp2[1024];
	static char label[1024];
	strcpy(label, "__CG__sys_label");
	sprintf(tmp2, "%d", val);
	strcat(label, tmp2);
	return label;
}

char* GetDataLabel(){
    static int datalabel_cnt = 0;
    char tmp[100];
    static char datalabel[200];
    strcpy(datalabel,"_REALNUM");
    sprintf(tmp,"%d",datalabel_cnt);
    strcat(datalabel,tmp);
    datalabel_cnt++;
    return datalabel;
}


void HandleLabelStmt(TreeNode* pnode){
	char sys_label[100];
	strcpy(sys_label, GetSysLabel(pnode->attr.val));
	sprintf(tmp, "%s:\n", sys_label); 
	EMITCODE(tmp);	
	GenCode(pnode->child[0]);
}

void CGStmtGoto(TreeNode* pnode){
	char sys_label[100];
	strcpy(sys_label, GetSysLabel(pnode->attr.val));
	sprintf(tmp, "jmp %s\n", sys_label); 
	EMITCODE(tmp);		
}


void HandleCaseStmt(TreeNode* pnode){

	char case_end[100];	
	strcpy(case_end, GetLabel());	

	GenCode(pnode->child[0]);
	EMITCODE("pushl %eax\n");
	GenCode(pnode->child[1]);

}

void HandleCaseExp(TreeNode* pnode){

	char case_end[100];	
	strcpy(case_end, GetLabel());	

	GenCode(pnode->child[0]);
	
	EMITCODE("popl %ebx\n");
	EMITCODE("cmpl %ebx,%eax\n");

	sprintf(tmp, "jne %s\n", case_end);  //unequal
	EMITCODE(tmp);

	GenCode(pnode->child[1]);

	sprintf(tmp, "%s:\n", case_end);
	EMITCODE(tmp);
	if (pnode->sibling!=NULL)
		EMITCODE("pushl %ebx\n");
}

void HandleWhileStmt(TreeNode* pnode){
	char while_start[100], while_end[100];
	strcpy(while_start, GetLabel());
	strcpy(while_end, GetLabel());	


	sprintf(tmp, "%s:\n", while_start);
	EMITCODE(tmp);

	GenCode(pnode->child[0]);

	EMITCODE("cmpl $0, %eax\n");
	sprintf(tmp,"je %s\n",while_end);
	EMITCODE(tmp);

	GenCode(pnode->child[1]);
	sprintf(tmp,"jmp %s\n",while_start);
	EMITCODE(tmp);
	sprintf(tmp, "%s:\n", while_end);
	EMITCODE(tmp);
}


void HandleRepeatStmt(TreeNode* pnode){
	char repeat_start[100];
	strcpy(repeat_start, GetLabel());
	
	sprintf(tmp,"%s:\n",repeat_start);
	EMITCODE(tmp);	

	GenCode(pnode->child[0]);
	GenCode(pnode->child[1]);

	EMITCODE("cmpl $0, %eax\n");
	sprintf(tmp,"je %s\n",repeat_start);
	EMITCODE(tmp);
	
}




void HandleForStmt(TreeNode* pnode){

	char for_start[100], for_end[100];
	int i;
	strcpy(for_start, GetLabel());
	strcpy(for_end, GetLabel());

	//chuzhi
	GenCode(pnode->child[1]);
	EMITCODE("pushl %eax\n");
	GenCode(pnode->child[0]);
	EMITCODE("popl %eax\n");
	//EMITCODE("addl %ecx, %esi\n");
	EMITCODE("movl %eax, -0(%esi)  \n");

	
	//xunhuan
	if(pnode->attr.op == TOKEN_TO){  //to
		sprintf(tmp,"%s:\n",for_start);
		EMITCODE(tmp);	
		GenCode(pnode->child[2]);
		EMITCODE("pushl %eax\n");
		GenCode(pnode->child[0]);
		EMITCODE("popl %ebx\n");	
		EMITCODE("cmpl %ebx, %eax\n");
		sprintf(tmp, "ja %s\n", for_end);
		EMITCODE(tmp);	

		GenCode(pnode->child[3]);	

		GenCode(pnode->child[0]);
		EMITCODE("inc %eax\n");
		EMITCODE("movl %eax, -0(%esi)\n");	

		sprintf(tmp,"jmp %s\n",for_start);
		EMITCODE(tmp);	
		sprintf(tmp,"%s:\n",for_end);
		EMITCODE(tmp);	
	}
	 else {
		sprintf(tmp,"%s:\n",for_start);
		EMITCODE(tmp);	
		GenCode(pnode->child[2]);
		EMITCODE("pushl %eax\n");
		GenCode(pnode->child[0]);
		EMITCODE("popl %ebx\n");	
		EMITCODE("cmpl %ebx, %eax\n");
		sprintf(tmp, "jb %s\n", for_end);
		EMITCODE(tmp);	

		GenCode(pnode->child[3]);	

		GenCode(pnode->child[0]);
		EMITCODE("dec %eax\n");
		EMITCODE("movl %eax, -0(%esi)\n");	
		
		sprintf(tmp,"jmp %s\n",for_start);
		EMITCODE(tmp);	
		sprintf(tmp,"%s:\n",for_end);
		EMITCODE(tmp);	
	 } //downto
}



void HandleIfStmt(TreeNode* pnode){
	char if_label[100], else_label[100], exit_label[100];
	strcpy(if_label, GetLabel());
	strcpy(else_label, GetLabel());
	strcpy(exit_label, GetLabel());
	
	//panduan
	GenCode(pnode->child[0]);
	EMITCODE("cmpl $1, %eax\n");	
	sprintf(tmp, "je %s \njmp %s\n", if_label, else_label);
	EMITCODE(tmp);	
	
	//if-part
	sprintf(tmp,"%s:\n",if_label);
	EMITCODE(tmp);	
	GenCode(pnode->child[1]);

	sprintf(tmp,"jmp %s\n",exit_label);	
	EMITCODE(tmp);	

	sprintf(tmp, "%s: \n", else_label);
  	EMITCODE(tmp);	

	if (pnode->child[2]!=NULL)
		GenCode(pnode->child[2]);
	
	sprintf(tmp, "%s: \n", exit_label);
  	EMITCODE(tmp);				
}

void HandleOutStmt(TreeNode* pnode){

	TreeNode *tt=NULL;
	

//	if (pnode->child[0]!=NULL)
		tt=pnode->child[0];

	while (tt!=NULL){
		CGNodeExpression(tt);	

		if (tt->RuningType==EXPTYPE_REAL){
			EMITCODE("pusha\n");
			EMITCODE("pushl %eax\n");
			// EMITCODE("flds (%eax)\n");
			EMITCODE("flds (%esp)\n");				// make the original
			EMITCODE("subl $4, %esp\n");
			EMITCODE("fstpl (%esp)\n");
			if  (pnode->attr.op==TOKEN_WRITELN){
				EMITCODE("pushl $.PRINTF_F_N\n");
			}
			else {
				EMITCODE("pushl $.PRINTF_F\n");
			}
			EMITCODE("call printf\n");
			EMITCODE("addl $8, %esp\n");
			EMITCODE("popl %eax\n");
			EMITCODE("popa\n");
		}
		else if (tt->RuningType==EXPTYPE_INT){
			EMITCODE("pusha\n");
			if  (pnode->attr.op==TOKEN_WRITELN){
				EMITCODE("pushl %eax\n");
				EMITCODE("pushl $.PRINTF_I_N\n");
				EMITCODE("call printf\n");
				EMITCODE("addl $8, %esp\n");				
				// EMITCODE("invoke printf,offset lb_writeln_int, %eax\n");
			}
			else{
				EMITCODE("pushl %eax\n");
				EMITCODE("pushl $.PRINTF_I\n");
				EMITCODE("call printf\n");
				EMITCODE("addl $8, %esp\n");	
				// EMITCODE("invoke printf,offset lb_write_int, %eax\n");
			}
			EMITCODE("popa\n");
		}
		tt=tt->sibling;
	}
	
}


void HandleInStmt(TreeNode* pnode){

	TreeNode *tt=NULL;

	char output[100];
	char output_all[100];
	strcpy(output, "invoke crt_scanf, addr lb_read_");//	int_write,eax\n");

//	if (pnode->child[0]!=NULL)
	tt=pnode->child[0];

	while (tt!=NULL){
		CGNodeExpression(tt);
		
		output_all[0]=0;
		strcpy(output_all,output);

		if (tt->RuningType==EXPTYPE_INT)
			strcat(output_all,"int, addr lb_tmp\n");
		else if (tt->RuningType==EXPTYPE_REAL)
			strcat(output_all,"real, addr lb_tmp\n");

		EMITCODE("pusha\n");
		EMITCODE(output_all);
		EMITCODE("popa\n");
		EMITCODE("movl %eax, dword ptr lb_tmp\n");			// UNDONE
		EMITCODE("movl %eax, (%esi)\n");
		tt=tt->sibling;
	}
	
}



void CGNodeExpression(TreeNode* pnode){
	switch (pnode->kind+(NODE_EXPRESSION<<4)){
				case EXP_ID:
				//printf("EXP_ID\n");
				//fflush(stdout);
					HandleExpId(pnode);
					break;
				case EXP_OP:
				//printf("EXP_OP\n");
				//fflush(stdout);
					HandleExpOp(pnode);
					break;
				case EXP_CONST:
					HandleConstExp(pnode);
					break;
				case EXP_CASE:
					HandleCaseExp(pnode);
					break;
				case EXP_FUNC_ID:
					HandleFuncExc(pnode);
					break;
			}
}


void GenCode(TreeNode* pnode){
	int size_param;
	switch (pnode->nodekind){
		case NODE_STATEMENT:
			//printf("NODE_STATEMENT\n");
			//fflush(stdout);
			switch (pnode->kind+(NODE_STATEMENT<<4)){
				case STMT_ASSIGN:
					//printf("STMT_ASSIGN\n");
					//fflush(stdout);
					HandleAssignStmt(pnode);
					break;
				case STMT_IF:
					HandleIfStmt(pnode);
					break;
				case STMT_FOR:
					HandleForStmt(pnode);
					break;
				case STMT_WHILE:
					HandleWhileStmt(pnode);
					break;
				case STMT_REPEAT:
					HandleRepeatStmt(pnode);
					break;	
				case STMT_CASE:
					HandleCaseStmt(pnode);
					break;	
				case STMT_GOTO:
					CGStmtGoto(pnode);
					break;	
				case STMT_LABEL:
					HandleLabelStmt(pnode);
					break;	
				case STMT_PROC_ID:
					HandleProcExc(pnode);
					break;
				case STMT_PROC_SYS:
					switch(pnode->attr.op)
					{
						case TOKEN_WRITE:
							HandleOutStmt(pnode);
							break;
						case TOKEN_WRITELN:
							HandleOutStmt(pnode);
							break;
						case TOKEN_READ:
							HandleInStmt(pnode);
							break;
						default: break;
					}
				break;
				
			}
			break;
		case NODE_EXPRESSION:
				//printf("NODE_EXPRESSION\n");
				//fflush(stdout);
				CGNodeExpression(pnode);
			break;
		case NODE_DECLARE:
			switch (pnode->kind+(NODE_DECLARE<<4)){
				case DECL_ROUTINEHEAD:
					//printf("DECL_ROUTINEHEAD\n");
					//fflush(stdout);

					size_param=enterNewScope(pnode);

					if (pnode->child[3]!=NULL)
  						GenCode(pnode->child[3]);
								
					if (strcmp(pnode->attr.name,"main")){
						sprintf(tmp, "%s: \n",pnode->attr.name);
						EMITCODE(tmp);
					}
					else {
						// EMITCODE("main PROC\n");
						EMITCODE(".globl main\n");
						EMITCODE("\t.type main, @function\n");
						EMITCODE("main:\n");
						EMITCODE("pushl %ebp\n");
						EMITCODE("movl %esp, %ebp\n");
						EMITCODE("movl %esp, %ecx\n");
					}

  					sprintf(tmp, "subl $%d, %%esp\n", size_param);
  					EMITCODE(tmp);		


  					break;
				case DECL_FUNCTION:

					//printf("DECL_FUNCTION\n");
					//fflush(stdout);
					
					funcListInsert(pnode->child[0]);  // give congjie function_head!!!!!!!!!!!!!

					(pnode->child[1])->attr.name=(pnode->child[0])->attr.name;
					GenCode(pnode->child[1]); //routine_head 
	
					
					size_param=leaveScope();
					sprintf(tmp, "addl $%d, %%esp\n", size_param);
  					EMITCODE(tmp);	
					EMITCODE("ret\n");	

					break;
    			case DECL_PROCEDURE:
	
					//printf("DECL_PROCEDURE\n");
					fflush(stdout);
					
					procListInsert(pnode->child[0]);  // give congjie function_head!!!!!!!!!!!!!

					(pnode->child[1])->attr.name=(pnode->child[0])->attr.name;
					GenCode(pnode->child[1]); //routine_head 
				
					size_param=leaveScope();
					sprintf(tmp, "addl $%d, %%esp\n", size_param);
  					EMITCODE(tmp);	
					EMITCODE("ret\n");	

					break;
			}
			break;
		case NODE_TYPE:
			break;
		default: printf("pnode->nodekind Default");
	}
	if(pnode->sibling!=NULL){
		GenCode(pnode->sibling);	
	}
	
}

int CG_main(TreeNode* pnode,char * ffname){
	int size_param;
	char buf[10000];

	codename = fopen("code_part.asm", "w");
	dataname = fopen("data_part.asm", "w");
/*	
EMITCODE("section .data\n");
EMITCODE("\tintformat db \"%d\",0xa,0\n");     
EMITCODE("section .text\n");
EMITCODE("\tglobal main\n");
EMITCODE("main:\n");
*/
	
	// EMITDATA(".386\n");
	// EMITDATA(".model flat,stdcall\n");
	// EMITDATA("option casemap:none\n");
	// EMITDATA("include masm32\\include\\msvcrt.inc\n");
	// EMITDATA("includelib msvcrt.lib\n");

	// EMITDATA("printf  proto C:dword,:dword\n");

	// EMITDATA(".data\n");
	EMITDATA(".PRINTF_I:\n");
	EMITDATA("\t.string \"%i\"\n");
	EMITDATA(".PRINTF_I_N:\n");
	EMITDATA("\t.string \"%i\\n\"\n");
	EMITDATA(".PRINTF_F:\n");
	EMITDATA("\t.string \"%f\"\n");
	EMITDATA(".PRINTF_F_N:\n");
	EMITDATA("\t.string \"%f\\n\"\n");
	// EMITDATA("lb_write_int db '%d',0\n");
	// EMITDATA("lb_writeln_int db '%d',0ah,0dh,0\n");
	// EMITDATA("lb_write_real db '%lf',0\n");
	// EMITDATA("lb_writeln_real db '%lf',0ah,0dh,0\n");
	// EMITDATA("lb_tmp db 0, 0, 0, 0, 0, 0, 0, 0\n");
	// EMITDATA("lb_read_int db '%d',0\n");
	// EMITDATA("lb_read_real db '%f',0\n");

	EMITCODE(".text\n");	
	
	initScope();
	pnode->attr.name="main";
	GenCode(pnode);
	

	size_param=leaveScope();  //li kai zhu yu shi
	sprintf(tmp, "addl $%d, %%esp\n", size_param);
  	EMITCODE(tmp);	
  	EMITCODE("leave\n");
  	EMITCODE("ret\n");
	// EMITCODE("main ENDP\n");
	// EMITCODE("END main\n");
	fclose(codename);
	fclose(dataname);
	
	if (!COMPILE_ERROR){
		ff = fopen(ffname, "w");
		codename = fopen("code_part.asm", "r");
		dataname = fopen("data_part.asm", "r");	
		while(fgets(buf,BUFSIZ,dataname)!=NULL){
			fputs(buf,ff);
		}
		while(fgets(buf,BUFSIZ,codename)!=NULL){
			fputs(buf,ff);
		}	
		fclose(codename);
		fclose(dataname);
		fclose(ff);
	}
}