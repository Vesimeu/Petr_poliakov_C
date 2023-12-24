/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "smarthome.y"

#include <stdio.h>
#include <stdlib.h>
#include "smart_objects.h"
#include <string.h>
#include "smarthome.tab.h"

// #define YYSTYPE_IS_DECLARED 1
// #define YYSTYPE_IS_TRIVIAL 1
bool in_false_if_block = false;
extern FILE* yyin;
extern int yylex();
extern char* yytext;

struct SmartObject;
SmartObject* current_object = NULL;  // Добавим переменную для хранения объекта
CommandList* current_command_list = NULL; // Добавим переменную для хранения текущего списка команд
void yyerror(const char* s);


#line 92 "smarthome.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "smarthome.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER = 3,                    /* INTEGER  */
  YYSYMBOL_CREATE_OBJECT = 4,              /* CREATE_OBJECT  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_TURN_ON = 7,                    /* TURN_ON  */
  YYSYMBOL_TURN_OFF = 8,                   /* TURN_OFF  */
  YYSYMBOL_SET_VOLUME = 9,                 /* SET_VOLUME  */
  YYSYMBOL_GRANT_ACCESS = 10,              /* GRANT_ACCESS  */
  YYSYMBOL_CURRENT_TIME = 11,              /* CURRENT_TIME  */
  YYSYMBOL_SUNRISE_TIME = 12,              /* SUNRISE_TIME  */
  YYSYMBOL_SUNSET_TIME = 13,               /* SUNSET_TIME  */
  YYSYMBOL_COLON = 14,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 15,                 /* SEMICOLON  */
  YYSYMBOL_LPAREN = 16,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 17,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 18,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 19,                    /* RBRACE  */
  YYSYMBOL_COMMA = 20,                     /* COMMA  */
  YYSYMBOL_DOT = 21,                       /* DOT  */
  YYSYMBOL_SET_TEMPERATURE = 22,           /* SET_TEMPERATURE  */
  YYSYMBOL_PRINT = 23,                     /* PRINT  */
  YYSYMBOL_PLUS = 24,                      /* PLUS  */
  YYSYMBOL_MINUS = 25,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 26,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 27,                    /* DIVIDE  */
  YYSYMBOL_STRING_VALUE = 28,              /* STRING_VALUE  */
  YYSYMBOL_INT_TYPE = 29,                  /* INT_TYPE  */
  YYSYMBOL_STRING_TYPE = 30,               /* STRING_TYPE  */
  YYSYMBOL_TURN_ON_LIGHT = 31,             /* TURN_ON_LIGHT  */
  YYSYMBOL_TURN_OFF_LIGHT = 32,            /* TURN_OFF_LIGHT  */
  YYSYMBOL_TURN_ON_BLINDS = 33,            /* TURN_ON_BLINDS  */
  YYSYMBOL_TURN_OFF_BLINDS = 34,           /* TURN_OFF_BLINDS  */
  YYSYMBOL_STATUS = 35,                    /* STATUS  */
  YYSYMBOL_GREATER = 36,                   /* GREATER  */
  YYSYMBOL_LESS = 37,                      /* LESS  */
  YYSYMBOL_EQUAL = 38,                     /* EQUAL  */
  YYSYMBOL_STRING = 39,                    /* STRING  */
  YYSYMBOL_ID = 40,                        /* ID  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_statement_list = 43,            /* statement_list  */
  YYSYMBOL_statement = 44,                 /* statement  */
  YYSYMBOL_create_object_statement = 45,   /* create_object_statement  */
  YYSYMBOL_light_command = 46,             /* light_command  */
  YYSYMBOL_blinds_command = 47,            /* blinds_command  */
  YYSYMBOL_set_temperature_statement = 48, /* set_temperature_statement  */
  YYSYMBOL_status_command = 49,            /* status_command  */
  YYSYMBOL_expression_statement = 50,      /* expression_statement  */
  YYSYMBOL_print_statement = 51,           /* print_statement  */
  YYSYMBOL_condition = 52,                 /* condition  */
  YYSYMBOL_relation_operator = 53,         /* relation_operator  */
  YYSYMBOL_if_else_statement = 54,         /* if_else_statement  */
  YYSYMBOL_55_1 = 55,                      /* $@1  */
  YYSYMBOL_56_2 = 56,                      /* $@2  */
  YYSYMBOL_57_3 = 57,                      /* $@3  */
  YYSYMBOL_58_4 = 58,                      /* $@4  */
  YYSYMBOL_59_5 = 59,                      /* $@5  */
  YYSYMBOL_assignment_statement = 60,      /* assignment_statement  */
  YYSYMBOL_variable_declaration = 61,      /* variable_declaration  */
  YYSYMBOL_argument_list = 62,             /* argument_list  */
  YYSYMBOL_expression = 63,                /* expression  */
  YYSYMBOL_time_expression = 64,           /* time_expression  */
  YYSYMBOL_object = 65,                    /* object  */
  YYSYMBOL_attribute_name = 66,            /* attribute_name  */
  YYSYMBOL_attribute = 67                  /* attribute  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   155

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  127

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    55,    55,    58,    59,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    75,    81,    84,    90,    91,
      95,    99,   101,   107,   119,   120,   124,   132,   133,   134,
     138,   142,   147,   138,   155,   159,   155,   170,   174,   177,
     182,   183,   186,   187,   201,   204,   207,   210,   218,   219,
     220,   221,   224,   225,   226,   229,   232,   235
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER",
  "CREATE_OBJECT", "IF", "ELSE", "TURN_ON", "TURN_OFF", "SET_VOLUME",
  "GRANT_ACCESS", "CURRENT_TIME", "SUNRISE_TIME", "SUNSET_TIME", "COLON",
  "SEMICOLON", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "COMMA", "DOT",
  "SET_TEMPERATURE", "PRINT", "PLUS", "MINUS", "MULTIPLY", "DIVIDE",
  "STRING_VALUE", "INT_TYPE", "STRING_TYPE", "TURN_ON_LIGHT",
  "TURN_OFF_LIGHT", "TURN_ON_BLINDS", "TURN_OFF_BLINDS", "STATUS",
  "GREATER", "LESS", "EQUAL", "STRING", "ID", "$accept", "program",
  "statement_list", "statement", "create_object_statement",
  "light_command", "blinds_command", "set_temperature_statement",
  "status_command", "expression_statement", "print_statement", "condition",
  "relation_operator", "if_else_statement", "$@1", "$@2", "$@3", "$@4",
  "$@5", "assignment_statement", "variable_declaration", "argument_list",
  "expression", "time_expression", "object", "attribute_name", "attribute", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-63)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-57)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,   -28,    -1,   -24,   -19,   -63,   -13,    27,    25,   -63,
      16,    23,    24,    34,    42,    46,    48,   -63,    63,    65,
      57,    59,    50,   -63,     1,    38,    40,     7,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,    66,    66,   -63,
     -63,    95,   -63,   -63,   -63,   -63,     7,    70,    80,   -63,
      88,   -63,    60,   -63,    77,    91,   -63,    82,    98,   102,
     105,   106,   107,   116,   117,   118,   -63,   120,    64,   -63,
     -63,   -63,     7,     7,     7,     7,    97,   -63,   -63,   -63,
     -63,   139,   126,   127,   128,   129,   130,     7,   -63,   -63,
     -63,     7,    82,    82,    82,    82,   132,   133,     5,     5,
     134,   -63,   -63,   -63,   -63,   -63,   -14,    82,   114,     7,
       3,    54,   -63,   135,     7,   -63,    39,   146,   -63,   -63,
      82,   -63,   136,   -63,     5,    56,   -63
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      30,     0,     0,     0,     0,    55,     0,     0,     2,     3,
       0,     0,     0,     0,     0,     0,     0,    12,     0,     0,
       0,     0,     0,    15,     0,     0,     0,     0,     1,     4,
       5,     7,     8,    10,     9,     6,    11,     0,     0,    14,
      13,     0,    42,    52,    53,    54,     0,    55,    43,    51,
       0,    48,     0,    50,     0,     0,    43,    37,     0,     0,
       0,     0,     0,     0,     0,     0,    56,     0,     0,    25,
      23,    24,     0,     0,     0,     0,     0,    38,    39,    31,
      35,     0,     0,     0,     0,     0,     0,     0,    27,    28,
      29,     0,    44,    45,    46,    47,    57,     0,    30,    30,
       0,    16,    17,    18,    19,    21,     0,    40,     0,     0,
      30,    30,    20,     0,     0,    26,     0,     0,    36,    22,
      41,    49,     0,    32,    30,    30,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -63,   -63,   -62,    -7,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,    29,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,    44,   -22,   -63,     0,    79,   -63
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    49,    91,    17,    18,    98,   124,    19,    99,    20,
      21,   106,   107,    51,    52,    67,    53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      22,    29,    50,   113,    42,    57,   114,     1,    22,     1,
      42,    23,    43,    44,    45,    24,    25,    46,    43,    44,
      45,    26,   117,    46,    68,    27,     2,    28,     2,     1,
     -30,    30,     3,     4,     3,     4,   110,   111,    31,    32,
      47,    48,     5,     6,     5,     6,     5,    56,     2,    33,
      92,    93,    94,    95,     3,     4,   121,    34,     1,   114,
       1,    35,   125,    36,     5,     6,    58,    59,    37,   108,
      38,    41,    39,   118,    40,   126,    54,     2,    55,     2,
      77,    76,    46,     3,     4,     3,     4,    69,    72,    73,
      74,    75,   120,     5,     6,     5,     6,    70,    22,    22,
      88,    89,    90,    29,    29,    71,    72,    73,    74,    75,
      22,    22,    72,    73,    74,    75,    79,    60,    29,    78,
      80,    81,    82,    83,    22,    22,    61,    62,    63,    64,
      65,   115,    84,    85,    86,    66,    87,    96,    72,    73,
      74,    75,   100,   101,   102,   103,   104,   105,   -56,   109,
     119,   112,   122,   116,   123,    97
};

static const yytype_int8 yycheck[] =
{
       0,     8,    24,    17,     3,    27,    20,     4,     8,     4,
       3,    39,    11,    12,    13,    16,    40,    16,    11,    12,
      13,    40,    19,    16,    46,    38,    23,     0,    23,     4,
       5,    15,    29,    30,    29,    30,    98,    99,    15,    15,
      39,    40,    39,    40,    39,    40,    39,    40,    23,    15,
      72,    73,    74,    75,    29,    30,    17,    15,     4,    20,
       4,    15,   124,    15,    39,    40,    37,    38,     5,    91,
       5,    21,    15,    19,    15,    19,    38,    23,    38,    23,
       3,    21,    16,    29,    30,    29,    30,    17,    24,    25,
      26,    27,   114,    39,    40,    39,    40,    17,    98,    99,
      36,    37,    38,   110,   111,    17,    24,    25,    26,    27,
     110,   111,    24,    25,    26,    27,    18,    22,   125,    28,
      18,    16,    16,    16,   124,   125,    31,    32,    33,    34,
      35,    17,    16,    16,    16,    40,    16,    40,    24,    25,
      26,    27,     3,    17,    17,    17,    17,    17,    16,    16,
      15,    17,     6,   109,    18,    76
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    23,    29,    30,    39,    40,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    54,    55,    58,
      60,    61,    65,    39,    16,    40,    40,    38,     0,    44,
      15,    15,    15,    15,    15,    15,    15,     5,     5,    15,
      15,    21,     3,    11,    12,    13,    16,    39,    40,    52,
      63,    64,    65,    67,    38,    38,    40,    63,    52,    52,
      22,    31,    32,    33,    34,    35,    40,    66,    63,    17,
      17,    17,    24,    25,    26,    27,    21,     3,    28,    18,
      18,    16,    16,    16,    16,    16,    16,    16,    36,    37,
      38,    53,    63,    63,    63,    63,    40,    66,    56,    59,
       3,    17,    17,    17,    17,    17,    62,    63,    63,    16,
      43,    43,    17,    17,    20,    17,    62,    19,    19,    15,
      63,    17,     6,    18,    57,    43,    19
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    45,    46,    46,    47,    47,
      48,    49,    50,    51,    51,    51,    52,    53,    53,    53,
      55,    56,    57,    54,    58,    59,    54,    60,    61,    61,
      62,    62,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    64,    64,    64,    65,    66,    67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     2,     2,     2,     5,     5,     5,     5,
       6,     5,     7,     4,     4,     4,     5,     1,     1,     1,
       0,     0,     0,    12,     0,     0,     7,     3,     4,     4,
       1,     3,     1,     1,     3,     3,     3,     3,     1,     6,
       1,     1,     1,     1,     1,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (yylval);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 15: /* create_object_statement: CREATE_OBJECT STRING  */
