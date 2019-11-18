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
%token T_PLUS T_MINUS T_MULTIPLE T_DIVIDE T_SMALLER_EQUAL T_LARGER_EQUAL T_LARGER
%token T_SMALLER T_EQUAL T_NOT_EQUAL T_ASSIGN
%token T_ID T_INT T_FLOAT T_NONE T_LATTER T_DIGIT T_INTEGER T_FLOATING 
%token T_NEWLINE T_QUIT
%token T_MAINPROG T_FUNCTION T_PROCEDURE T_BEGIN T_END T_IF T_THEN 
%token T_ELSE T_NOP T_WHILE T_RETURN T_PRINT T_IN T_OPERATOR T_SEMICOLON 
%token T_PERIOD T_COMMA T_LEFT_PARENTHESIS T_RIGHT_PARENTHESIS T_FOR
%token T_LEFT_BRACKET T_RIGHT_BRACKET T_COLON T_COMMENT T_ELIF T_NOT 
/*
%left T_PLUS T_MINUS
%left T_MULTIPLY T_DIVIDE
*/

%start for_statement

%%
program_start:
        | T_MAINPROG T_ID T_SEMICOLON declarations subprogram_declarations compound_statement   {}

;
declarations:
        type identifier_list T_SEMICOLON declarations                                           {}
        |                                                                                       {} 
;
identifier_list:
        T_ID                                                                                    {}
        | T_ID T_COMMA identifier_list                                                          {}
;
type:
        standard_type                                                                           {}
        | standard_type T_LEFT_BRACKET T_DIGIT T_RIGHT_BRACKET                                  {}
;
standard_type:
        T_INT                                                                                   {}
        | T_FLOAT                                                                               {}
;
subprogram_declarations:
        subprogram_declaration subprogram_declarations                                          {}
        | 
;
subprogram_declaration:
        subprogram_head declarations compound_statement                                         {}
;
subprogram_head:
        T_FUNCTION T_ID arguments T_COLON standard_type T_SEMICOLON                             {}
        | T_PROCEDURE T_ID arguments T_SEMICOLON                                                {}
;
arguments:
        T_LEFT_PARENTHESIS parameter_list T_RIGHT_PARENTHESIS                                   {}
        |                                                                                       {}
;
parameter_list:
        identifier_list T_COLON type                                                            {}
        | identifier_list T_COLON type T_SEMICOLON parameter_list                               {}
;
compound_statement:
        T_BEGIN statement_list T_END                                                            {}
;
statement_list:
        statement                                                                               {}
        | statement T_SEMICOLON statement_list                                                  {}
;
statement:
        variable T_ASSIGN expression                                                            {}
        | print_statement                                                                       {}
        | procedure_statement                                                                   {} 
        | compound_statement                                                                    {}
        | if_statement                                                                          {}
        | while_statement                                                                       {}
        | for_statement 
        | T_RETURN expression                                                                   {} 
        | T_NOP                                                                                 {}
;
if_statement:
        T_IF expression T_COLON statement                                                       {} 
        | T_IF expression T_COLON statement else_if_statement                                   {}
        | T_IF expression T_COLON statement T_ELSE T_COLON statement                            {}
        | T_IF expression T_COLON statement else_if_statement T_ELSE T_COLON statement          {}
;
else_if_statement:
        T_ELIF expression T_COLON statement                                                     {}
        | T_ELIF expression T_COLON statement else_if_statement                                 {}
;
while_statement:
         T_WHILE expression T_COLON statement                                                   {}
        | T_WHILE expression T_COLON statement T_ELSE T_COLON statement                         {}
;
for_statement:
         T_FOR expression T_IN expression T_COLON statement
        | T_FOR expression T_IN expression T_COLON statement T_ELSE T_COLON statement 
;
print_statement:
        T_PRINT                                                                                 {}
        | T_PRINT T_LEFT_PARENTHESIS expression T_RIGHT_PARENTHESIS                             {}
;
variable:
        T_ID                                                                                    {}
        | T_ID T_LEFT_BRACKET expression T_RIGHT_BRACKET                                        {}
;
procedure_statement:
        T_ID T_LEFT_PARENTHESIS actual_parameter_expression T_RIGHT_PARENTHESIS                 {}
;
actual_parameter_expression:
        expression_list                                                                         {}
        |                                                                                       {}
;
expression_list:
        expression                                                                              {}
        | expression T_COMMA expression_list                                                    {}
;
expression:
        simple_expression                                                                       {}
        | simple_expression relop simple_expression                                             {}
;
simple_expression:
        term                                                                                    {;}
        | term addop simple_expression                                                          {}
;
/* NOTE THE ABOVE GRAMMAR HAS BEEN CHANGED */
term:
        factor | factor multop term                                                             {}
;
factor: 
        T_INTEGER                                                                               {}
        | T_FLOATING                                                                            {}
        | variable                                                                              {}
        | procedure_statement 
        | T_NOT factor                                                                          {}
        | sign factor                                                                           {}
;
/* NOTE THE ABOVE GRAMMAR HAS BEEN CHANGED */
sign:
        T_PLUS                                                                                  {}
        | T_MINUS                                                                               {}
;
relop:
        T_LARGER                                                                                {}
        | T_LARGER_EQUAL                                                                        {}
        | T_SMALLER                                                                             {}
        | T_SMALLER_EQUAL                                                                       {}
        | T_EQUAL                                                                               {}
        | T_NOT_EQUAL                                                                           {}
        | T_IN                                                                                  {}
;
addop:
        T_PLUS                                                                                  {}
        | T_MINUS                                                                               {}
;
multop:
        T_MULTIPLE                                                                              {}
        | T_DIVIDE                                                                              {}
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