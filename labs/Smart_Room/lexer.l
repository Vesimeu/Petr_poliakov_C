%{
#include "smart_objects.h"
#include "smarthome.tab.h"

struct SmartObject;

%}

struct SmartObject;

%%
\"[^"]*\"          { yylval.strval = strdup(yytext); return STRING; }
[0-9]+                 { yylval.intval = atoi(yytext); return INTEGER; }
"create_object"        { yylval.strval = strdup(yytext); return CREATE_OBJECT; }
"if"                   { return IF; }
"else"                 { return ELSE; }
"turn_on_light"        { return TURN_ON_LIGHT; }  // Добавляем токен для команды включения света
"turn_off_light"       { return TURN_OFF_LIGHT; }  // Добавляем токен для команды выключения света
"turn_on_blinds"       { return TURN_ON_BLINDS; }  // Добавляем токен для команды включения жалюзи
"turn_off_blinds"      { return TURN_OFF_BLINDS; }  // Добавляем токен для команды выключения жалюзи
"status"               { return STATUS; } //ADD STATUS
"set_temperature"      { return SET_TEMPERATURE; }
"set_volume"           { return SET_VOLUME; }
"grant_access"         { return GRANT_ACCESS; }
"current_time"         { return CURRENT_TIME; }
"sunrise_time"         { return SUNRISE_TIME; }
"sunset_time"          { return SUNSET_TIME; }
"print"                 { return PRINT; }
"("      { return LPAREN; }
")"         { return RPAREN; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
">"          { yylval.strval = strdup(yytext); return GREATER; }
"<"         { yylval.strval = strdup(yytext); return LESS; }
"=="        {  yylval.strval = strdup(yytext); return EQUAL; }
";"                   { return SEMICOLON; }
[a-zA-Z_][a-zA-Z0-9_]*    { yylval.strval = strdup(yytext); return ID; }

[ \t\n]                ;
.               { return DOT; }

%%

int yywrap() {
    return 1;
}