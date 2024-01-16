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

#ifndef YY_YY_CONTROL_TAB_H_INCLUDED
# define YY_YY_CONTROL_TAB_H_INCLUDED
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
    ADD_ROOM = 259,                /* ADD_ROOM  */
    TURN_ON = 260,                 /* TURN_ON  */
    TURN_OFF = 261,                /* TURN_OFF  */
    COLON = 262,                   /* COLON  */
    LPAREN = 263,                  /* LPAREN  */
    RPAREN = 264,                  /* RPAREN  */
    LBRACE = 265,                  /* LBRACE  */
    RBRACE = 266,                  /* RBRACE  */
    COMMA = 267,                   /* COMMA  */
    START = 268,                   /* START  */
    PRINT = 269,                   /* PRINT  */
    END = 270,                     /* END  */
    AND = 271,                     /* AND  */
    SET_AUDIO_LEVEL = 272,         /* SET_AUDIO_LEVEL  */
    SET_TEMPERATURE = 273,         /* SET_TEMPERATURE  */
    SET_LIGHT_MODE = 274,          /* SET_LIGHT_MODE  */
    SET_BLINDS_MODE = 275,         /* SET_BLINDS_MODE  */
    SET_SAFE_MODE = 276,           /* SET_SAFE_MODE  */
    INFO = 277,                    /* INFO  */
    GREATER = 278,                 /* GREATER  */
    LESS = 279,                    /* LESS  */
    EQUAL = 280,                   /* EQUAL  */
    STRING = 281,                  /* STRING  */
    ID = 282                       /* ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "control.y"

    int intval;
    char* strval;
    Room* objectval;

#line 97 "control.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CONTROL_TAB_H_INCLUDED  */
