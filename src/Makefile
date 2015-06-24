#a.out : tiny.l tiny.y global.h scan.h parse.h util.c main.c


compiler: tiny.l tiny.y global.h scan.h parse.h CG.h analyze.h symtab.h util.c main.c
	flex tiny.l
	yacc -d tiny.y
	gcc util.c lex.yy.c y.tab.c main.c CG.c analyze.c symtab.c -ll -o compiler
#	gcc util.c lex.yy.c main.c -lfl -o a.out

test: compiler
	./compiler test.pas	
	gcc -o test.o out.s
	./test.o || /bin/true

clean:
	rm y.tab.c
	rm y.tab.h
	rm lex.yy.c
	rm compiler
	rm test.o
	rm out.s
	rm data_part.asm
	rm code_part.asm