#line 75 "smarthome.y"
                                              { (yyval.objectval) = create_object((yyvsp[0].strval)); current_object = (yyval.objectval); }
#line 1233 "smarthome.tab.c"
    break;

  case 16: /* light_command: object DOT TURN_ON_LIGHT LPAREN RPAREN  */
#line 81 "smarthome.y"
                                                      { 
                add_command_to_list(turn_on_light, get_object((yyvsp[-4].objectval)), 0); 
             }
#line 1241 "smarthome.tab.c"
    break;

  case 17: /* light_command: object DOT TURN_OFF_LIGHT LPAREN RPAREN  */
#line 84 "smarthome.y"
                                                       { 
                add_command_to_list(turn_off_light, get_object((yyvsp[-4].objectval)), 0); 
             }
#line 1249 "smarthome.tab.c"
    break;

  case 18: /* blinds_command: object DOT TURN_ON_BLINDS LPAREN RPAREN  */
#line 90 "smarthome.y"
                                                        { add_command_to_list(turn_on_blinds, get_object((yyvsp[-4].objectval)), 0); }
#line 1255 "smarthome.tab.c"
    break;

  case 19: /* blinds_command: object DOT TURN_OFF_BLINDS LPAREN RPAREN  */
#line 91 "smarthome.y"
                                                        { add_command_to_list(turn_off_blinds, get_object((yyvsp[-4].objectval)), 0); }
