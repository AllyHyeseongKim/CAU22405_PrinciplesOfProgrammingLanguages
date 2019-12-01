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
    if(!toAppend)
    {
        toAppend = checkAlloc(sizeof(*result));
        toAppend->kind = ekStatements;
        toAppend->data.statements.count = 0;
        toAppend->data.statements.statements = 0;
    }
    assert(ekStatements == toAppend->kind);

    struct AstElement* temp = checkAlloc(sizeof(*result));
    temp->kind = toAppend->kind;
    temp->data.statements.count = toAppend->data.statements.count;
    temp->data.statements.statements = checkAlloc(toAppend->data.statements.count*sizeof(*toAppend->data.statements.statements));
    for(int i = 0; i < toAppend->data.statements.count; i++)
        temp->data.statements.statements[i] = toAppend->data.statements.statements[i];

    toAppend->data.statements.count = toAppend->data.statements.count + 1;
    toAppend->data.statements.statements = realloc(toAppend->data.statements.statements, toAppend->data.statements.count*sizeof(*toAppend->data.statements.statements));
    toAppend->data.statements.statements[0] = result;
    for (int i = 0; i < temp->data.statements.count; i++)
        toAppend->data.statements.statements[i+1] = temp->data.statements.statements[i];
    free(temp->data.statements.statements);
    free(temp);
    return toAppend;
}

struct AstElement* combineStatement(struct AstElement* result, struct AstElement* toAppend) {
    if(!result)
    {
        result = checkAlloc(sizeof(*result));
        result->kind = ekStatements;
        result->data.statements.count = 0;
        result->data.statements.statements = 0;
    }
    if(!toAppend)
    {
        toAppend = checkAlloc(sizeof(*result));
        toAppend->kind = ekStatements;
        toAppend->data.statements.count = 0;
        toAppend->data.statements.statements = 0;
    }
    assert(result);
    assert(ekStatements == result->kind);
    assert(ekStatements == toAppend->kind);

    int init_size = result->data.statements.count;
    result->data.statements.count = result->data.statements.count + toAppend->data.statements.count;
    result->data.statements.statements = realloc(result->data.statements.statements, result->data.statements.count*sizeof(result->data.statements.statements));
    for(int i = 0; i < toAppend->data.statements.count; i++)
        result->data.statements.statements[i + init_size] = toAppend->data.statements.statements[i];
    
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
    result->kind = ekIf;
    result->data.ifStmt.cond = cond;
    result->data.ifStmt.if_statement = ifStmt;
    result->data.ifStmt.else_statement = elseStmt;
    
    return result;
}

struct AstElement* makeNop(){
    struct AstElement* result = checkAlloc(sizeof(*result));
    result->kind = ekNop;
    return result;
}

struct AstElement* makeVariable(int name, int type, int index){
    struct AstElement* result = checkAlloc(sizeof(*result));
    result->kind = ekVar;
    result->data.variable.name = name;
    result->data.variable.type = type;
    result->data.variable.index = index;
    return result;
}

struct AstElement* makeSemicolonError() {
    struct AstElement* result = checkAlloc(sizeof(*result));
    fprintf(stderr, "Missing Semicolon\n");
    exit(1);
    return result;
}

struct AstElement* makeMainProgError() {
    struct AstElement* result = checkAlloc(sizeof(*result));
    fprintf(stderr, "No mainprog declaration\n");
    exit(1);
    return result;
}

// struct AstElement* makeProcedure(int name, struct AstElement* parameter) {
struct AstElement* makeProcedure() {
    struct AstElement* result = checkAlloc(sizeof(*result));
    // result->kind = ekProcedure;
    // result->data.procedure.name = name;
    // result->data.procedure.parameter = parameter;
    fprintf(stderr, "This program does not accept function calls except 'print' with only one parameter\n");
    exit(1);
    return result;
}

struct AstElement* makeParameters(struct AstElement* dest, struct AstElement* toAppend){     
    if(!toAppend)
    {
        toAppend = checkAlloc(sizeof(*dest));
        toAppend->kind = ekParameter;
        toAppend->data.parameter.count = 0;
        toAppend->data.parameter.expressions = 0;
    }
    if(!dest)
    {
        dest = checkAlloc(sizeof(*dest));
        dest->kind = ekParameter;
        dest->data.parameter.count = 0;
        dest->data.parameter.expressions = 0;
        return dest;
    }
    assert(dest);
    assert(ekParameter == toAppend->kind);
    assert(ekBinExpression == dest->kind);

    struct AstElement* temp = checkAlloc(sizeof(*dest));
    temp->kind = dest->kind;
    temp->data.expression.left = dest->data.expression.left;
    temp->data.expression.op = dest->data.expression.op;
    temp->data.expression.right = dest->data.expression.right;

    dest->kind = ekParameter;
    dest->data.parameter.count = toAppend->data.parameter.count + 1;
    dest->data.parameter.expressions = checkAlloc(dest->data.parameter.count*sizeof(*toAppend->data.parameter.expressions));

    dest->data.parameter.expressions[0] = temp;
    for(int i = 0; i < toAppend->data.parameter.count; i++) {
        dest->data.parameter.expressions[i + 1] = toAppend->data.parameter.expressions[i];
    }

    return dest;   
}

struct AstElement* makeAssignmentByAddress(struct AstElement* val) {
    struct AstElement* result = checkAlloc(sizeof(*result));
    result->data.assignment_by_address.expression = val;
    result->kind = ekAssignAddress;

    return result;

}

struct AstElement* makeCompoundStmt(struct AstElement* stmt) {
    assert(stmt);
    assert(ekStatements == stmt->kind);
    struct AstElement* result = checkAlloc(sizeof(*result));
    result->data.compound.statement = stmt;
    result->kind = ekCompound;
    return result;
}

struct AstElement* makeExpByAddress(struct AstElement* procedure) {
    struct AstElement* result = checkAlloc(sizeof(*result));
    result->kind = ekExpAddress;
    result->data.expAddr.procedure = procedure;
    return result;
}

struct AstElement* makeForCondition(int left, int right) {
    struct AstElement* result = checkAlloc(sizeof(*result));
    result->kind = ekForCondition;
    result->data.for_condition.left_var = left;
    result->data.for_condition.right_var = right; 
    result->data.for_condition.num_call = 0; 
    return result;
}

struct AstElement* makeFor(struct AstElement* cond, struct AstElement* exec) {
    struct AstElement* result = checkAlloc(sizeof(*result));
    result->kind = ekFor;
    result->data.whileStmt.cond = cond;
    result->data.whileStmt.statements = exec;
    return result;
}