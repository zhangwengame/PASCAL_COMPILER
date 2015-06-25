#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef YYPARSER
#include "y.tab.h"
#define ENDFILE 0
#endif

#ifndef False
#define False 0
#endif

#ifndef True
#define True 1
#endif

#define MAXRESERVED 8
typedef int TokenType;
extern FILE* source;
extern FILE* listing;
//extern FILE* code;
extern int TraceAnalyze;
extern TraceScan;
extern int lineno;
extern int DEBUG_MODE;
extern int COMPILE_ERROR;
extern int ERROR_COUNT;
/*
typedef enum{
    // book-keeping
    ENDFILE,ERROR,
    //reserved
    TOKEN_PROGRAM,
    //
    TOKEN_CONST,TOKEN_TYPE,TOKEN_VAR,
    //reserved
    IF,THEN,
    //special symbol
    EQUAL,PLUS,OR,LB,RB,SEMI,SPLIT,DOT,LP,RP,COMMA,COLON,
    //type
    INT,BOOL,TRUE,FALSE,ARRAY,OF,
    //multicharacter tokens
    ID,TOKEN_INT,TOKEN_REAL,TOKEN_CHAR,TOKEN_STRING
}TokenType;
*/

#define NODE_STATEMENT 0x01
#define NODE_EXPRESSION 0x02
#define NODE_DECLARE 0x03
#define NODE_TYPE 0x04
#define STMT_LABEL 0x11
#define STMT_ASSIGN 0x12
#define STMT_GOTO 0x13
#define STMT_IF 0x14
#define STMT_REPEAT 0x15
#define STMT_WHILE 0x16
#define STMT_FOR 0x17
#define STMT_CASE 0x18
#define STMT_PROC_ID 0x19
#define STMT_PROC_SYS 0x1a
#define EXP_ID 0x21
#define EXP_CONST 0x22
#define EXP_OP 0x23
#define EXP_CASE 0x24
#define EXP_FUNC_ID 0x25
#define EXP_FUNC_SYS 0x26
#define DECL_ROUTINEHEAD 0x31
#define DECL_FUNCTION 0x32
#define DECL_FUNCTIONHEAD 0x33
#define DECL_PROCEDURE 0x34
#define DECL_PROCEDUREHEAD 0x35
#define DECL_CONST 0x36
#define DECL_VAR 0x37
#define DECL_TYPE 0x38
#define DECL_VAR_PARA 0x39
#define DECL_VAL_PARA 0x3a
#define TYPE_SIMPLE_SYS 0x41
#define TYPE_SIMPLE_ID 0x42
#define TYPE_SIMPLE_ENUM 0x43
#define TYPE_SIMPLE_LIMIT 0x44
#define TYPE_ARRAY 0x45
#define TYPE_RECORD 0x46

// Defination of error type
#define ERROR_TYPE_MISMATCH 1
#define ERROR_VAR_MISS 2
#define ERROR_VAR_NOTARRAY 3
#define ERROR_VAR_MODIFYCONST 4
#define ERROR_VAR_REDEC 5
#define ERROR_FUNC_REDEC 6
/*
#define EXPTYPE_VOID 0x51
#define EXPTYPE_INT 0x52
#define EXPTYPE_REAL 0x53
#define EXPTYPE_CHAR 0x54
#define EXPTYPE_STRING 0x55
#define EXPTYPE_BOOL 0x56
#define EXPTYPE_ARRAY 0x57
#define EXPTYPE_RECORD 0x58
#define EXPTYPE_SIMPLE_ID 0x59
#define EXPTYPE_SIMPLE_ENUM 0x5a
#define EXPTYPE_SIMPLE_LIMIT 0x5b
*/
/*typedef enum{
    NODE_STATEMENT, NODE_EXPRESSION, NODE_DECLARE, NODE_TYPE
}NodeKind;

typedef enum{
    STMT_LABEL,
    STMT_ASSIGN,STMT_GOTO,STMT_IF,STMT_REPEAT,STMT_WHILE,STMT_FOR,STMT_CASE,
    STMT_PROC_ID,STMT_PROC_SYS
}StmtKind;

typedef enum{
    EXP_ID,
    EXP_CONST,
    EXP_OP,EXP_CASE,EXP_FUNC_ID,EXP_FUNC_SYS
}ExpKind;

typedef enum{
    DECL_ROUTINEHEAD,
    DECL_FUNCTION,DECL_FUNCTIONHEAD,
    DECL_PROCEDURE,DECL_PROCEDUREHEAD,
    DECL_CONST,DECL_VAR,DECL_TYPE,
    DECL_VAR_PARA,DECL_VAL_PARA
}DeclKind;

typedef enum{
    TYPE_SIMPLE_SYS,TYPE_SIMPLE_ID, TYPE_SIMPLE_ENUM, TYPE_SIMPLE_LIMIT,
    TYPE_ARRAY, TYPE_RECORD
}TypeKind;
*/
//
typedef enum{
    EXPTYPE_VOID,EXPTYPE_INT,EXPTYPE_REAL,
    EXPTYPE_CHAR,EXPTYPE_STRING,EXPTYPE_BOOL,
    EXPTYPE_ARRAY,EXPTYPE_RECORD,
    EXPTYPE_SIMPLE_ID,EXPTYPE_SIMPLE_ENUM,EXPTYPE_SIMPLE_LIMIT
}ExpType;

#define MAXCHILDREN 4

typedef struct treeNode{
    struct treeNode * child[MAXCHILDREN];
    struct treeNode * sibling;
    int nodekind;
    int lineno;
    int kind;
    union{
        TokenType op;
        char * name;
        int val;
        char char_val;
        char * string_val;
        double real_val;
    }attr;
    ExpType type;
    ExpType RuningType;
    int ERROR_STATE;
}TreeNode;

#endif
