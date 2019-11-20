#ifndef ASTGEN_H
#define ASTGEN_H

static int stackSize = 0;

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

int var_map[5381][2];
// std::unordered_map<std::string, std::pair<STACK_PLACE, LENTH> >  var_map;
block mem_stack[100][2];
// std::vector<std::pair<TYPE, block> > mem_stack;


struct AstElement
{
    enum {ekId, ekNumber, ekBinExpression, ekAssignment, ekWhile, ekCall, ekStatements, ekLastElement} kind;
    union
    {
        float val;
        int name;
        struct
        {
            struct AstElement *left, *right;
            char op;
        }expression;
        struct
        {
            int name;
            struct AstElement* right;
        }assignment;
        struct
        {
            int count;
            struct AstElement** statements;
        }statements;
        struct
        {
            struct AstElement* cond;
            struct AstElement* statements;
        } whileStmt;
        struct
        {
            int name;
            struct AstElement* param;
        }call;
    } data;
};

struct AstElement* makeAssignment(int name, struct AstElement* val);
struct AstElement* makeExpByNum(float val);
struct AstElement* makeExpByName(int name);
struct AstElement* makeExp(struct AstElement* left, struct AstElement* right, char op);
struct AstElement* makeStatement(struct AstElement* dest, struct AstElement* toAppend);
struct AstElement* makeWhile(struct AstElement* cond, struct AstElement* exec);
struct AstElement* makeCall(int name, struct AstElement* param);
#endif