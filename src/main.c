#include "global.h"
#include "util.h"
#include "scan.h"
#include "parse.h"
#include "CG.h"
#include "symtab.h"
#include "analyze.h"
char filename[30] = "test.pas";
FILE * source ;
FILE * listing ;
int TraceAnalyze = False; 
int TraceScan= False;
int lineno=0;
int DEBUG_MODE=0;
int COMPILE_ERROR=0;
int ERROR_COUNT=0;

int main(int argc, char const *argv[]){
// ningning
	// printf("%d\n", argc);
	// printf("%s\n", argv[0]);
	// printf("%s\n", argv[1]);
	if (argc == 2){
		// filename = argv[0];
		strcpy(filename, argv[1]);
	}	
	else if (argc==3){
		if (!strcmp("-d",argv[2])){
			DEBUG_MODE=1;
			TraceAnalyze=True;
			TraceScan=True;
		}
	}
    source = fopen(filename,"r");
    TreeNode * syntaxTree;
    listing = stdout;
    syntaxTree = parse();
	if (DEBUG_MODE){
		printTree(syntaxTree); 
	}
	CG_main(syntaxTree, "out.s");
	if (COMPILE_ERROR){
		fprintf(listing, "%d errors generated.\n",ERROR_COUNT);
		return -1;
	}
 //   while(getToken()!=ENDFILE);
// caihua
    return 0;
}
