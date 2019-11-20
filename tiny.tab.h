/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 16 "tiny.y"
{
	int ival;
	float fval;
        char cval;
        char sval[100];
}
/* Line 1529 of yacc.c.  */
#line 152 "tiny.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

