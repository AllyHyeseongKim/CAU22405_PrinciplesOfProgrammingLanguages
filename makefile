all: tiny

tiny.tab.c tiny.tab.h:	tiny.y
	bison -d tiny.y --report=all

lex.yy.c: tiny.l tiny.tab.h
	flex tiny.l

tiny: lex.yy.c tiny.tab.c tiny.tab.h astexec.h astgen.h
	gcc -o tiny tiny.tab.c lex.yy.c astexec.c astgen.c

clean:
	rm tiny tiny.tab.c lex.yy.c tiny.tab.h tiny.output