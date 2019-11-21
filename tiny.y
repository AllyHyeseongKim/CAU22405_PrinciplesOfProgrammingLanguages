%{
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

%left T_LARGER T_LARGER_EQUAL T_SMALLER T_SMALLER_EQUAL T_EQUAL T_NOT_EQUAL
%left T_PLUS T_MINUS
%left T_MULTIPLE T_DIVIDE

%type<ast> parameter_list actual_parameter_expression expression_list for_condition other_statment match_statement unmatch_statement
%type<ast> procedure_statement statement compound_statement statement_list identifier_list declarations arguments subprogram_head
%type<ast> term factor simple_expression expression print_statement subprogram_declarations subprogram_declaration
%type<ival> variable standard_type type
// %type<ast> else_if_statement if_statement while_statement for_statement
%start program_start

%%
program_start:
        | T_MAINPROG T_ID T_SEMICOLON declarations subprogram_declarations compound_statement   { make_id(0, 0, 1);(*(struct AstElement**)astDest) = combineStatement($4, $6);}
        | T_MAINPROG T_ID error declarations subprogram_declarations compound_statement     {printf("No semicolon"); (*(struct AstElement**)astDest) = combineStatement($4, $6);}

;
declarations:
        type identifier_list T_SEMICOLON declarations                                           {$$ = combineStatement($2, $4);}                                          
        |                                                                                       {$$ = 0}
;
identifier_list:
        T_ID                                                                                    {$$ = makeStatement(makeVariable($1, varType, varIndex), 0); argSize += varIndex;}
        | T_ID T_COMMA identifier_list                                                          {$$ = makeStatement(makeVariable($1, varType, varIndex), $3); argSize += varIndex;}
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
        subprogram_declaration subprogram_declarations                                          {$$ = combineStatement($1, $2)}
        |                                                                                       { $$ = makeNop()}
;
subprogram_declaration:
        subprogram_head declarations compound_statement                                         {$$ = sub_program_map[subName] = makeStatement(makeCompoundStmt(combineStatement($1, combineStatement($2, $3))), 0)}
;
subprogram_head:
        T_FUNCTION T_ID arguments T_COLON standard_type T_SEMICOLON                             {$$ = $3; varType=FUNCTION; subName=$2;}
        | T_PROCEDURE T_ID arguments T_SEMICOLON                                                {$$ = $3; varType=PROCEDURE; subName=$2;}
;
arguments:
        T_LEFT_PARENTHESIS parameter_list T_RIGHT_PARENTHESIS                                   {$$ = $2}
        | T_LEFT_PARENTHESIS T_RIGHT_PARENTHESIS                                                {$$ = 0; argSize=0;}
;
parameter_list:
        type T_COLON identifier_list                                                            {$$ = $3}
        | type T_COLON identifier_list T_SEMICOLON parameter_list                               {$$ = combineStatement($3, $5);}
;
compound_statement:
        T_BEGIN statement_list T_END                                                            {$$ = makeStatement(makeCompoundStmt($2), 0)}
;
statement_list:
        statement                                                                               {$$ = makeStatement($1, 0);}
        | statement T_SEMICOLON statement_list                                                  {$$ = makeStatement($1, $3);}      
;
statement:
        match_statement                                                                         {$$ = $1}
        | unmatch_statement                                                                     {$$ = $1}
;
match_statement:
        other_statment                                                                          {$$ = $1}
        | T_IF expression T_COLON match_statement T_ELSE T_COLON match_statement                {$$ = makeIfElse($2, $4, $7)} 
        | T_WHILE expression T_COLON match_statement T_ELSE T_COLON match_statement             {$$ = makeIfElse($2, makeWhile($2, $4), $7)}
        | T_FOR for_condition T_COLON match_statement T_ELSE T_COLON match_statement            {$$ = makeIfElse($2, makeFor($2, $4), $7)}
;
unmatch_statement:
        T_IF expression T_COLON statement                                                       {$$ = makeIfElse($2, $4, makeNop())}
        | T_IF expression T_COLON match_statement T_ELSE T_COLON unmatch_statement              {$$ = makeIfElse($2, $4, $7)}
        | T_WHILE expression T_COLON statement                                                  {$$ = makeWhile($2, $4);}
        | T_FOR for_condition T_COLON statement                                                 {$$ = makeFor($2, $4)}
;
other_statment:
        variable T_ASSIGN expression                                                            {$$ = makeAssignment($1, varIndex, $3);}
        | print_statement                                                                       {$$ = $1}
        | procedure_statement                                                                   {$$ = $1} 
        | compound_statement                                                                    {$$ = $1}
        // | if_statement                                                                          {$$ = $1}
        // | while_statement                                                                       {$$ = $1}
        // | for_statement                                                                         {$$ = $1}
        | T_RETURN expression                                                                   {$$ = makeAssignmentByAddress($2);} 
        | T_NOP                                                                                 {$$ = makeNop()}
;
// if_statement:
//         T_IF expression T_COLON statement                                                       {$$ = makeIfElse($2, $4, makeNop())}
//         | T_IF expression T_COLON statement T_ELSE T_COLON statement                            {$$ = makeIfElse($2, $4, $7)}
//         | T_IF expression T_COLON statement else_if_statement                                   {$$ = makeIfElse($2, $4, $5)}
// ;
// else_if_statement:
//         T_ELIF expression T_COLON statement                                                     {$$ = makeIfElse($2, $4, makeNop())}
//         | T_ELIF expression T_COLON statement T_ELSE T_COLON statement                          {$$ = makeIfElse($2, $4, $7)}
//         | T_ELIF expression T_COLON statement else_if_statement                                 {$$ = makeIfElse($2, $4, $5)}
// ;
// while_statement:
//          T_WHILE expression T_COLON statement                                                   {$$ = makeWhile($2, $4);}
//         | T_WHILE expression T_COLON statement T_ELSE T_COLON statement                         {$$ = makeIfElse($2, makeWhile($2, $4), $7)}
// ;
// for_statement:
//          T_FOR for_condition T_COLON statement                                                  {$$ = makeFor($2, $4)}
//         | T_FOR for_condition T_COLON statement T_ELSE T_COLON statement                        {$$ = makeIfElse($2, makeFor($2, $4), $7)}
// ;
for_condition:
        variable T_IN variable                                                                  {$$ = makeForCondition($1, $3)}
;
print_statement:
        T_PRINT                                                                                 {$$ = makeNop()}
        | T_PRINT T_LEFT_PARENTHESIS expression T_RIGHT_PARENTHESIS                             {$$ = makeCall("print", $3);}
;
variable:
        T_ID                                                                                    {$$ = $1; varIndex = 0;}
        | T_ID T_LEFT_BRACKET expression T_RIGHT_BRACKET                                        {$$ = $1; }
;
procedure_statement:
        T_ID T_LEFT_PARENTHESIS actual_parameter_expression T_RIGHT_PARENTHESIS                 {$$ = makeProcedure($1, $3)}
;
actual_parameter_expression:
        expression_list                                                                         {$$ = $1; }
        |                                                                                       {$$ = makeParameters(0, 0)}
;
expression_list:
        expression                                                                              {$$ = makeParameters($1, 0); }
        | expression T_COMMA expression_list                                                    {$$ = makeParameters($1, $3);}
;
expression:
        simple_expression                                                                       {$$ = makeExp($1, makeExpByNum(0), '+')}
        | simple_expression T_LARGER simple_expression                                          {$$ = makeExp($1, $3, '>');}
        | simple_expression T_LARGER_EQUAL simple_expression                                    {$$ = makeExp($1, $3, '1');}
        | simple_expression T_SMALLER simple_expression                                         {$$ = makeExp($1, $3, '<');}
        | simple_expression T_SMALLER_EQUAL simple_expression                                   {$$ = makeExp($1, $3, '2');}
        | simple_expression T_EQUAL simple_expression                                           {$$ = makeExp($1, $3, '=');}
        | simple_expression T_NOT_EQUAL simple_expression                                       {$$ = makeExp($1, $3, '!');}
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
        T_INTEGER                                                                               {$$ = makeExpByNum($1); varIndex = $1;}
        | T_FLOATING                                                                            {$$ = makeExpByNum($1)}
        | variable                                                                              {$$ = makeExpByName($1, varIndex);}
        | procedure_statement                                                                   {$$ = makeExpByAddress(makeStatement($1, 0));}
        | T_NOT factor                                                                          {$$ = ($2->data.val) ? $2 : makeExpByNum(0)}
        | T_PLUS factor                                                                         {$$ = makeExp(makeExpByNum(0), $2, '+')}
        | T_MINUS factor                                                                        {$$ = makeExp(makeExpByNum(0), $2, '-')}
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
}



