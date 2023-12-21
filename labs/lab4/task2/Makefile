all: expr

expr: lex.yy.c y.tab.c
    gcc -o expr y.tab.c lex.yy.c -lfl

lex.yy.c: lexer.l
    flex lexer.l

y.tab.c: parser.y
    bison -d parser.y

clean:
    rm -f expr lex.yy.c y.tab.c y.tab.h

