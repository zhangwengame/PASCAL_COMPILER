#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"
#include "analyze.h"

#define ERROR_RETURN 0xffff
#define SIZE 211
#define PARA_OFFSET_INC 4
#define SHIFT 4
#define ID_MAX_LEN 10

int currentNestLevel = 0;
static int hash (char* key) {
	int temp = 0;
	int i = 0;
	while(key[i] != '\0') {
		temp = ((temp << SHIFT) + key[i]) % SIZE;
		++i;
	}

	return temp;
}

static VariableList variableHashTable[SIZE];
static TypeList typeHashTable[SIZE];
static FuncList funcHashTable[SIZE];
static ProcList procHashTable[SIZE];
static int totalOffset[50];

void ErrorHandler(int errortype, TreeNode * pnode){
	switch (errortype){
		case ERROR_TYPE_MISMATCH:
			printf("Line %d, Error: Different data type can not be calculated.\n",pnode->lineno);
 			fflush(stdout);	
			break;
		case ERROR_VAR_MISS:
			printf("Line %d, Error: The variable %s is not existed.\n",pnode->lineno,pnode->attr.name);
 			fflush(stdout);
			break;
		case ERROR_VAR_NOTARRAY:
			printf("Line %d, Error: The variable %s is not an array.\n",pnode->lineno,pnode->attr.name);
 			fflush(stdout);
			break;
		case ERROR_VAR_MODIFYCONST:
			printf("Line %d, Error: The const variable %s can not be assigned.\n",pnode->lineno,(pnode->child[0])->attr.name);
 			fflush(stdout);	
			break;
		case ERROR_VAR_REDEC:
			printf("Line %d, Error: redeclaration of variable: %s.\n",pnode->lineno,pnode->attr.name);
 			fflush(stdout);	
			break;
		case ERROR_FUNC_REDEC:
			printf("Line %d, Error: redeclaration of function: %s.\n",pnode->lineno,pnode->attr.name);
 			fflush(stdout);	
			break;
	}
	COMPILE_ERROR=1;
	++ERROR_COUNT;
}

SubBoundDef newSubBoundDef(ExpType type, void* lower, void* upper) {
	SubBoundDef new = (SubBoundDef) malloc(sizeof(struct SubBoundDefRec));
	new->boundType = type;
	if(type == EXPTYPE_INT) {
		new->LowerBound.i = *(int*)lower;
		new->UpperBound.i = *(int*)upper;	
	} else if(type == EXPTYPE_CHAR) {
		new->LowerBound.c = *(char*)lower;
		new->UpperBound.c = *(char*)upper;
	} else if(type == EXPTYPE_SIMPLE_ENUM) {
		new->LowerBound.m = (char*)lower;
		new->UpperBound.m = (char*)upper;
	}

	return new;
}

ArrayDef newArrayDef(ExpType arrayType, ExpType boundType, void* lower, void* upper) {
	ArrayDef new = (ArrayDef) malloc(sizeof(struct ArrayDefRec));
	new->arrayType = arrayType;
	new->subBound = newSubBoundDef(boundType, lower, upper);

	return new;
}

EnumDef newEnumDef(char* mark) {
	EnumDef new = (EnumDef) malloc(sizeof(struct EnumDefRec));
	new->mark = mark;
	new->next = NULL;

	return new;
}

EnumDef insertEnumDef(EnumDef enumList, char* mark) {
	while(enumList->next != NULL)
		enumList = enumList->next;
	enumList->next = newEnumDef(mark);
	
	return enumList->next; 
}

TypeList newTypeDef(char* name, ExpType type, int nestLevel, void* pAttr, int size) {
	TypeList new = (TypeList) malloc(sizeof(struct TypeListRec));
	new->name = name;
	new->type = type;
	new->nestLevel = nestLevel;
	new->pAttr = pAttr;
	new->size = size;
	new->next = NULL;

	return new;
}

