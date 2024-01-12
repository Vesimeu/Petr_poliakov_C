%{
#include "MySmartHome.h"
#include "MySmartHome.tab.h"


%}


%%
\"[^"]*\"          { yylval.strval = strdup(yytext); return STRING; }
[0-9]+                 { yylval.intval = atoi(yytext); return INTEGER; }
"create "       { yylval.strval = strdup(yytext); return CREATE; } 
"light_ON"        { return LIGHT_ON; }  //return ACTIVATE_LIGHT
"light_OFF"       { return LIGHT_OFF; }  //return DEACTIVATE_LIGHT
"blinds_ON"       { return BLINDS_ON; }  // return OPEN_BLINDS;
"blinds_OFF"      { return BLINDS_OFF; }  //return CLOSE_BLINDS;
"information"               { return INFO; } //return INFO;
"aircon"      { return AIRCON; } //return ADJUST_AIRCON;
"sound"      { return SOUND ; } //return SET_AUDIO_LEVEL ;
"print"                 { return PRINT; } //return PRINT;
"Home:"                 { return START; } 
"set"               { return SET; } //HOME
"("      { return LPAREN; }
")"         { return RPAREN; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
"="        {  yylval.strval = strdup(yytext); return EQUAL; }
"endl;"                   { return ENDL; }
[a-zA-Z_][a-zA-Z0-9_]*    { yylval.strval = strdup(yytext); return ID; }

[ \t\n]                ;

%%

int yywrap() {
    return 1;
}