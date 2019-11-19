%{

#include <iostream>
#include <unordered_map>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <utility>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

typedef enum {UNKOWN, FLOAT, INT, FUNCTION, PROCEDURE} TYPE;
typedef int STACK_PLACE;
typedef int LENTH;
typedef union {
        int i;
        float f;
} block;

std::unordered_map<std::string, std::pair<STACK_PLACE, LENTH> >  var_map;
std::vector<std::pair<TYPE, block> > mem_stack;
int stack_frame = 0;
int var_index = 0;
TYPE var_type;
int if_bool;



void yyerror(const char* s);
%}

%union {
	int ival;
	float fval;
        char cval;
        char sval[100];
}

%token<ival> T_INTEGER
%token<fval> T_FLOATING

%token<cval> T_PLUS T_MINUS T_MULTIPLE T_DIVIDE 
%token T_SMALLER T_EQUAL T_NOT_EQUAL T_ASSIGN T_SMALLER_EQUAL T_LARGER_EQUAL T_LARGER
%token<sval> T_ID T_INT T_FLOAT T_NONE T_LATTER 
%token T_NEWLINE T_QUIT
%token T_MAINPROG T_FUNCTION T_PROCEDURE T_BEGIN T_END T_IF T_THEN 
%token T_ELSE T_NOP T_WHILE T_RETURN T_PRINT T_IN T_OPERATOR T_SEMICOLON 
%token T_PERIOD T_COMMA T_LEFT_PARENTHESIS T_RIGHT_PARENTHESIS T_FOR
%token<cval> T_LEFT_BRACKET T_RIGHT_BRACKET T_COLON T_COMMENT T_ELIF T_NOT 

%left T_PLUS T_MINUS
%left T_MULTIPLE T_DIVIDE

%type<fval> term factor simple_expression expression procedure_statement statement
%type<sval> variable
%type<ival> identifier_list standard_type type

%start program_start

%%
program_start:
        | T_MAINPROG T_ID T_SEMICOLON declarations subprogram_declarations compound_statement   {}

;
declarations:
        type identifier_list T_SEMICOLON declarations                                           {}
        |                                                                                       {} 
;
identifier_list:
        T_ID {
                $$ = 1;
                var_map[$1] = std::make_pair(mem_stack.size(), var_index);
                block b = {0};
                for(int i = 0; i < var_index; i++)
                        mem_stack.push_back(std::make_pair(var_type, b));
        }
        | T_ID T_COMMA identifier_list {
                $$ = $3 + 1;
                var_map[$1] = std::make_pair(mem_stack.size(), var_index);
                block b = {0};
                for(int i = 0; i < var_index; i++)
                        mem_stack.push_back(std::make_pair(var_type, b));
        }
;
type:
        standard_type                                                                           {var_index = 1; var_type = (TYPE)$1}
        | standard_type T_LEFT_BRACKET T_INTEGER T_RIGHT_BRACKET                                {var_index = $3; var_type = (TYPE)$1}
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
        T_BEGIN statement_list T_END                                                            {}
;
statement_list:
        statement                                                                               {}
        | statement T_SEMICOLON statement_list                                                  {}
;
statement:
        variable T_ASSIGN expression {
                if(mem_stack[var_map[$1].first].first == INT)
                        mem_stack[var_map[$1].first + var_index].second.i = (int)$3;
                else
                        mem_stack[var_map[$1].first + var_index].second.f = (float)$3;
        }
        | print_statement                                                                       {}
        | procedure_statement                                                                   {} 
        | compound_statement                                                                    {}
        | if_statement                                                                          {}
        | while_statement                                                                       {}
        | for_statement 
        | T_RETURN expression                                                                   {$$ = $1} 
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
        | T_PRINT T_LEFT_PARENTHESIS expression T_RIGHT_PARENTHESIS                             {printf("%f\n", $3);}
;
variable:
        T_ID                                                                                    {strcpy($$, $1); var_index = 0;}
        | T_ID T_LEFT_BRACKET expression T_RIGHT_BRACKET                                        {strcpy($$, $1); var_index = (int)$3;}
;
procedure_statement:
        T_ID T_LEFT_PARENTHESIS actual_parameter_expression T_RIGHT_PARENTHESIS {
                var_map[$1] = std::make_pair(mem_stack.size() - 1, PROCEDURE);
        }
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
        | simple_expression T_LARGER simple_expression                                          {$$ = ($1 > $3)? 1: 0}
        | simple_expression T_LARGER_EQUAL simple_expression                                    {$$ = ($1 >= $3)? 1: 0}
        | simple_expression T_SMALLER simple_expression                                         {$$ = ($1 < $3)? 1: 0}
        | simple_expression T_SMALLER_EQUAL simple_expression                                   {$$ = ($1 <= $3)? 1: 0}
        | simple_expression T_EQUAL simple_expression                                           {$$ = ($1 == $3)? 1: 0}
        | simple_expression T_NOT_EQUAL simple_expression                                       {$$ = ($1 != $3)? 1: 0}
        | simple_expression T_IN simple_expression                                              {}
;
simple_expression:
        term                                                                                    {$$ = $1;}
        | term T_PLUS simple_expression                                                         {$$ = $1 + $3}
        | term T_MINUS simple_expression                                                        {$$ = $1 - $3;}
;
/* NOTE THE ABOVE GRAMMAR HAS BEEN CHANGED */
term:
        factor                                                                                  {$$ = $1}
        | factor T_MULTIPLE term                                                                {$$ = $1 * $3}
        | factor T_DIVIDE term                                                                  {$$ = $1 / $3}
;
factor: 
        T_INTEGER                                                                               {$$ = $1}
        | T_FLOATING                                                                            {$$ = $1}
        | variable {
                if(mem_stack[var_map[$1].first].first == INT)
                        $$ = (float)mem_stack[var_map[$1].first].second.i;
                else
                        $$ = (float)mem_stack[var_map[$1].first].second.f;
        }
        | procedure_statement                                                                   {}
        | T_NOT factor                                                                          {$$ = ($1) ? $1 : 0}
        | T_PLUS factor                                                                         {$$ = $2}
        | T_MINUS factor                                                                        {$$ = -$2}
;

%%

int main(int argc, char* argv[]) {
	yyin = fopen("test.tiny", "r");

	while(!feof(yyin)) {
		yyparse();
	}

	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}