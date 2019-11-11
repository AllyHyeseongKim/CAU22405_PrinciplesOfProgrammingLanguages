%option noyywrap

%{
#include <stdio.h>

#define YY_DECL int yylex()

#include "tiny.tab.h"

%}

%%

[a-zA-Z][a-zA-Z0-9]*                                {return T_ID;}
"int"                                               {return T_INT;}
"float"                                             {return T_FLOAT;}
[a-zA-Z]                                            {return T_LATTER;}
[0-9]                                               {return T_DIGIT;}
[0-9]+		                                        {yylval.ival = atoi(yytext); return T_INTEGER;}
[0-9]+\.[0-9]+ 	                                    {yylval.fval = atof(yytext); return T_FLOATING;}
"mainprog"                                          {printf("sd"); return T_MAINPROG;}
"function"                                          {return T_FUNCTION;}
"procedure"                                         {return T_PROCEDURE;}
"begin"                                             {return T_BEGIN;}
"end"                                               {return T_END;}
"if"                                                {return T_IF;}
"then"                                              {return T_THEN;}
"else"                                              {return T_ELSE;}
"nop"                                               {return T_NOP;}
"while"                                             {return T_WHILE;}
"return"                                            {return T_RETURN;}
"print"                                             {return T_PRINT;}
"in"                                                {return T_IN;}
"elif"                                              {return T_ELIF;}

("+"|"-"|"*"|"/"|"< "|"<="|">="|">"|"=="|"!="|"!")  {return T_OPERATOR;}
";"                                                 {return T_SEMICOLON;}
"."                                                 {return T_PERIOD;}
","                                                 {return T_COMMA;}
"="                                                 {return T_EQUAL;}
"("                                                 {return T_LEFT_PARENTHESIS;}
")"                                                 {return T_RIGHT_PARENTHESIS;}
"["                                                 {return T_LEFT_BRACKET;}
"]"                                                 {return T_RIGHT_BRACKET;}
":"                                                 {return T_COLON;}
[\t ]*                                              {return T_WHITESPACE;}
"//"                                                {return T_COMMENT;}
\n                                                  {return T_NEWLINE;}


%%