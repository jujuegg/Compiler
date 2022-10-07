all:	clean y.tab.c lex.yy.c
	gcc lex.yy.c y.tab.c -ly -lfl -o hw2

y.tab.c:
	bison -y -d B083040019.y

lex.yy.c:
	flex B083040019.l

clean:
	rm -f hw2 lex.yy.c y.tab.c y.tab.h
