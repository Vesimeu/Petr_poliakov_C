%{
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int x=0; int y=0; int k=0;
float t=0; int l=0;
void yyerror(const char *str)
{
fprintf(stderr, "error: %s\n", str);
}
int yylex();
int yywrap()
{
return 1;
}
extern FILE *yyin, *yyout;
%}

%token LEFT RIGHT GO BACK
%token PROV TIME MV LAMPN LAMPF
%token NUMBER X Y V PER

%%
comm:
| comm com;
com:
com_l
| com_r
| com_v
| com_n
| say_t
| chek
| make_vol
| lampon
| lampoff
| vvod_x
| vvod_y
| prm;
;
com_l: LEFT NUMBER {
fprintf(yyout,"Робот совершил поворот налево %d раз\n", $2);
x=x-$2; k=k+$2;
}
| LEFT PER {
fprintf(yyout,"Робот совершил поворот налево %d раз\n", $2);
x=x-$2; k=k+$2;
};
com_r: RIGHT NUMBER {
fprintf(yyout,"Робот совершил поворот направо %d раз\n", $2);
x=x+$2; k=k+1;
}
| RIGHT PER {
fprintf(yyout,"Робот совершил поворот направо %d раз\n", $2);
x=x+$2; k=k+$2;
};
com_v: GO NUMBER {
fprintf(yyout,"Робот передвигается прямо на %d клеток\n", $2);
y=y+$2;k=k+$2;
}
| GO PER {
fprintf(yyout,"Робот передвигается прямо на %d клеток\n", $2);
y=y+$2; k=k+$2;
};
com_n: BACK NUMBER {
fprintf(yyout,"Робот передвигается назад на %d клеток\n", $2);
y=y-$2; k=k+$2;
}
| BACK PER {
fprintf(yyout,"Робот передвигается назад на %d клеток\n", $2);
y=y-$2; k=k+$2;
};
say_t: TIME {
long int ttime;
ttime=time(NULL);
fprintf(yyout,"Time and Data: %s\n", ctime(&ttime));
k=k+1;
};
chek: PROV {
fprintf(yyout,"Запрашиваемая координата x = %d\n", x);
fprintf(yyout,"Запрашиваемая координата y = %d\n",y);
if ((x<0) || (y<0) || (x>20) || (y>20)) { fprintf(yyout,"Робот покинул поле\n"); return 0;}
if ((x==10)&(y==10)) { fprintf(yyout,"Робот достиг центра поля \n"); l=1;}
k=k+1;
};
lampon: LAMPN {
if (l=1) {fprintf(yyout,"Загорелся индикатор \n");k=k+1;}
else {fprintf(yyout,"*Ничего не произошло* \n");}
};
lampoff: LAMPF {
if (l=1) {fprintf(yyout,"Индикатор потух \n");k=k+1;}
else {fprintf(yyout,"*Ничего не произошло* \n");}
};
make_vol: MV NUMBER {
fprintf(yyout,"Громкость %d единиц.\n", $2);
k=k+1;
}
| V NUMBER {
fprintf(yyout,"Громкость %d единиц.\n", $2);
k=k+1;
}
| MV PER {
fprintf(yyout,"Громкость %d единиц.\n", $2);
k=k+1;
};
vvod_x: X NUMBER { int d=x;
x=$2;
if (d>x) {fprintf(yyout,"Робот совешил %d поворотов налево\n",d-x);k=k+(d-x);}
if (d<x) {fprintf(yyout,"Робот совешил %d поворотов направо\n",x-d);k=k+(x-d);}
};
vvod_y: Y NUMBER { int d=y;
y=$2;
if (d>y) {fprintf(yyout,"Робот перемещался назад %d раз\n",d-y);k=k+(d-y);}
if (d<y) {fprintf(yyout,"Робот перемещался вперед %d раз\n",y-d);k=k+(y-d);}
};
prm: PER {}
| PER NUMBER {
$1=$2;
};
%%
int main() {
yyin = fopen("TaskForRobot.txt", "r");
yyout = fopen("DoneTask.txt", "w");
yyparse();
fprintf(yyout,"Всего робот совершил %d действий\n", k);
}
