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
    ID = 260,                      /* ID  */
    CREATE_OBJECT = 261,           /* CREATE_OBJECT  */
    IF = 262,                      /* IF  */
    ELSE = 263,                    /* ELSE  */
    TURN_ON = 264,                 /* TURN_ON  */
    TURN_OFF = 265,                /* TURN_OFF  */
    SET_VOLUME = 266,              /* SET_VOLUME  */
    GRANT_ACCESS = 267,            /* GRANT_ACCESS  */
    CURRENT_TIME = 268,            /* CURRENT_TIME  */
    SUNRISE_TIME = 269,            /* SUNRISE_TIME  */
    SUNSET_TIME = 270,             /* SUNSET_TIME  */
    COLON = 271,                   /* COLON  */
    SEMICOLON = 272,               /* SEMICOLON  */
    LPAREN = 273,                  /* LPAREN  */
    RPAREN = 274,                  /* RPAREN  */
    LBRACE = 275,                  /* LBRACE  */
    RBRACE = 276,                  /* RBRACE  */
    EQUAL = 277,                   /* EQUAL  */
    GREATER = 278,                 /* GREATER  */
    LESS = 279,                    /* LESS  */
    COMMA = 280,                   /* COMMA  */
    DOT = 281,                     /* DOT  */
    SET_TEMPERATURE = 282,         /* SET_TEMPERATURE  */
    PRINT = 283,                   /* PRINT  */
    TURN_ON_LIGHT = 284,           /* TURN_ON_LIGHT  */
    TURN_OFF_LIGHT = 285,          /* TURN_OFF_LIGHT  */
    TURN_ON_BLINDS = 286,          /* TURN_ON_BLINDS  */
    TURN_OFF_BLINDS = 287,         /* TURN_OFF_BLINDS  */
    STATUS = 288                   /* STATUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "smarthome.y"

    int intval;
    char* strval;
    SmartObject* objectval;

#line 103 "smarthome.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SMARTHOME_TAB_H_INCLUDED  */