TypeList insertTypeDef(TypeList typeList, char* name, ExpType type, int nestLevel, void* pAttr, int size) {
	while(typeList->next != NULL)
		typeList = typeList->next;
	typeList->next = newTypeDef(name, type, nestLevel, pAttr, size);

	return typeList->next;
}

RecordDef newDefinedRecord(TypeList ptr) {
	RecordDef new = (RecordDef) malloc(sizeof(struct RecordNodeRec));
	new->type = DEFINED;
	new->ptr.pDef = ptr;
	new->next = NULL;

	return new;
}

RecordDef newAnonyRecord(TypeList typeList) {
	RecordDef new = (RecordDef) malloc(sizeof(struct RecordNodeRec));
	new->type = ANONYMOUS;
	new->ptr.pAnony = (void*) typeList;
	new->next = NULL; 

	return new;
}

SimpleTypeList newSimpleTypeList(char* name, ExpType type, int isVar) {
	SimpleTypeList new = (SimpleTypeList) malloc(sizeof(struct SimpleTypeListRec));
	new->name = name;
	new->type = type;
	new->isVar = isVar;
	
	return new;
}

SimpleTypeList insertSimpleTypeList(SimpleTypeList simpleList, char* name, ExpType type, int isVar) {
	while(simpleList->next != NULL)
		simpleList = simpleList->next;
	simpleList->next = newSimpleTypeList(name, type, isVar);

	return simpleList->next;
}

int procListInsert(TreeNode* procHead) {

	char* name = procHead->attr.name;
	int nestLevel = currentNestLevel;
	int paraNestLevel = nestLevel + 1;
	int offset = 4;

	SimpleTypeList paraList;
	SimpleTypeList tmpList;
	TreeNode* tmpNode;

	if(procHead->child[0] == NULL)
		paraList = NULL;
	else {
	   	if(procHead->child[0]->kind == (DECL_VAR_PARA&0xF)) {
			paraList = newSimpleTypeList(procHead->child[0]->child[0]->attr.name, procHead->child[0]->child[1]->type, True);
		} else {
			paraList = newSimpleTypeList(procHead->child[0]->child[0]->attr.name, procHead->child[0]->child[1]->type, False);
		}

		varListInsert(procHead, procHead->child[0]->child[0]->attr.name, procHead->child[0]->child[1]->type, False, paraNestLevel, NULL, procHead->lineno, 0, offset);
		offset = offset + PARA_OFFSET_INC;

		tmpNode = procHead->child[0]->sibling;
		tmpList = paraList;
		while(tmpNode != NULL) {
			if(tmpNode->kind == (DECL_VAR_PARA&0xF))
				tmpList = insertSimpleTypeList(tmpList, tmpNode->child[0]->attr.name, tmpNode->child[1]->type, True);
			else
				tmpList = insertSimpleTypeList(tmpList, tmpNode->child[0]->attr.name, tmpNode->child[1]->type, False);

			varListInsert(tmpNode, tmpNode->child[0]->attr.name, tmpNode->child[1]->type, False, paraNestLevel, NULL, tmpNode->lineno, 0, offset);
			offset = offset + PARA_OFFSET_INC;
			
			tmpNode = tmpNode->sibling;
		}
	}
	
	int h = hash(name);
	ProcList l = procHashTable[h];
	ProcList tmp = l;
	while((tmp != NULL) && (strcmp(name, tmp->name)))
		tmp = tmp->next;
	if(tmp == NULL || (strcmp(name, tmp->name)==0 && nestLevel>tmp->nestLevel)) { /*process with same nestlevel not yet in the table, insert to the list head*/
		tmp = (ProcList) malloc(sizeof(struct ProcListRec));
		tmp->name = name;
		tmp->paraList = paraList;
		tmp->nestLevel = nestLevel;
		tmp->next = (l == NULL)? NULL:l;
		procHashTable[h] = tmp;
	}

	return offset;
}

