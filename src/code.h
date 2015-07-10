#ifndef _CODE_H_
#define _CODE_H_

#include <stdio.h>
#include "global.h"
#include "y.tab.h"
#include "analyze.h"
#include "symtab.h"



char* GetLabel();
char* GetSysLabel(int val);
char* GetDataLabel();

void PopParam(TreeNode* pnode,SimpleTypeList judge_var);
void PushParam(TreeNode* pnode);

void HandleAssignStmt(TreeNode* pnode);
void HandleCaseExp(TreeNode* pnode);
void HandleCaseStmt(TreeNode* pnode);
void HandleConstExp(TreeNode* pnode);
void HandleExpId(TreeNode* pnode);
void HandleExpOp(TreeNode* pnode);
void HandleForStmt(TreeNode* pnode);
void HandleFuncExc(TreeNode* pnode);
void HandleGotoStmt(TreeNode* pnode);
void HandleIfStmt(TreeNode* pnode);
void HandleInStmt(TreeNode* pnode);
void HandleLabelStmt(TreeNode* pnode);
void HandleNodeExp(TreeNode* pnode);
void HandleOutStmt(TreeNode* pnode);
void HandleProcExc(TreeNode* pnode);
void HandleRepeatStmt(TreeNode* pnode);
void HandleWhileStmt(TreeNode* pnode);

void GenCode(TreeNode* pnode);

#endif /* _CODE_H_ */
