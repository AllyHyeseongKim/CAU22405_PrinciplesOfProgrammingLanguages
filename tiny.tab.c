/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_INTEGER = 258,
     T_ID = 259,
     T_FLOATING = 260,
     T_PLUS = 261,
     T_MINUS = 262,
     T_MULTIPLE = 263,
     T_DIVIDE = 264,
     T_SMALLER = 265,
     T_EQUAL = 266,
     T_NOT_EQUAL = 267,
     T_ASSIGN = 268,
     T_SMALLER_EQUAL = 269,
     T_LARGER_EQUAL = 270,
     T_LARGER = 271,
     T_INT = 272,
     T_FLOAT = 273,
     T_NONE = 274,
     T_LATTER = 275,
     T_NEWLINE = 276,
     T_QUIT = 277,
     T_MAINPROG = 278,
     T_FUNCTION = 279,
     T_PROCEDURE = 280,
     T_BEGIN = 281,
     T_END = 282,
     T_IF = 283,
     T_THEN = 284,
     T_ELSE = 285,
     T_NOP = 286,
     T_WHILE = 287,
     T_RETURN = 288,
     T_PRINT = 289,
     T_IN = 290,
     T_OPERATOR = 291,
     T_SEMICOLON = 292,
     T_PERIOD = 293,
     T_COMMA = 294,
     T_LEFT_PARENTHESIS = 295,
     T_RIGHT_PARENTHESIS = 296,
     T_FOR = 297,
     T_LEFT_BRACKET = 298,
     T_RIGHT_BRACKET = 299,
     T_COLON = 300,
     T_COMMENT = 301,
     T_ELIF = 302,
     T_NOT = 303
   };
#endif
/* Tokens.  */
#define T_INTEGER 258
#define T_ID 259
#define T_FLOATING 260
#define T_PLUS 261
#define T_MINUS 262
#define T_MULTIPLE 263
#define T_DIVIDE 264
#define T_SMALLER 265
#define T_EQUAL 266
#define T_NOT_EQUAL 267
#define T_ASSIGN 268
#define T_SMALLER_EQUAL 269
#define T_LARGER_EQUAL 270
#define T_LARGER 271
#define T_INT 272
#define T_FLOAT 273
#define T_NONE 274
#define T_LATTER 275
#define T_NEWLINE 276
#define T_QUIT 277
#define T_MAINPROG 278
#define T_FUNCTION 279
#define T_PROCEDURE 280
#define T_BEGIN 281
#define T_END 282
#define T_IF 283
#define T_THEN 284
#define T_ELSE 285
#define T_NOP 286
#define T_WHILE 287
#define T_RETURN 288
#define T_PRINT 289
#define T_IN 290
#define T_OPERATOR 291
#define T_SEMICOLON 292
#define T_PERIOD 293
#define T_COMMA 294
#define T_LEFT_PARENTHESIS 295
#define T_RIGHT_PARENTHESIS 296
#define T_FOR 297
#define T_LEFT_BRACKET 298
#define T_RIGHT_BRACKET 299
#define T_COLON 300
#define T_COMMENT 301
#define T_ELIF 302
#define T_NOT 303




/* Copy the first part of user declarations.  */
#line 1 "tiny.y"

#include "astgen.h"
#include "astexec.h"
#include <stdio.h>
#include <stdlib.h>
#define YYPARSE_PARAM astDest

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int stack_frame;
extern int stackSize;

int varIndex = 0;
int argSize = 0;
TYPE varType;
int subName=0;

