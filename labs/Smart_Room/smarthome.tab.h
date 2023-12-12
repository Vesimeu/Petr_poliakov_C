/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SMARTHOME_TAB_H_INCLUDED
# define YY_YY_SMARTHOME_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGER = 258,                 /* INTEGER  */
    STRING = 259,                  /* STRING  */
    CREATE_OBJECT = 260,           /* CREATE_OBJECT  */
    IF = 261,                      /* IF  */
    ELSE = 262,                    /* ELSE  */
    TURN_ON = 263,                 /* TURN_ON  */
    TURN_OFF = 264,                /* TURN_OFF  */
    SET_TEMPERATURE = 265,         /* SET_TEMPERATURE  */
    SET_VOLUME = 266,              /* SET_VOLUME  */
    GRANT_ACCESS = 267,            /* GRANT_ACCESS  */
    CURRENT_TIME = 268,            /* CURRENT_TIME  */
    SUNRISE_TIME = 269,            /* SUNRISE_TIME  */
    SUNSET_TIME = 270,             /* SUNSET_TIME  */
    ID = 271,                      /* ID  */
    COLON = 272,                   /* COLON  */
    SEMICOLON = 273,               /* SEMICOLON  */
    LPAREN = 274,                  /* LPAREN  */
    RPAREN = 275,                  /* RPAREN  */
    LBRACE = 276,                  /* LBRACE  */
    RBRACE = 277,                  /* RBRACE  */
    EQUAL = 278,                   /* EQUAL  */
    GREATER = 279,                 /* GREATER  */
    LESS = 280,                    /* LESS  */
    COMMA = 281,                   /* COMMA  */
    DOT = 282                      /* DOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 40 "smarthome.y"

    int intval;
    char* strval;
    SmartObject* objectval;

#line 97 "smarthome.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SMARTHOME_TAB_H_INCLUDED  */
