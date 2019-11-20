#include "astgen.h"
#include "astexec.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


static void* checkAlloc(size_t sz)
{
    void* result = calloc(sz, 1);
    if(!result)
    {
        fprintf(stderr, "alloc failed\n");
        exit(1);
    }
    return result;
}

struct AstElement* makeAssignment(int name, int index, struct AstElement* val)
{
    struct AstElement* result = checkAlloc(sizeof(*result));
    result->kind = ekAssignment;
    result->data.assignment.name = name;
    result->data.assignment.right = val;
    result->data.assignment.index = index;
    return result;
}

struct AstElement* makeExpByNum(float val)
{
    struct AstElement* result = checkAlloc(sizeof(*result));
    result->kind = ekNumber;
    result->data.val = val;
    return result;
}

struct AstElement* makeExpByName(int name, int index)
{
    struct AstElement* result = checkAlloc(sizeof(*result));
    result->kind = ekId;
    result->data.name[0] = name;
    result->data.name[1] = index;
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

struct AstElement* makeCall(char* name, struct AstElement* param)
{
    struct AstElement* result = checkAlloc(sizeof(*result));
    result->kind = ekCall;
    result->data.call.name = name;
    result->data.call.param = param;
    return result;
}

struct AstElement* makeIfElse(struct AstElement* cond, struct AstElement* ifStmt, struct AstElement* elseStmt) {
    struct AstElement* result = checkAlloc(sizeof(*result));
    puts("sdfasdf");
    result->kind = ekIf;
    result->data.ifStmt.cond = cond;
    result->data.ifStmt.if_statement = ifStmt;
    result->data.ifStmt.else_statement = elseStmt;
    
    return result;
}