#line 1261 "smarthome.tab.c"
    break;

  case 20: /* set_temperature_statement: object DOT SET_TEMPERATURE LPAREN INTEGER RPAREN  */
#line 95 "smarthome.y"
                                                                            { add_command_to_list(set_temperature, get_object((yyvsp[-5].objectval)), (yyvsp[-1].intval)) ;}
#line 1267 "smarthome.tab.c"
    break;

  case 21: /* status_command: object DOT STATUS LPAREN RPAREN  */
#line 99 "smarthome.y"
                                                {add_command_to_list(print_object_state, get_object((yyvsp[-4].objectval)), 0) ; }
#line 1273 "smarthome.tab.c"
    break;

  case 22: /* expression_statement: object DOT attribute_name LPAREN argument_list RPAREN SEMICOLON  */
#line 102 "smarthome.y"
{
    execute_method((yyvsp[-6].objectval), (yyvsp[-4].strval), (yyvsp[-2].intval)); // Выполняем метод объекта
}
#line 1281 "smarthome.tab.c"
    break;

  case 23: /* print_statement: PRINT LPAREN ID RPAREN  */
#line 107 "smarthome.y"
                           {
        Variable* var = get_variable((yyvsp[-1].strval));
        if (var != NULL) {
            if (var->type == INT) {
                printf("%d\n", var->int_value);
            } else if (var->type == STRING) {
                printf("%s\n", var->str_value);
            }
        } else {
            fprintf(stderr, "Error: Variable '%s' not found\n", (yyvsp[-1].strval));
        }
    }
