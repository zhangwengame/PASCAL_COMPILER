#a.out : tiny.l tiny.y global.h scan.h parse.h util.c main.c
a.out : tiny.l tiny.y global.h scan.h parse.h CG.h analyze.h symtab.h util.c main.c
	flex tiny.l
	yacc -d tiny.y
	gcc util.c lex.yy.c y.tab.c main.c CG.c analyze.c symtab.c -ll -o compiler
#	gcc util.c lex.yy.c main.c -lfl -o a.out
clean:
	rm y.tab.c
	rm y.tab.h
	rm lex.yy.c
	rm compiler
