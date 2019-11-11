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
%token T_ID T_INT T_FLOAT T_LATTER T_DIGIT T_INTEGER T_FLOATING T_MAINPROG T_FUNCTION T_PROCEDURE T_BEGIN T_END T_IF T_THEN T_ELSE T_NOP T_WHILE T_RETURN T_PRINT T_IN T_OPERATOR T_SEMICOLON T_PERIOD T_COMMA T_EQUAL T_LEFT_PARENTHESIS T_RIGHT_PARENTHESIS T_LEFT_BRACKET T_RIGHT_BRACKET T_COLON T_WHITESPACE T_COMMENT T_ELIF
%token T_NEWLINE T_QUIT
/*
%left T_PLUS T_MINUS
%left T_MULTIPLY T_DIVIDE
*/

%start prg

%%
prg:
        T_MAINPROG {printf("dsdfs"); exit(0);}
;
program_start:
        T_MAINPROG T_ID T_SEMICOLON declarations subprogram_declarations compound_statement

;
declarations:
        type identifier_list T_SEMICOLON declarations
        | T_WHITESPACE
        | 
;
identifier_list:
        T_ID
        | T_ID T_COMMA identifier_list
;
type:
        standard_type
        | standard_type T_LEFT_BRACKET T_DIGIT T_RIGHT_BRACKET
;
standard_type:
        T_INT
        | T_FLOAT
;
subprogram_declarations:
        subprogram_declaration subprogram_declarations
        | T_WHITESPACE
        | 
;
subprogram_declaration:
        subprogram_head declarations compound_statement
;
subprogram_head:
        T_FUNCTION T_ID arguments T_COLON standard_type T_SEMICOLON
        | T_PROCEDURE T_ID arguments T_SEMICOLON
;
arguments:
        T_LEFT_PARENTHESIS parameter_list T_RIGHT_PARENTHESIS
        | T_WHITESPACE
        |
;
parameter_list:
        identifier_list T_COLON type
        | identifier_list T_COLON type T_SEMICOLON parameter_list
;
compound_statement:
        T_BEGIN statement_list T_END
;
statement_list:
        statement
        | statement T_SEMICOLON statement_list
;
statement:
        variable T_EQUAL expression
        | print_statement
        | procedure_statement 
        | compound_statement 
        | if_statement 
        | while_statement
        | for_statement 
        | T_RETURN expression 
        | T_NOP
;
if_statement:
        "if" expression ":" statement 
        | "if" expression ":" statement else_if_statement
        | "if" expression ":" "else" ":" expression
        | "if" expression ":" statement else_if_statement "else" ":" expression
;
else_if_statement:
        "elif" expression ":" statement
        | "elif" expression ":" statement else_if_statement
;
while_statement:
         "while" expression ":" statement
        | "while" expression ":" statement "else" ":" statement
;
for_statement:
         "for" expression "in" expression ":" statement
        | "for" expression "in" expression ":" statement "else" ":" statement
;
print_statement:
        "print" 
        | "print" "(" expression ")"
;
variable:
        T_ID 
        | T_ID "[" expression "]"
;
procedure_statement:
        T_ID "(" actual_parameter_expression ")"
;
actual_parameter_expression:
        T_WHITESPACE | expression_list |
;
expression_list:
        expression | expression "," expression_list
;
expression:
        simple_expression | simple_expression relop simple_expression
;
simple_expression:
        term | term addop simple_expression
;
/* NOTE THE ABOVE GRAMMAR HAS BEEN CHANGED */
term:
        factor | factor multop term
;
factor: 
        T_INTEGER 
        | T_FLOATING 
        | variable 
        | procedure_statement 
        | "!" factor 
        | sign factor
;
/* NOTE THE ABOVE GRAMMAR HAS BEEN CHANGED */
sign:
        "+" 
        | "-" 
;
relop:
        ">" 
        | ">=" 
        | "<" 
        | "<=" 
        | "==" 
        | "!=" 
        | "in"
;
addop:
        "+" 
        | "-"
;
multop:
        "*"
        | "/"
;
%%

int main(int argc, char* argv[]) {
	yyin = fopen("test", "r");

	while(!feof(yyin)) {
		yyparse();
	}

	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}