#line 1298 "smarthome.tab.c"
    break;

  case 24: /* print_statement: PRINT LPAREN expression RPAREN  */
#line 119 "smarthome.y"
                                     { print_expression_result((yyvsp[-1].intval)); }
#line 1304 "smarthome.tab.c"
    break;

  case 25: /* print_statement: PRINT LPAREN STRING RPAREN  */
#line 120 "smarthome.y"
                                 { printf("%s\n", (yyvsp[-1].strval)); }
#line 1310 "smarthome.tab.c"
    break;

  case 26: /* condition: LPAREN expression relation_operator expression RPAREN  */
#line 125 "smarthome.y"
  {
    (yyval.conditionval) = create_condition((yyvsp[-3].intval), (yyvsp[-2].strval), (yyvsp[-1].intval));
  }
#line 1318 "smarthome.tab.c"
    break;

  case 30: /* $@1: %empty  */
#line 138 "smarthome.y"
{
    execute_command_list(); // Выполняем все команды до if
}
#line 1326 "smarthome.tab.c"
    break;

  case 31: /* $@2: %empty  */
#line 142 "smarthome.y"
{
    bool condition_result = evaluate_condition((yyvsp[-1].conditionval));
    in_false_if_block = !condition_result;
}
#line 1335 "smarthome.tab.c"
    break;

  case 32: /* $@3: %empty  */
#line 147 "smarthome.y"
{
    in_false_if_block = !in_false_if_block; // Инвертируем значение для блока else
}
#line 1343 "smarthome.tab.c"
    break;

  case 33: /* if_else_statement: $@1 IF condition LBRACE $@2 statement_list RBRACE ELSE LBRACE $@3 statement_list RBRACE  */
#line 151 "smarthome.y"
{
    in_false_if_block = false; // Сбрасываем значение после выполнения if или else
}
#line 1351 "smarthome.tab.c"
    break;

  case 34: /* $@4: %empty  */
