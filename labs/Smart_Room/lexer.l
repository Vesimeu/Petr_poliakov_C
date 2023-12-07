%{
#include "smarthome.tab.h"
%}

%%
[0-9]+                 { yylval.intval = atoi(yytext); return INTEGER; }
"create_object"        { return CREATE_OBJECT; }
"if"                   { return IF; }
"else"                 { return ELSE; }
"turn_on"              { return TURN_ON; }
"turn_off"             { return TURN_OFF; }
"set_temperature"      { return SET_TEMPERATURE; }
"set_volume"           { return SET_VOLUME; }
"grant_access"         { return GRANT_ACCESS; }
"current_time"         { return CURRENT_TIME; }
"sunrise_time"         { return SUNRISE_TIME; }
"sunset_time"          { return SUNSET_TIME; }
[ \t\n]                ; // пропускаем пробелы и символы новой строки
.                      { return yytext[0]; } // все остальные символы возвращаем как есть

%%

int yywrap(void) {
    return 1;
}
