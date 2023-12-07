#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Variable {
    char* name;
    char* value;
};

extern int yylex();
extern FILE* yyin;
extern void yyerror(const char* s);