void yyerror(const char* s);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 22 "tiny.y"
{
	int ival;
	float fval;
        char cval;
        char sval[100];
        struct AstElement* ast;
}
/* Line 193 of yacc.c.  */
#line 221 "tiny.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 234 "tiny.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   138

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  145

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,    11,    18,    23,    24,    26,    30,
      32,    37,    39,    41,    44,    45,    49,    56,    61,    65,
      68,    72,    78,    82,    84,    88,    90,    92,    94,   102,
     103,   108,   116,   120,   122,   124,   126,   128,   130,   133,
     135,   140,   148,   153,   161,   165,   167,   172,   174,   179,
     184,   186,   187,   189,   193,   195,   199,   203,   207,   211,
     215,   219,   221,   225,   229,   231,   235,   239,   241,   243,
     245,   247,   250,   253
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    -1,    23,     4,    37,    51,    55,    60,
      -1,    23,     4,     1,    51,    55,    60,    -1,    53,    52,
      37,    51,    -1,    -1,     4,    -1,     4,    39,    52,    -1,
      54,    -1,    54,    43,     3,    44,    -1,    17,    -1,    18,
      -1,    56,    55,    -1,    -1,    57,    51,    60,    -1,    24,
       4,    58,    45,    54,    37,    -1,    25,     4,    58,    37,
      -1,    40,    59,    41,    -1,    40,    41,    -1,    53,    45,
      52,    -1,    53,    45,    52,    37,    59,    -1,    26,    61,
      27,    -1,    62,    -1,    62,    37,    61,    -1,    63,    -1,
      64,    -1,    65,    -1,    28,    74,    45,    63,    30,    45,
      63,    -1,    -1,    28,    74,    45,    62,    -1,    28,    74,
      45,    63,    30,    45,    64,    -1,    70,    13,    74,    -1,
      69,    -1,    71,    -1,    60,    -1,    66,    -1,    67,    -1,
      33,    74,    -1,    31,    -1,    32,    74,    45,    62,    -1,
      32,    74,    45,    62,    30,    45,    62,    -1,    42,    68,
      45,    62,    -1,    42,    68,    45,    62,    30,    45,    62,
      -1,    70,    35,    70,    -1,    34,    -1,    34,    40,    74,
      41,    -1,     4,    -1,     4,    43,    74,    44,    -1,     4,
      40,    72,    41,    -1,    73,    -1,    -1,    74,    -1,    74,
      39,    73,    -1,    75,    -1,    75,    16,    75,    -1,    75,
      15,    75,    -1,    75,    10,    75,    -1,    75,    14,    75,
      -1,    75,    11,    75,    -1,    75,    12,    75,    -1,    76,
      -1,    76,     6,    75,    -1,    76,     7,    75,    -1,    77,
      -1,    77,     8,    76,    -1,    77,     9,    76,    -1,     3,
      -1,     5,    -1,    70,    -1,    71,    -1,    48,    77,    -1,
       6,    77,    -1,     7,    77,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    54,    54,    55,    56,    60,    61,    64,    65,    68,
      69,    72,    73,    76,    77,    80,    83,    84,    87,    88,
      91,    92,    95,    98,    99,   102,   103,   106,   107,   109,
     110,   111,   114,   115,   116,   117,   118,   119,   120,   121,
     134,   135,   138,   139,   142,   145,   146,   149,   150,   153,
     156,   157,   160,   161,   164,   165,   166,   167,   168,   169,
     170,   173,   174,   175,   179,   180,   181,   184,   185,   186,
     187,   188,   189,   190
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_INTEGER", "T_ID", "T_FLOATING",
  "T_PLUS", "T_MINUS", "T_MULTIPLE", "T_DIVIDE", "T_SMALLER", "T_EQUAL",
  "T_NOT_EQUAL", "T_ASSIGN", "T_SMALLER_EQUAL", "T_LARGER_EQUAL",
  "T_LARGER", "T_INT", "T_FLOAT", "T_NONE", "T_LATTER", "T_NEWLINE",
  "T_QUIT", "T_MAINPROG", "T_FUNCTION", "T_PROCEDURE", "T_BEGIN", "T_END",
  "T_IF", "T_THEN", "T_ELSE", "T_NOP", "T_WHILE", "T_RETURN", "T_PRINT",
  "T_IN", "T_OPERATOR", "T_SEMICOLON", "T_PERIOD", "T_COMMA",
  "T_LEFT_PARENTHESIS", "T_RIGHT_PARENTHESIS", "T_FOR", "T_LEFT_BRACKET",
  "T_RIGHT_BRACKET", "T_COLON", "T_COMMENT", "T_ELIF", "T_NOT", "$accept",
  "program_start", "declarations", "identifier_list", "type",
  "standard_type", "subprogram_declarations", "subprogram_declaration",
  "subprogram_head", "arguments", "parameter_list", "compound_statement",
  "statement_list", "statement", "match_statement", "unmatch_statement",
  "other_statment", "while_statement", "for_statement", "for_condition",
  "print_statement", "variable", "procedure_statement",
  "actual_parameter_expression", "expression_list", "expression",
  "simple_expression", "term", "factor", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    50,    51,    51,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    57,    57,    58,    58,
      59,    59,    60,    61,    61,    62,    62,    63,    63,    64,
      64,    64,    65,    65,    65,    65,    65,    65,    65,    65,
      66,    66,    67,    67,    68,    69,    69,    70,    70,    71,
      72,    72,    73,    73,    74,    74,    74,    74,    74,    74,
      74,    75,    75,    75,    76,    76,    76,    77,    77,    77,
      77,    77,    77,    77
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     6,     4,     0,     1,     3,     1,
       4,     1,     1,     2,     0,     3,     6,     4,     3,     2,
       3,     5,     3,     1,     3,     1,     1,     1,     7,     0,
       4,     7,     3,     1,     1,     1,     1,     1,     2,     1,
       4,     7,     4,     7,     3,     1,     4,     1,     4,     4,
       1,     0,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     1,     1,
       1,     2,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     1,     6,     6,    11,    12,    14,
       0,     9,    14,     0,     0,     0,    14,     6,     7,     0,
       0,     0,     0,     0,    29,     4,    13,     0,     0,     6,
       0,     3,     0,     0,     0,    47,     0,    39,     0,     0,
      45,     0,    35,     0,    23,    25,    26,    27,    36,    37,
      33,     0,    34,    15,     8,     5,    10,    19,     0,     0,
       0,    17,    51,     0,    67,    68,     0,     0,     0,    69,
      70,     0,    54,    61,    64,     0,    38,     0,    47,     0,
       0,    22,    29,     0,     0,    18,     0,     0,    50,    52,
       0,    72,    73,    71,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,     0,    29,     0,    24,
      32,    20,    16,    49,     0,    48,    30,    25,    57,    59,
      60,    58,    56,    55,    62,    63,    65,    66,    40,    46,
      42,    44,     0,    53,     0,     0,     0,    21,    29,    29,
      29,    28,    31,    41,    43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     9,    19,    10,    11,    15,    16,    17,    33,
      59,    42,    43,    44,    45,    46,    47,    48,    49,    79,
      50,    69,    70,    87,    88,    89,    72,    73,    74
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -93
static const yytype_int8 yypact[] =
{
       9,    44,    52,    19,   -93,    22,    22,   -93,   -93,    36,
      50,    14,    36,    62,    73,    54,    36,    22,    39,    42,
      79,    54,    46,    46,     3,   -93,   -93,    54,    50,    22,
      55,   -93,     8,    51,    60,    -2,     7,   -93,     7,     7,
      58,    96,   -93,    75,    66,   -93,   -93,   -93,   -93,   -93,
     -93,    91,   -93,   -93,   -93,   -93,   -93,   -93,    61,    64,
      22,   -93,     7,     7,   -93,   -93,     7,     7,     7,   -93,
     -93,    63,    53,    16,    35,    65,   -93,     7,    68,    67,
      72,   -93,     3,     7,    50,   -93,    76,    80,   -93,    70,
      78,   -93,   -93,   -93,     3,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     3,    82,     3,    96,   -93,
     -93,    87,   -93,   -93,     7,   -93,   -93,    95,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,    97,   -93,
      98,   -93,    22,   -93,    81,    84,    85,   -93,     3,     3,
       3,   -93,   -93,   -93,   -93
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -93,   -93,    13,   -25,   -31,    57,    12,   -93,   -93,   108,
       1,     0,    56,   -89,   -92,    -6,   -93,   -93,   -93,   -93,
     -93,   -24,   -20,   -93,    20,   -30,    -7,   -28,     5
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      51,    58,   117,    54,    52,   116,    71,    35,    75,    76,
      64,    35,    65,    66,    67,    25,   128,    80,   130,    12,
       5,    31,   101,   102,    21,     7,     8,    53,    26,    24,
      27,    36,     1,    90,    37,    38,    39,    40,    62,     7,
       8,    63,    55,   103,   104,    41,   141,   106,     3,    57,
     143,   144,     4,   110,    18,    68,     6,    20,    51,   111,
      13,    14,    52,    95,    96,    97,    22,    98,    99,   100,
      51,    91,    92,    93,    52,   126,   127,    23,    28,    29,
      24,    51,    30,    51,   131,    52,    32,    52,   118,   119,
     120,   121,   122,   123,   124,   125,    60,    61,    77,    56,
      78,    58,    81,    82,    83,    85,    84,   108,    94,   114,
     105,    63,   107,   112,    51,    51,    51,    86,    52,    52,
      52,   113,   115,   129,   132,   134,   138,   135,   136,   139,
     140,    34,   142,   137,   133,     0,     0,     0,   109
};

