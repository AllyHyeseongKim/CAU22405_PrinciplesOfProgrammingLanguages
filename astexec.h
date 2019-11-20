#ifndef ASTEXEC_H
#define ASTEXEC_H

typedef enum {UNKOWN, FLOAT, INT, FUNCTION, PROCEDURE} TYPE;
typedef int STACK_PLACE;
typedef int LENTH;
typedef union {
        int i;
        float f;
} block;

void make_id(int var_name, TYPE varType, int varIndex);
float get_var_val(int var_name, int varIndex);
void assign_var(int var_name, float val, int varIndex);
void print_val(float num);

int var_map[10000][2];
// std::unordered_map<std::string, std::pair<STACK_PLACE, LENTH> >  var_map;
block mem_stack[100][2];
// std::vector<std::pair<TYPE, block> > mem_stack;


struct AstElement;
struct ExecEnviron;

/* creates the execution engine */
struct ExecEnviron* createEnv();

/* removes the ExecEnviron */
void freeEnv(struct ExecEnviron* e);

/* executes an AST */
void execAst(struct ExecEnviron* e, struct AstElement* a);

#endif