#line 155 "smarthome.y"
{
    execute_command_list(); // Выполняем все команды до if
}
#line 1359 "smarthome.tab.c"
    break;

  case 35: /* $@5: %empty  */
#line 159 "smarthome.y"
{
    bool condition_result = evaluate_condition((yyvsp[-1].conditionval));
    in_false_if_block = !condition_result;
}
#line 1368 "smarthome.tab.c"
    break;

  case 36: /* if_else_statement: $@4 IF condition LBRACE $@5 statement_list RBRACE  */
#line 164 "smarthome.y"
{
    in_false_if_block = false; // Сбрасываем значение после выполнения if
}
#line 1376 "smarthome.tab.c"
    break;

  case 37: /* assignment_statement: ID EQUAL expression  */
#line 170 "smarthome.y"
                        { set_int_variable((yyvsp[-2].strval), (yyvsp[0].intval)); }
#line 1382 "smarthome.tab.c"
    break;

  case 38: /* variable_declaration: INT_TYPE ID EQUAL INTEGER  */
#line 174 "smarthome.y"
                              {
        add_int_variable((yyvsp[-2].strval), (yyvsp[0].intval));
    }
#line 1390 "smarthome.tab.c"
    break;

  case 39: /* variable_declaration: STRING_TYPE ID EQUAL STRING_VALUE  */
#line 177 "smarthome.y"
                                      {
        add_string_variable((yyvsp[-2].strval), (yyvsp[0].strval));
    }
#line 1398 "smarthome.tab.c"
    break;

  case 43: /* expression: ID  */
#line 187 "smarthome.y"
                 {
                Variable* var = get_variable((yyvsp[0].strval));
                if (var != NULL) {
                    if (var->type == INT) {
                        (yyval.intval) = var->int_value;
                    } else {
                        yyerror("Cannot perform arithmetic on string variable");
                        (yyval.intval) = 0;
                    }
                } else {
                    yyerror("Variable not found");
                    (yyval.intval) = 0;
                }
            }
#line 1417 "smarthome.tab.c"
    break;

  case 44: /* expression: expression PLUS expression  */
#line 201 "smarthome.y"
                                       {
                (yyval.intval) = (yyvsp[-2].intval) + (yyvsp[0].intval);
            }
#line 1425 "smarthome.tab.c"
    break;

  case 45: /* expression: expression MINUS expression  */
#line 204 "smarthome.y"
                                        {
                (yyval.intval) = (yyvsp[-2].intval) - (yyvsp[0].intval);
            }
#line 1433 "smarthome.tab.c"
    break;

  case 46: /* expression: expression MULTIPLY expression  */
#line 207 "smarthome.y"
                                           {
                (yyval.intval) = (yyvsp[-2].intval) * (yyvsp[0].intval);
            }
#line 1441 "smarthome.tab.c"
    break;

  case 47: /* expression: expression DIVIDE expression  */
#line 210 "smarthome.y"
                                         {
                if ((yyvsp[0].intval) == 0) {
                    yyerror("Division by zero");
                    (yyval.intval) = 0;
                } else {
                    (yyval.intval) = (yyvsp[-2].intval) / (yyvsp[0].intval);
                }
            }
#line 1454 "smarthome.tab.c"
    break;

  case 49: /* expression: object DOT attribute_name LPAREN argument_list RPAREN  */
#line 219 "smarthome.y"
                                                                  { (yyval.intval) = (SmartObject*)(yyvsp[-5].objectval); }
#line 1460 "smarthome.tab.c"
    break;

  case 55: /* object: STRING  */
#line 229 "smarthome.y"
               { (yyval.objectval) = get_object((yyvsp[0].strval)); }
#line 1466 "smarthome.tab.c"
    break;

  case 57: /* attribute: object DOT ID  */
#line 235 "smarthome.y"
                         { (yyval.intval) = get_attribute_value(current_object, (yyvsp[0].strval)); }
#line 1472 "smarthome.tab.c"
    break;


#line 1476 "smarthome.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 242 "smarthome.y"


void yyerror(const char* s) {
    fprintf(stderr, "Error: %s near '%s'\n", s, yytext);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s input_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE* input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    yyin = input_file;

    SmartObject* obj = NULL;  // Добавим переменную для хранения объекта
    // yyparse(&obj);  // Передадим указатель на объект в yyparse

    yyparse();
    execute_command_list();
    fclose(input_file);



    return 0;
}
