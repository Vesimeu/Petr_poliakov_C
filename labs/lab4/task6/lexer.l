%{
#include "bison.tab.h" // Предполагаем, что Bison генерирует файл с именем mylang.tab.h
%}

%%

"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
[0-9]+      { yylval.num = atoi(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return IDENTIFIER; }

[ \t\n]+    { /* Игнорируем пробелы и новые строки */ }
.           { return *yytext; } // Возвращаем любой другой символ как есть

%%

int yywrap() {
    return 1;
}
