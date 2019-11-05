%option noyywrap

%{
#include <stdio.h>

#define YY_DECL int yylex()

#include "tiny.tab.h"

%}

%%

LATTER(LATTER|DIGIT)*                               {return ID;}
"int"                                               {return INT;}
"float"                                             {return FLOAT;}
[a-zA-Z]                                            {return LATTER;}
[0-9]                                               {return DIGIT;}
DIGIT+		                                        {yylval.ival = atoi(yytext); return INTEGER;}
DIGIT+\.DIGIT+ 	                                    {yylval.fval = atof(yytext); return FLOATING;}
("mainprog"|"function"|"procedure"|"begin"|"end"|"if"|"then"|"else"|"nop"|"while"|"return"|"print"|"in")  {return KEYWORD;}
("+"|"-"|"*"|"/"|"<"|"<="|">="|">"|"=="|"!="|"!")   {return OPERATOR;}
(";"|"."|","|"="|"("|")"|"["|"]"|":")               {return DELEMETER;}
(" "+|[\t]+|\n+|"//")                               {return WHITESPACE;}

%%