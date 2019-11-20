%option noyywrap

%{
#include <stdio.h>


#define YY_DECL int yylex()

#include "tiny.tab.h"


%}

%%

"//"                                                {return T_COMMENT;}
"+"                                                 {return T_PLUS;}
"-"                                                 {return T_MINUS;}
"*"                                                 {return T_MULTIPLE;}
"/"                                                 {return T_DIVIDE;}
"<="                                                {return T_SMALLER_EQUAL;}
">="                                                {return T_LARGER_EQUAL;}                                               
">"                                                 {return T_LARGER;}
"<"                                                 {return T_SMALLER;}
"=="                                                {return T_EQUAL;}
"!="                                                {return T_NOT_EQUAL;}
"="                                                 {return T_ASSIGN;}
"!"                                                 {return T_NOT;}
";"                                                 {return T_SEMICOLON;}
"."                                                 {return T_PERIOD;}
","                                                 {return T_COMMA;}
"("                                                 {return T_LEFT_PARENTHESIS;}
")"                                                 {return T_RIGHT_PARENTHESIS;}
"["                                                 {return T_LEFT_BRACKET;}
"]"                                                 {return T_RIGHT_BRACKET;}
":"                                                 {return T_COLON;}
[ \t\n]*                                              ;
"mainprog"                                          {return T_MAINPROG;}
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
"elif"                                              {return T_ELIF;}
"int"                                               {strcpy(yylval.sval, yytext);  return T_INT;}
"in"                                                {return T_IN;}
"float"                                             {strcpy(yylval.sval, yytext);  return T_FLOAT;}
"for"                                               {return T_FOR;}


[a-zA-Z][a-zA-Z0-9]*                                {
    int res = 0;
    for(int i = 0; i < strlen(yytext); i++)
        res += (yytext[0] << 2);
    res = (res > 0)? res : -res;
    yylval.ival = (res % 10000); return T_ID;}
[0-9]+\.[0-9]+ 	                                    {yylval.fval = atof(yytext); return T_FLOATING;}
[0-9]+		                                        {yylval.ival = atoi(yytext); return T_INTEGER;}
.                                                   {return T_NONE;}
%%
