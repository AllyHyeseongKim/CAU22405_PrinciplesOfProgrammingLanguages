all: tiny

tiny.tab.c tiny.tab.h:	tiny.y
	bison -d tiny.y

lex.yy.c: tiny.l tiny.tab.h
	flex tiny.l

tiny: lex.yy.c tiny.tab.c tiny.tab.h
	gcc -o tiny tiny.tab.c lex.yy.c

clean:
	rm tiny.tab.c lex.yy.c tiny.tab.h