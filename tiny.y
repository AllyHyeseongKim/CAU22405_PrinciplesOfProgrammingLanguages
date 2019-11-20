%{
#include "astgen.h"
#include "astexec.h"
#include <stdio.h>
#include <stdlib.h>
#define YYPARSE_PARAM astDest

extern int yylex();
extern int yyparse();
extern FILE* yyin;

int varIndex = 0;
TYPE varType;

void yyerror(const char* s);
%}

%union {
	int ival;
	float fval;
        char cval;
        char sval[100];
        struct AstElement* ast;
}

%token<ival> T_INTEGER T_ID
%token<fval> T_FLOATING

%token<cval> T_PLUS T_MINUS T_MULTIPLE T_DIVIDE 
%token T_SMALLER T_EQUAL T_NOT_EQUAL T_ASSIGN T_SMALLER_EQUAL T_LARGER_EQUAL T_LARGER
%token<sval> T_INT T_FLOAT T_NONE T_LATTER 
%token T_NEWLINE T_QUIT
%token T_MAINPROG T_FUNCTION T_PROCEDURE T_BEGIN T_END T_IF T_THEN 
%token T_ELSE T_NOP T_WHILE T_RETURN T_PRINT T_IN T_OPERATOR T_SEMICOLON 
%token T_PERIOD T_COMMA T_LEFT_PARENTHESIS T_RIGHT_PARENTHESIS T_FOR
%token<cval> T_LEFT_BRACKET T_RIGHT_BRACKET T_COLON T_COMMENT T_ELIF T_NOT 

%left T_PLUS T_MINUS
%left T_MULTIPLE T_DIVIDE

%type<ast> procedure_statement statement compound_statement statement_list while_statement
%type<ast> term factor simple_expression expression print_statement if_statement
%type<ival> variable identifier_list standard_type type

%start program_start

%%
program_start:
        | T_MAINPROG T_ID T_SEMICOLON declarations subprogram_declarations compound_statement T_SEMICOLON   { (*(struct AstElement**)astDest) = $6; }

;
declarations:
        type identifier_list T_SEMICOLON declarations                                           {}
        |                                                                                       {} 
;
identifier_list:
        T_ID                                                                                    {;$$ = 1; make_id($1, varType, varIndex); }
        | T_ID T_COMMA identifier_list                                                          {$$ = $3 + 1; make_id($1, varType, varIndex);}
;
type:
        standard_type                                                                           {varIndex = 1; varType = (TYPE)$1}
        | standard_type T_LEFT_BRACKET T_INTEGER T_RIGHT_BRACKET                                {varIndex = $3; varType = (TYPE)$1}
;
standard_type:
        T_INT                                                                                   {$$ = INT}
        | T_FLOAT                                                                               {$$ = FLOAT;}
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
        T_BEGIN statement_list T_END                                                            {$$ = $2;}
;
statement_list:                                                                                 {$$=0;}
        | statement_list statement T_SEMICOLON                                                  {$$ = makeStatement($1, $2);}      
;
statement:
        variable T_ASSIGN expression                                                            {$$ = makeAssignment($1, varIndex, $3);}
        | print_statement                                                                       {}
        | procedure_statement                                                                   {} 
        | compound_statement                                                                    {$$ = $1}
        | if_statement                                                                          {$$ = $1}
        | while_statement                                                                       {$$ = $1}
        | for_statement 
        | T_RETURN expression                                                                   {} 
        | T_NOP                                                                                 {$$ = 0}
;
if_statement:
        T_IF expression T_COLON statement T_SEMICOLON T_ELSE T_COLON statement                  {$$ = makeIfElse($2, $4, $8)}
        | T_IF expression T_COLON statement else_if_statement                                   {}
        | T_IF expression T_COLON statement else_if_statement T_ELSE T_COLON statement          {}
        | T_IF expression T_COLON statement                                                     {}
;
else_if_statement:
        T_ELIF expression T_COLON statement                                                     {}
        | T_ELIF expression T_COLON statement else_if_statement                                 {}
;
while_statement:
         T_WHILE expression T_COLON statement                                                   {$$ = makeWhile($2, $4);}
        | T_WHILE expression T_COLON statement T_ELSE T_COLON statement                         {}
;
for_statement:
         T_FOR expression T_IN expression T_COLON statement
        | T_FOR expression T_IN expression T_COLON statement T_ELSE T_COLON statement 
;
print_statement:
        T_PRINT                                                                                 {}
        | T_PRINT T_LEFT_PARENTHESIS expression T_RIGHT_PARENTHESIS                             {$$ = makeCall("print", $3);}
;
variable:
        T_ID                                                                                    {$$ = $1; varIndex = 0;}
        | T_ID T_LEFT_BRACKET expression T_RIGHT_BRACKET                                        {$$ = $1; varIndex = (int)$3->data.val;}
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
        simple_expression                                                                       {$$ = $1}
        | simple_expression T_LARGER simple_expression                                          {$$ = makeExp($1, $3, '>');}
        | simple_expression T_LARGER_EQUAL simple_expression                                    // {$$ = ($1 >= $3)? 1: 0}
        | simple_expression T_SMALLER simple_expression                                         {$$ = makeExp($1, $3, '<');}
        | simple_expression T_SMALLER_EQUAL simple_expression                                   // {$$ = ($1 <= $3)? 1: 0}
        | simple_expression T_EQUAL simple_expression                                           // {$$ = ($1 == $3)? 1: 0}
        | simple_expression T_NOT_EQUAL simple_expression                                       // {$$ = ($1 != $3)? 1: 0}
        | simple_expression T_IN simple_expression                                              {}
;
simple_expression:
        term                                                                                    {$$ = $1;}
        | term T_PLUS simple_expression                                                         {$$ = makeExp($1, $3, '+');}
        | term T_MINUS simple_expression                                                        {$$ = makeExp($1, $3, '-');}
;
/* NOTE THE ABOVE GRAMMAR HAS BEEN CHANGED */
term:
        factor                                                                                  {$$ = $1}
        | factor T_MULTIPLE term                                                                {$$ = makeExp($1, $3, '*');}
        | factor T_DIVIDE term                                                                  {$$ = makeExp($1, $3, '/');}
;
factor: 
        T_INTEGER                                                                               {$$ = makeExpByNum($1)}
        | T_FLOATING                                                                            {$$ = makeExpByNum($1)}
        | variable                                                                              {$$ = makeExpByName($1, varIndex);}
        | procedure_statement                                                                   {}
        | T_NOT factor                                                                         // {$$ = ($1) ? $1 : 0}
        | T_PLUS factor                                                                        // {$$ = $2}
        | T_MINUS factor                                                                       // {$$ = -$2}
;

%%

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
	exit(1);
}



