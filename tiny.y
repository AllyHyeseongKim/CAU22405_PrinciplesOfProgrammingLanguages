%{

#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);
%}

%union {
	int ival;
	float fval;
}

%token<ival> INTEGER
%token<fval> FLOATING
%token ID INT FLOAT LATTER DIGIT KEYWORD OPERATOR DELEMETER WHITESPACE
%token T_NEWLINE T_QUIT
/*
%left T_PLUS T_MINUS
%left T_MULTIPLY T_DIVIDE
*/

%start program

%%
program:
        | "mainprog" ID ";" declarations subprogram_declarations compound_statement
;
declarations:
        | type identifier_list ";" declarations
        | WHITESPACE
;
identifier_list:
        | ID
        | ID ";" identifier_list
;
type:
        | standard_type
        | standard_type "[" DIGIT "]"
;
standard_type:
        | "int"
        | "float"
;
subprogram_declarations:
        | subprogram_declaration subprogram_declarations
        | WHITESPACE
;
subprogram_declaration:
        | subprogram_head declarations compound_statement
;
subprogram_head:
        | "function" ID arguments ":" standard_type ";"
        | "procedure" ID
;
arguments:
        | ";"
;
arguments:
        | "(" parameter_list ")"
        | WHITESPACE
;
parameter_list:
        | identifier_list ":" type
        | identifier_list ":" type ";" parameter_list
;
compound_statement:
        |  "begin" statement_list "end"
;
statement_list:
        |  statement
        | statement ";" statement_list
;
statement:
        | variable "=" expression
        | print_statement
        | procedure_statement 
        | compound_statement 
        | if_statement 
        | while_statement
        | for_statement 
        | "return" expression 
        | "nop"
;
if_statement:
        |  "if" expression ":" statement 
        |  "if" expression ":" statement else_if_statement
        |  "if" expression ":" "else" ":" expression
        |  "if" expression ":" statement else_if_statement "else" ":" expression
;
else_if_statement:
        | "elif" expression ":" statement
        | "elif" expression ":" statement else_if_statement
;
while_statement:
        |  "while" expression ":" statement
        |  "while" expression ":" statement "else" ":" statement
;
for_statement:
        |  "for" expression "in" expression ":" statement
        |  "for" expression "in" expression ":" statement "else" ":" statement
;
print_statement:
        | "print" 
        | "print" "(" expression ")"
;
variable:
        | ID 
        | ID "[" expression "]"
;
procedure_statement:
        |  ID "(" actual_parameter_expression ")"
;
actual_parameter_expression:
        |  WHITESPACE | expression_list
;
expression_list:
        |  expression | expression "," expression_list
;
expression:
        |  simple_expression | simple_expression relop simple_expression
;
simple_expression:
        |  term | term addop simple_expression
;
/* NOTE THE ABOVE GRAMMAR HAS BEEN CHANGED */
term:
        |  factor | factor multop term
;
factor: 
        | INTEGER 
        | FLOATING 
        | variable 
        | procedure_statement 
        | "!" factor 
        | sign factor
;
/* NOTE THE ABOVE GRAMMAR HAS BEEN CHANGED */
sign:
        | "+" 
        | "-" 
;
relop:
        | ">" 
        | ">=" 
        | "<" 
        | "<=" 
        | "==" 
        | "!=" 
        | "in"
;
addop:
        | "+" 
        | "-"
;
multop:
        | "*"
        | "/"
;
%%

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("You put one argument\n");
        return 0;
    }
    if (argc > 2)
        printf("You put over two argument\n");
        return 0;

	yyin = fopen(argv[1], "r");

	do {
		yyparse();
	} while(!feof(yyin));

	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}