int funcListInsert(TreeNode* funcHead) {

	char* name = funcHead->attr.name;
	int nestLevel = currentNestLevel;
	int paraNestLevel = nestLevel + 1;
	int offset = 4;

	ExpType retType = funcHead->child[1]->type;
	SimpleTypeList paraList;
	SimpleTypeList tmpList;
	TreeNode* tmpNode;


	if(funcHead->child[0] == NULL)
		paraList = NULL;
	else {
	   	if(funcHead->child[0]->kind == (DECL_VAR_PARA&0xF)) {
			paraList = newSimpleTypeList(funcHead->child[0]->child[0]->attr.name, funcHead->child[0]->child[1]->type, True);
		} else {
			paraList = newSimpleTypeList(funcHead->child[0]->child[0]->attr.name, funcHead->child[0]->child[1]->type, False);
		}
		varListInsert(funcHead->child[0]->child[0], funcHead->child[0]->child[0]->attr.name,funcHead->child[0]->child[1]->type, False, paraNestLevel, NULL, funcHead->lineno, 0, offset);
		offset = offset + PARA_OFFSET_INC;

		tmpNode = funcHead->child[0]->sibling;
		tmpList = paraList;
		while(tmpNode != NULL) {
			if(tmpNode->kind == (DECL_VAR_PARA&0xF))
				tmpList = insertSimpleTypeList(tmpList, tmpNode->child[0]->attr.name, tmpNode->child[1]->type, True);
			else
				tmpList = insertSimpleTypeList(tmpList, tmpNode->child[0]->attr.name, tmpNode->child[1]->type, False);

			varListInsert(tmpNode->child[0], tmpNode->child[0]->attr.name, tmpNode->child[1]->type, False, paraNestLevel, NULL, tmpNode->lineno, 0, offset);
			offset = offset + PARA_OFFSET_INC;
			
			tmpNode = tmpNode->sibling;
		}
	}	
	varListInsert(funcHead, funcHead->attr.name, retType, False, paraNestLevel, NULL, funcHead->lineno, 0, offset);
	offset = offset + PARA_OFFSET_INC;

	int h = hash(name);
	FuncList l = funcHashTable[h];
	FuncList tmp = l;
	while((tmp != NULL) && (strcmp(name, tmp->name)))
		tmp = tmp->next;
	if(tmp == NULL || (strcmp(name, tmp->name)==0 && nestLevel>tmp->nestLevel)) { /*process with same nestlevel not yet in the table, insert to the list head*/
		tmp = (FuncList) malloc(sizeof(struct FuncListRec));
		tmp->name = name;
		tmp->paraList = paraList;
		tmp->retType = retType;
		tmp->nestLevel = nestLevel;
		tmp->next = (l == NULL)? NULL:l;
		funcHashTable[h] = tmp;
	}
	return offset;
}

void typeListAliaseInsert(char* name, char* aliase) {
	int h = hash(name);
	TypeList l = typeHashTable[h];
	while((l != NULL) && (strcmp(name, l->name)))
		l = l->next;
	if(l != NULL) {
		AliaseList t = l->aliaseSet;
		while(t->next != NULL)
			t = t->next;
		t->next = (AliaseList) malloc(sizeof(struct AliaseListRec));
		t->next->aliase = aliase;
		t->next->next = NULL;
	}
}

void typeListInsert(char* name, ExpType type, int nestLevel, void* pAttr, int size) {
	int h = hash(name);
	TypeList l = typeHashTable[h];
	TypeList tmp = l;
	while((tmp != NULL) && (strcmp(name, tmp->name)))
		tmp = tmp->next;
	if(tmp == NULL || (strcmp(name, tmp->name)==0 && nestLevel>tmp->nestLevel)) { /*process with same nestlevel not yet in the table, insert to the list head*/
		tmp = (TypeList) malloc(sizeof(struct TypeListRec));
		tmp->name = name;
		tmp->aliaseSet = NULL;
		tmp->type = type;
		tmp->nestLevel = nestLevel;
		tmp->pAttr = pAttr;
		tmp->size = size;
		tmp->next = (l == NULL)? NULL:l;
		typeHashTable[h] = tmp;
	}

}