static const yytype_int16 yycheck[] =
{
      24,    32,    94,    28,    24,    94,    36,     4,    38,    39,
       3,     4,     5,     6,     7,    15,   105,    41,   107,     6,
       1,    21,     6,     7,    12,    17,    18,    27,    16,    26,
      17,    28,    23,    63,    31,    32,    33,    34,    40,    17,
      18,    43,    29,     8,     9,    42,   138,    77,     4,    41,
     139,   140,     0,    83,     4,    48,    37,    43,    82,    84,
      24,    25,    82,    10,    11,    12,     4,    14,    15,    16,
      94,    66,    67,    68,    94,   103,   104,     4,    39,    37,
      26,   105,     3,   107,   108,   105,    40,   107,    95,    96,
      97,    98,    99,   100,   101,   102,    45,    37,    40,    44,
       4,   132,    27,    37,    13,    41,    45,    35,    45,    39,
      45,    43,    45,    37,   138,   139,   140,    60,   138,   139,
     140,    41,    44,    41,    37,    30,    45,    30,    30,    45,
      45,    23,   138,   132,   114,    -1,    -1,    -1,    82
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    23,    50,     4,     0,     1,    37,    17,    18,    51,
      53,    54,    51,    24,    25,    55,    56,    57,     4,    52,
      43,    55,     4,     4,    26,    60,    55,    51,    39,    37,
       3,    60,    40,    58,    58,     4,    28,    31,    32,    33,
      34,    42,    60,    61,    62,    63,    64,    65,    66,    67,
      69,    70,    71,    60,    52,    51,    44,    41,    53,    59,
      45,    37,    40,    43,     3,     5,     6,     7,    48,    70,
      71,    74,    75,    76,    77,    74,    74,    40,     4,    68,
      70,    27,    37,    13,    45,    41,    54,    72,    73,    74,
      74,    77,    77,    77,    45,    10,    11,    12,    14,    15,
      16,     6,     7,     8,     9,    45,    74,    45,    35,    61,
      74,    52,    37,    41,    39,    44,    62,    63,    75,    75,
      75,    75,    75,    75,    75,    75,    76,    76,    62,    41,
      62,    70,    37,    73,    30,    30,    30,    59,    45,    45,
      45,    63,    64,    62,    62
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 55 "tiny.y"
    { make_id(0, 0, 1);(*(struct AstElement**)astDest) = combineStatement((yyvsp[(4) - (6)].ast), (yyvsp[(6) - (6)].ast));;}
    break;

  case 4:
#line 56 "tiny.y"
    {printf("No semicolon"); (*(struct AstElement**)astDest) = combineStatement((yyvsp[(4) - (6)].ast), (yyvsp[(6) - (6)].ast));;}
    break;

  case 5:
#line 60 "tiny.y"
    {(yyval.ast) = combineStatement((yyvsp[(2) - (4)].ast), (yyvsp[(4) - (4)].ast));;}
    break;

  case 6:
#line 61 "tiny.y"
    {(yyval.ast) = 0;}
    break;

  case 7:
#line 64 "tiny.y"
    {(yyval.ast) = makeStatement(makeVariable((yyvsp[(1) - (1)].ival), varType, varIndex), 0); argSize += varIndex;;}
    break;

  case 8:
#line 65 "tiny.y"
    {(yyval.ast) = makeStatement(makeVariable((yyvsp[(1) - (3)].ival), varType, varIndex), (yyvsp[(3) - (3)].ast)); argSize += varIndex;;}
    break;

  case 9:
#line 68 "tiny.y"
    {varIndex = 1; varType = (TYPE)(yyvsp[(1) - (1)].ival);}
    break;

  case 10:
#line 69 "tiny.y"
    {varIndex = (yyvsp[(3) - (4)].ival); varType = (TYPE)(yyvsp[(1) - (4)].ival);}
    break;

  case 11:
#line 72 "tiny.y"
    {(yyval.ival) = INT;}
    break;

  case 12:
#line 73 "tiny.y"
    {(yyval.ival) = FLOAT;;}
    break;

  case 13:
#line 76 "tiny.y"
    {;}
    break;

  case 15:
#line 80 "tiny.y"
    {sub_program_map[subName] = makeStatement(makeCompoundStmt(combineStatement((yyvsp[(1) - (3)].ast), combineStatement((yyvsp[(2) - (3)].ast), (yyvsp[(3) - (3)].ast)))), 0);}
    break;

  case 16:
#line 83 "tiny.y"
    {(yyval.ast) = (yyvsp[(3) - (6)].ast); varType=FUNCTION; subName=(yyvsp[(2) - (6)].ival);;}
    break;

  case 17:
#line 84 "tiny.y"
    {(yyval.ast) = (yyvsp[(3) - (4)].ast); varType=PROCEDURE; subName=(yyvsp[(2) - (4)].ival);;}
    break;

  case 18:
#line 87 "tiny.y"
    {(yyval.ast) = (yyvsp[(2) - (3)].ast);}
    break;

  case 19:
#line 88 "tiny.y"
    {(yyval.ast) = 0; argSize=0;;}
    break;

  case 20:
#line 91 "tiny.y"
    {(yyval.ast) = (yyvsp[(3) - (3)].ast);}
    break;

  case 21:
#line 92 "tiny.y"
    {(yyval.ast) = combineStatement((yyvsp[(3) - (5)].ast), (yyvsp[(5) - (5)].ast));;}
    break;

  case 22:
#line 95 "tiny.y"
    {(yyval.ast) = makeStatement(makeCompoundStmt((yyvsp[(2) - (3)].ast)), 0);}
    break;

  case 23:
#line 98 "tiny.y"
    {(yyval.ast) = makeStatement((yyvsp[(1) - (1)].ast), 0);;}
    break;

  case 24:
#line 99 "tiny.y"
    {(yyval.ast) = makeStatement((yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));;}
    break;

  case 25:
#line 102 "tiny.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);}
    break;

  case 26:
#line 103 "tiny.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);}
    break;

  case 27:
#line 106 "tiny.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);}
    break;

  case 28:
#line 107 "tiny.y"
    {(yyval.ast) = makeIfElse((yyvsp[(2) - (7)].ast), (yyvsp[(4) - (7)].ast), (yyvsp[(7) - (7)].ast));}
    break;

  case 30:
#line 110 "tiny.y"
    {(yyval.ast) = makeIfElse((yyvsp[(2) - (4)].ast), (yyvsp[(4) - (4)].ast), makeNop());}
    break;

  case 31:
#line 111 "tiny.y"
    {(yyval.ast) = makeIfElse((yyvsp[(2) - (7)].ast), (yyvsp[(4) - (7)].ast), (yyvsp[(7) - (7)].ast));}
    break;

  case 32:
#line 114 "tiny.y"
    {(yyval.ast) = makeAssignment((yyvsp[(1) - (3)].ival), varIndex, (yyvsp[(3) - (3)].ast));;}
    break;

  case 33:
#line 115 "tiny.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);}
    break;

  case 34:
#line 116 "tiny.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);}
    break;

  case 35:
#line 117 "tiny.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);}
    break;

  case 36:
#line 118 "tiny.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);}
    break;

  case 37:
#line 119 "tiny.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);}
    break;

  case 38:
#line 120 "tiny.y"
    {(yyval.ast) = makeAssignmentByAddress((yyvsp[(2) - (2)].ast));;}
    break;

  case 39:
#line 121 "tiny.y"
    {(yyval.ast) = makeNop();}
    break;

  case 40:
#line 134 "tiny.y"
    {(yyval.ast) = makeWhile((yyvsp[(2) - (4)].ast), (yyvsp[(4) - (4)].ast));;}
    break;

  case 41:
#line 135 "tiny.y"
    {(yyval.ast) = makeIfElse((yyvsp[(2) - (7)].ast), makeWhile((yyvsp[(2) - (7)].ast), (yyvsp[(4) - (7)].ast)), (yyvsp[(7) - (7)].ast));}
    break;

  case 42:
#line 138 "tiny.y"
    {(yyval.ast) = makeFor((yyvsp[(2) - (4)].ast), (yyvsp[(4) - (4)].ast));}
    break;

  case 43:
#line 139 "tiny.y"
    {(yyval.ast) = makeIfElse((yyvsp[(2) - (7)].ast), makeFor((yyvsp[(2) - (7)].ast), (yyvsp[(4) - (7)].ast)), (yyvsp[(7) - (7)].ast));}
    break;

  case 44:
#line 142 "tiny.y"
    {(yyval.ast) = makeForCondition((yyvsp[(1) - (3)].ival), (yyvsp[(3) - (3)].ival));}
    break;

  case 45:
#line 145 "tiny.y"
    {(yyval.ast) = makeNop();}
    break;

  case 46:
#line 146 "tiny.y"
    {(yyval.ast) = makeCall("print", (yyvsp[(3) - (4)].ast));;}
    break;

  case 47:
#line 149 "tiny.y"
    {(yyval.ival) = (yyvsp[(1) - (1)].ival); varIndex = 0;;}
    break;

  case 48:
#line 150 "tiny.y"
    {(yyval.ival) = (yyvsp[(1) - (4)].ival); ;}
    break;

  case 49:
#line 153 "tiny.y"
    {(yyval.ast) = makeProcedure((yyvsp[(1) - (4)].ival), (yyvsp[(3) - (4)].ast));}
    break;

  case 50:
#line 156 "tiny.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 51:
#line 157 "tiny.y"
    {(yyval.ast) = makeParameters(0, 0);}
    break;

  case 52:
#line 160 "tiny.y"
    {(yyval.ast) = makeParameters((yyvsp[(1) - (1)].ast), 0); ;}
    break;

  case 53:
#line 161 "tiny.y"
    {(yyval.ast) = makeParameters((yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));;}
    break;

  case 54:
#line 164 "tiny.y"
    {(yyval.ast) = makeExp((yyvsp[(1) - (1)].ast), makeExpByNum(0), '+');}
    break;

  case 55:
#line 165 "tiny.y"
    {(yyval.ast) = makeExp((yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), '>');;}
    break;

  case 56:
#line 166 "tiny.y"
    {(yyval.ast) = makeExp((yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), '1');;}
    break;

  case 57:
#line 167 "tiny.y"
    {(yyval.ast) = makeExp((yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), '<');;}
    break;

  case 58:
#line 168 "tiny.y"
    {(yyval.ast) = makeExp((yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), '2');;}
    break;

  case 59:
#line 169 "tiny.y"
    {(yyval.ast) = makeExp((yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), '=');;}
    break;

  case 60:
#line 170 "tiny.y"
    {(yyval.ast) = makeExp((yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), '!');;}
    break;

  case 61:
#line 173 "tiny.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 62:
#line 174 "tiny.y"
    {(yyval.ast) = makeExp((yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), '+');;}
    break;

  case 63:
#line 175 "tiny.y"
    {(yyval.ast) = makeExp((yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), '-');;}
    break;

  case 64:
#line 179 "tiny.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);}
    break;

  case 65:
#line 180 "tiny.y"
    {(yyval.ast) = makeExp((yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), '*');;}
    break;

  case 66:
#line 181 "tiny.y"
    {(yyval.ast) = makeExp((yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), '/');;}
    break;

  case 67:
#line 184 "tiny.y"
    {(yyval.ast) = makeExpByNum((yyvsp[(1) - (1)].ival)); varIndex = (yyvsp[(1) - (1)].ival);;}
    break;

  case 68:
#line 185 "tiny.y"
    {(yyval.ast) = makeExpByNum((yyvsp[(1) - (1)].fval));}
    break;

  case 69:
#line 186 "tiny.y"
    {(yyval.ast) = makeExpByName((yyvsp[(1) - (1)].ival), varIndex);;}
    break;

  case 70:
#line 187 "tiny.y"
    {(yyval.ast) = makeExpByAddress(makeStatement((yyvsp[(1) - (1)].ast), 0));;}
    break;

  case 71:
#line 188 "tiny.y"
    {(yyval.ast) = ((yyvsp[(2) - (2)].ast)->data.val) ? (yyvsp[(2) - (2)].ast) : makeExpByNum(0);}
    break;

  case 72:
#line 189 "tiny.y"
    {(yyval.ast) = makeExp(makeExpByNum(0), (yyvsp[(2) - (2)].ast), '+');}
    break;

  case 73:
#line 190 "tiny.y"
    {(yyval.ast) = makeExp(makeExpByNum(0), (yyvsp[(2) - (2)].ast), '-');}
    break;


/* Line 1267 of yacc.c.  */
#line 1907 "tiny.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 193 "tiny.y"


int main(int argc, char* argv[]) {
        
	yyin = fopen("test.tiny", "r");
        struct AstElement *a = 0;

	while(!feof(yyin)) {
		yyparse(&a);
	}
        struct ExecEnviron* e = createEnv();
        execAst(e, a);
        freeEnv(e);

	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
}




