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
int TraceScan = True; 
int lineno=0;

int main(int argc, char const *argv[]){
// ningning
	// printf("%d\n", argc);
	// printf("%s\n", argv[0]);
	// printf("%s\n", argv[1]);
	if (argc == 2){
		// filename = argv[0];
		strcpy(filename, argv[1]);
	}	
    source = fopen(filename,"r");
    listing = stdout;
    TreeNode * syntaxTree;
 //   while(getToken()!=ENDFILE);
    syntaxTree = parse();
    printTree(syntaxTree);  

// caihua
	CG_main(syntaxTree, "out.s");

    return 0;

}
