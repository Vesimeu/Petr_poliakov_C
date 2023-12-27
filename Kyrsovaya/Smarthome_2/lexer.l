%{
#include "func.h"
#include "SmartHome.tab.h"


%}


%%
\"[^"]*\"          { yylval.strval = strdup(yytext); return STRING; }
[0-9]+                 { yylval.intval = atoi(yytext); return INTEGER; }
"add_room"        { yylval.strval = strdup(yytext); return ADD_OBJ; }
"light_on"        { return LIGHT_ON; }  // Добавляем токен для команды включения света
"light_off"       { return LIGHT_OFF; }  // Добавляем токен для команды выключения света
"blinds_on"       { return BLINDS_ON; }  // Добавляем токен для команды включения жалюзи
"blinds_off"      { return BLINDS_OFF; }  // Добавляем токен для команды выключения жалюзи
"info"               { return INFO; } 
"set_conditioner"      { return SET_CONDITIONER; }
"set_volume"      { return SET_VOLUME ; } //Теперь у нас есть звук
"print"                 { return PRINT; }
"("      { return LPAREN; }
")"         { return RPAREN; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
">"          { yylval.strval = strdup(yytext); return GREATER; }
"<"         { yylval.strval = strdup(yytext); return LESS; }
"="        {  yylval.strval = strdup(yytext); return EQUAL; }
"end"                   { return END; }
[a-zA-Z_][a-zA-Z0-9_]*    { yylval.strval = strdup(yytext); return ID; }

[ \t\n]                ;
"->"               { return HAVE; }

%%

int yywrap() {
    return 1;
}