void varListInsert(TreeNode* t, char* name, ExpType type, int isConst, int nestLevel, void* pAttr, int lineno, int baseLoc, int offset) { 
	int h = hash(name);
	VariableList l = variableHashTable[h];
	VariableList tmp = l;
	while((tmp != NULL) && (strcmp(name, tmp->name)))
			tmp = tmp->next;
	
	if(tmp == NULL || (strcmp(name, tmp->name)==0 && nestLevel>tmp->nestLevel)) { 
		tmp = (VariableList) malloc(sizeof(struct VariableListRec));
		tmp->name = name;
		tmp->type = type;
		tmp->isConst = isConst; 
		tmp->nestLevel = nestLevel;
		tmp->pAttr = pAttr;
		tmp->lines = (LineList) malloc(sizeof(struct LineListRec));
		tmp->lines->lineno = lineno;
		tmp->lines->next = NULL;
		tmp->memloc.baseLoc = baseLoc;
		tmp->memloc.offset = offset;
		tmp->next = (l == NULL)? NULL:l;
		variableHashTable[h] = tmp;
	} else { 
		LineList t = tmp->lines;
		while(t->next != NULL)
			t = t->next;
		t->next = (LineList) malloc(sizeof(struct LineListRec));
		t->next->lineno = lineno;
		t->next->next = NULL;
	}
}

VariableList varListLookup(char* name) {
	int h = hash(name);
	VariableList l = variableHashTable[h];
	while((l != NULL) && (strcmp(name, l->name)))
		l = l->next;
	if(l == NULL)
		return NULL;
	else {
		l->memloc.baseLoc = currentNestLevel - l->nestLevel; 
		return l;
	}
}

FuncList funcListLookup(char* name) {
	int h = hash(name);
	FuncList l = funcHashTable[h];
	while((l != NULL) && (strcmp(name, l->name)))
		l = l->next;
	if(l == NULL)
		return NULL;
	else  
		return l;
}

ProcList procListLookup(char* name) {
	int h = hash(name);
	ProcList l = procHashTable[h];
	while((l != NULL) && (strcmp(name, l->name)))
		l = l->next;
	if(l == NULL)
		return NULL;
	else
		return l;
}

TypeList typeListLookup(char* name) {
	int h = hash(name);
	TypeList l = typeHashTable[h];
	while((l != NULL) && (strcmp(name, l->name)))
		l = l->next;
	if(l == NULL)
		return NULL;
	else
		return l;
}

LookupRet arrayLookup(char* a, int i) {
	int lower, upper, size;
	LookupRet ret;
	ret.totalOff = ERROR_RETURN;
	ret.jumpLevel = ERROR_RETURN;
	ret.type = EXPTYPE_VOID;
	VariableList l = varListLookup(a);
	if(l->type == EXPTYPE_ARRAY && l->pAttr != NULL) {
		lower = ((ArrayDef)(l->pAttr))->subBound->LowerBound.i;
		upper = ((ArrayDef)(l->pAttr))->subBound->UpperBound.i;
		if(i>=lower && i<=upper) {
			ret.totalOff = l->memloc.offset+OFFSET_INC*(i-lower);
			ret.jumpLevel = currentNestLevel - l->nestLevel;
			ret.type = l->type;
		} 
	}
	return ret;
}

