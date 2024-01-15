%{
#include "updated_func.h"
#include "updated_SmartHome.tab.h"


%}


%%
\"[^"]*\"          { yylval.strval = strdup(yytext); return STRING; }
[0-9]+                 { yylval.intval = atoi(yytext); return INTEGER; }
"create_room "       { yylval.strval = strdup(yytext); return ADD_ROOM; }
"activate_light"        { return ACTIVATE_LIGHT; }  
"deactivate_light"       { return DEACTIVATE_LIGHT; }  
"open_blinds"       { return OPEN_BLINDS; }  
"close_blinds"      { return CLOSE_BLINDS; }  
"info"               { return INFO; } 
"adjust_aircon"      { return ADJUST_AIRCON; }
"set_audio_level"      { return SET_AUDIO_LEVEL ; } 
"print"                 { return PRINT; }
"("      { return LPAREN; }
")"         { return RPAREN; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
"="        {  yylval.strval = strdup(yytext); return EQUAL; }
";"                   { return END; }
[a-zA-Z_][a-zA-Z0-9_]*    { yylval.strval = strdup(yytext); return ID; }

[ \t\n]                ;
">"               { return HAVE; }

%%

int yywrap() {
    return 1;
}