%{
#include "head_file.h"
#include "control.tab.h"


%}


%%
\"[^"]*\"          { yylval.strval = strdup(yytext); return STRING; }
[0-9]+                 { yylval.intval = atoi(yytext); return INTEGER; }
"new_room"       { yylval.strval = strdup(yytext); return ADD_ROOM; }
"set_light_mode"          { return SET_LIGHT_MODE; }
"open_blinds"       { return OPEN_BLINDS; }  
"close_blinds"      { return CLOSE_BLINDS; }  
"info"               { return INFO; } 
"adjust_aircon"      { return ADJUST_AIRCON; }
"set_audio_level"      { return SET_AUDIO_LEVEL ; } 
"print"                 { return PRINT; }
":"               { return START; }
";"                   { return END; }
"("      { return LPAREN; }
")"         { return RPAREN; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
"="        {  yylval.strval = strdup(yytext); return EQUAL; }
[a-zA-Z_][a-zA-Z0-9_]*    { yylval.strval = strdup(yytext); return ID; }

[ \t\n]                ;

%%

int yywrap() {
    return 1;
}