LookupRet recordLookup(char* rec, char* a) {
	VariableList l = varListLookup(rec);
	TypeList plist;
	int size = 0;
	LookupRet ret;
	ret.totalOff = ERROR_RETURN;
	ret.jumpLevel = ERROR_RETURN;
	ret.type = EXPTYPE_VOID;
	if(l->type == EXPTYPE_RECORD && l->pAttr != NULL) {
		if(((RecordDef)(l->pAttr))->type == ANONYMOUS) {
			plist = ((RecordDef)(l->pAttr))->ptr.pAnony; 
		} else {
			plist = ((RecordDef)(l->pAttr))->ptr.pDef; 
		}
		while(plist != NULL && strcmp(plist->name, a)) {
			size += 1;
			plist = plist->next;
		}
		if(plist != NULL) {
			ret.totalOff = size*OFFSET_INC + l->memloc.offset;
			ret.jumpLevel = currentNestLevel - l->nestLevel;
			ret.type = plist->type;
		}
	}
	return ret;	
}

void initScope() {
	currentNestLevel = -1;
	int i;
	for(i=0; i<SIZE; i++) {
		variableHashTable[i] = NULL;
		typeHashTable[i] = NULL;
		procHashTable[i] = NULL;
		funcHashTable[i] = NULL;
	}
}

int enterNewScope(TreeNode* t) {
	currentNestLevel += 1;
	totalOffset[currentNestLevel] = buildSymtab(t);
	return 	totalOffset[currentNestLevel];
}

int leaveScope() {
	int tmp = currentNestLevel;
	int retValue = totalOffset[currentNestLevel];
	void* ptr1, *ptr2, *ptr3;
	currentNestLevel -= 1;
	int i;
	for(i=0; i<SIZE; i++) {
		VariableList vl = variableHashTable[i];
		TypeList tl = typeHashTable[i];
		FuncList fl = funcHashTable[i];
		ProcList pl = procHashTable[i];

		while(vl != NULL && vl->nestLevel >= tmp) {
			ptr1 = (void*)vl;
			vl = vl->next;
			ptr2 = (void*)(((VariableList)ptr1)->lines);
			while((LineList)ptr2 != NULL) {
				ptr3 = (void*)(((LineList)ptr2)->next);
				free((LineList)ptr2);
				ptr2 = ptr3;
			}
			free((VariableList)ptr1);
		}
		variableHashTable[i] = vl;

		while(tl != NULL && tl->nestLevel >= tmp) {
			ptr1 = (void*)tl;
			tl = tl->next;
			ptr2 = (void*)(((TypeList)ptr1)->aliaseSet);
			while((AliaseList)ptr2 != NULL) {
				ptr3 = (void*)(((AliaseList)ptr2)->next);
				free((AliaseList)ptr2);
				ptr2 = ptr3;
			}
			free((VariableList)ptr1);
		}
		typeHashTable[i] = tl;
	}
	return retValue;
}

void printSymTab(FILE* listing) {
	int i;
	fprintf(listing, "Variable Name	| Level | Line Number\n");
	fprintf(listing, ":\n");
	for(i=0; i<SIZE; i++) {
		if(variableHashTable[i] != NULL) {
			VariableList l = variableHashTable[i];
			while(l != NULL) {
				LineList t = l->lines;
				fprintf(listing, "%-14s ", l->name);
				fprintf(listing, "%-8d", l->nestLevel);
				while(t != NULL) {
					fprintf(listing, "%4d ", t->lineno);
					t = t->next;
				}
				fprintf(listing, "\n");
				l = l->next;
			}
		}
	}

	fprintf(listing, "Function Name	| Level | Return Value Type | Parameter\n");
	fprintf(listing, ": \n");
	for(i=0; i<SIZE; i++) {
		if(funcHashTable[i] != NULL) {
			FuncList l = funcHashTable[i];
			while(l != NULL) {
				SimpleTypeList t = l->paraList;
				fprintf(listing, "%-14s ", l->name);
				fprintf(listing, "%-8d", l->nestLevel);
				fprintf(listing, "%-8d ", l->retType);
				while(t != NULL) {
					fprintf(listing, "%-14s ", t->name);
					t = t->next;
				}
				fprintf(listing, "\n");
				l = l->next;
			}
		}
	}	
	
}
