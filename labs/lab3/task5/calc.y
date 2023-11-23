%{
#include <stdio.h>
#include <stdlib.h>

struct ast {
  int nodetype;
  struct ast *l;
  struct ast *r;
};

struct numval {
  int nodetype;
  double number;
};

struct ast *newast(int nodetype, struct ast *l, struct ast *r);
struct ast *newnum(double d);
double eval(struct ast *a);
void treefree(struct ast *a);

int yylex(void);
void yyerror(const char *s);

%}

%union {
  struct ast *a;
  double d;
}

%token <d> NUMBER
%token ADD SUB
%left '+' '-'
%left '*' '/'
%type <a> emxpr term factor

%%

calc: expr { printf("Result: %f\n", eval($1)); treefree($1); }

expr: expr ADD term   { $$ = newast('+', $1, $3); }
    | expr SUB term   { $$ = newast('-', $1, $3); }
    | term            { $$ = $1; }

term: term '*' factor { $$ = newast('*', $1, $3); }
    | term '/' factor { $$ = newast('/', $1, $3); }
    | factor          { $$ = $1; }

factor: NUMBER       { $$ = newnum($1); }
      | '(' expr ')'  { $$ = $2; }
      ;

%%

struct ast *newast(int nodetype, struct ast *l, struct ast *r) {
  struct ast *a = malloc(sizeof(struct ast));
  if (!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = nodetype;
  a->l = l;
  a->r = r;
  return a;
}

struct ast *newnum(double d) {
  struct numval *a = malloc(sizeof(struct numval));
  if (!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = NUMBER;
  a->number = d;
  return (struct ast *)a;
}

void treefree(struct ast *a) {
  switch (a->nodetype) {
    case NUMBER:
      free((struct numval *)a);
      break;
    case '+':
    case '-':
    case '*':
    case '/':
      treefree(a->l);
      treefree(a->r);
      free(a);
      break;
    default:
      printf("Internal error: free bad node %d\n", a->nodetype);
  }
}

double eval(struct ast *a) {
  double v;

  switch (a->nodetype) {
    case NUMBER:
      v = ((struct numval *)a)->number;
      break;
    case '+':
      v = eval(a->l) + eval(a->r);
      break;
    case '-':
      v = eval(a->l) - eval(a->r);
      break;
    case '*':
      v = eval(a->l) * eval(a->r);
      break;
    case '/':
      v = eval(a->l) / eval(a->r);
      break;
    default:
      printf("Internal error: bad node %d\n", a->nodetype);
  }

  return v;
}

int main(void) {
  yyparse();
  return 0;
}

void yyerror(const char *s) {
  fprintf(stderr, "error: %s\n", s);
}
