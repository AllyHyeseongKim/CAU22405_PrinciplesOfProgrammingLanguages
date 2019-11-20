#include "astgen.h"
#include "astexec.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void make_id(int var_name, TYPE varType, int varIndex) {
        var_map[var_name][0] = stackSize;
        var_map[var_name][1] = varIndex;
        for(int i = 0; i < varIndex; i++) {
                mem_stack[stackSize][0].i = varType;
                mem_stack[stackSize][0].f = 0;
                stackSize++;
        }
}

float get_var_val(int var_name, int varIndex) {
        if(mem_stack[var_map[var_name][0]][0].i == INT) return (float)mem_stack[var_map[var_name][0] + varIndex][1].i;
        else return (float)mem_stack[var_map[var_name][0] + varIndex][1].f;
}

void assign_var(int var_name, float val, int varIndex) {
        if(mem_stack[var_map[var_name][0]][0].i == INT) mem_stack[var_map[var_name][0] + varIndex][1].i = (int)val;
        else mem_stack[var_map[var_name][0] + varIndex][1].f = (float)val;
}

void print_val(float num) {
        printf("%.4f", num);
}


static void* checkAlloc(size_t sz)
{
    void* result = calloc(sz, 1);
    if(!result)
    {
        fprintf(stderr, "alloc failed\n");
        exit(1);
    }
}

struct AstElement* makeAssignment(int name, struct AstElement* val)
{
    struct AstElement* result = checkAlloc(sizeof(*result));
    result->kind = ekAssignment;
    result->data.assignment.name = name;
    result->data.assignment.right = val;
    return result;
}

struct AstElement* makeExpByNum(float val)
{
    struct AstElement* result = checkAlloc(sizeof(*result));
    result->kind = ekNumber;
    result->data.val = val;
    return result;
}

struct AstElement* makeExpByName(int name)
{
    struct AstElement* result = checkAlloc(sizeof(*result));
    result->kind = ekId;
    result->data.name = name;
    return result;
}

struct AstElement* makeExp(struct AstElement* left, struct AstElement* right, char op)
{
    struct AstElement* result = checkAlloc(sizeof(*result));
    result->kind = ekBinExpression;
    result->data.expression.left = left;
    result->data.expression.right = right;
    result->data.expression.op = op;
    return result;
}

struct AstElement* makeStatement(struct AstElement* result, struct AstElement* toAppend)
{
    if(!result)
    {
        result = checkAlloc(sizeof(*result));
        result->kind = ekStatements;
        result->data.statements.count = 0;
        result->data.statements.statements = 0;
    }
    assert(ekStatements == result->kind);
    result->data.statements.count++;
    result->data.statements.statements = realloc(result->data.statements.statements, result->data.statements.count*sizeof(*result->data.statements.statements));
    result->data.statements.statements[result->data.statements.count-1] = toAppend;
    return result;
}

struct AstElement* makeWhile(struct AstElement* cond, struct AstElement* exec)
{
    struct AstElement* result = checkAlloc(sizeof(*result));
    result->kind = ekWhile;
    result->data.whileStmt.cond = cond;
    result->data.whileStmt.statements = exec;
    return result;
}

struct AstElement* makeCall(int name, struct AstElement* param)
{
    struct AstElement* result = checkAlloc(sizeof(*result));
    result->kind = ekCall;
    result->data.call.name = name;
    result->data.call.param = param;
    return result;
}