#include "astexec.h"
#include "astgen.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>



int stackSize = 0;


void make_id(int var_name, TYPE varType, int varIndex) {
        for(int i = 0; i < varIndex; i++) {
                var_map[var_name + i][0] = stackSize;
                var_map[var_name + i][1] = varIndex - i;
                mem_stack[stackSize][0].i = varType;
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


struct ExecEnviron
{
    float x; /* The value of the x variable, a real language would have some name->value lookup table instead */
};

static float execTermExpression(struct ExecEnviron* e, struct AstElement* a);
static float execBinExp(struct ExecEnviron* e, struct AstElement* a);
static void execAssign(struct ExecEnviron* e, struct AstElement* a);
static void execWhile(struct ExecEnviron* e, struct AstElement* a);
static void execCall(struct ExecEnviron* e, struct AstElement* a);
static void execStmt(struct ExecEnviron* e, struct AstElement* a);
static void execIf(struct ExecEnviron* e, struct AstElement* a);
static void execNop(struct ExecEnviron* e, struct AstElement* a);
static void execVar(struct ExecEnviron* e, struct AstElement* a);
static void execProcedure(struct ExecEnviron* e, struct AstElement* a);

/* Lookup Array for AST elements which yields values */
static float(*valExecs[])(struct ExecEnviron* e, struct AstElement* a) =
{
    execTermExpression,
    execTermExpression,
    execBinExp,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

/* lookup array for non-value AST elements */
static void(*runExecs[])(struct ExecEnviron* e, struct AstElement* a) =
{
    NULL, /* ID and numbers are canonical and */
    NULL, /* don't need to be executed */
    NULL, /* a binary expression is not executed */
    execAssign,
    execWhile,
    execCall,
    execStmt,
    execIf,
    execNop,
    execVar,
    execProcedure
};

/* Dispatches any value expression */
static float dispatchExpression(struct ExecEnviron* e, struct AstElement* a)
{
    assert(a);
    assert(valExecs[a->kind]);
    return valExecs[a->kind](e, a);
}

static void dispatchStatement(struct ExecEnviron* e, struct AstElement* a)
{
    assert(a);
    assert(runExecs[a->kind]);
    runExecs[a->kind](e, a);
}

static void onlyName(const char* name, const char* reference, const char* kind)
{
    if(strcmp(reference, name))
    {
        fprintf(stderr,
            "This language knows only the %s '%s', not '%s'\n",
            kind, reference, name);
        exit(1);
    }
}

static void onlyPrint(const char* name)
{
    onlyName(name, "print", "function");
}

static float execTermExpression(struct ExecEnviron* e, struct AstElement* a)
{
    /* This function looks ugly because it handles two different kinds of
     * AstElement. I would refactor it to an execNameExp and execVal
     * function to get rid of this two if statements. */
    assert(a);
    if(ekNumber == a->kind)
    {
        return a->data.val;
    }
    else
    {
        if(ekId == a->kind)
        {
            assert(e);
            return get_var_val(a->data.name[0], a->data.name[1]);
        }
    }
    fprintf(stderr, "OOPS: tried to get the value of a non-expression(%d)\n", a->kind);
    exit(1);
}

static float execBinExp(struct ExecEnviron* e, struct AstElement* a)
{
    assert(ekBinExpression == a->kind);
    const float left = dispatchExpression(e, a->data.expression.left);
    const float right = dispatchExpression(e, a->data.expression.right);
    switch(a->data.expression.op)
    {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '>':
            return left > right;
        case '<':
            return left < right;
        case '1':
            return left <= right;
        case '2':
            return left >= right;
        case '=':
            return left == right;
        case '!':
            return left != right;
        default:
            fprintf(stderr,  "OOPS: Unknown operator:%c\n", a->data.expression.op);
            exit(1);
    }
    /* no return here, since every switch case returns some value (or bails out) */
}

static void execAssign(struct ExecEnviron* e, struct AstElement* a)
{
    assert(a);
    assert(ekAssignment == a->kind);
    assert(e);
    struct AstElement* r = a->data.assignment.right;
    assign_var(a->data.assignment.name, dispatchExpression(e, r), a->data.assignment.index);
}

static void execWhile(struct ExecEnviron* e, struct AstElement* a)
{
    assert(a);
    assert(ekWhile == a->kind);
    struct AstElement* const c = a->data.whileStmt.cond;
    struct AstElement* const s = a->data.whileStmt.statements;
    assert(c);
    assert(s);
    while(dispatchExpression(e, c))
    {
        dispatchStatement(e, s);
    }
}

static void execCall(struct ExecEnviron* e, struct AstElement* a)
{
    assert(a);
    assert(ekCall == a->kind);
    onlyPrint(a->data.call.name);
    printf("%f\n", dispatchExpression(e, a->data.call.param));
}

static void execStmt(struct ExecEnviron* e, struct AstElement* a)
{
    assert(a);
    assert(ekStatements == a->kind);
    int i;
    for(i=0; i<a->data.statements.count; i++)
    {
        dispatchStatement(e, a->data.statements.statements[i]);
    }
}

static void execIf(struct ExecEnviron* e, struct AstElement* a) {
    assert(a);
    assert(ekIf == a->kind);
    struct AstElement* const c = a->data.ifStmt.cond;
    struct AstElement* const if_s = a->data.ifStmt.if_statement;
    struct AstElement* const else_s = a->data.ifStmt.else_statement;

    if(dispatchExpression(e, c)) {
        dispatchStatement(e, if_s);
    } else {
        dispatchStatement(e, else_s);
    }
}

static void execNop(struct ExecEnviron* e, struct AstElement* a) {
    assert(a);
    assert(ekNop == a->kind);
    return;
}

static void execVar(struct ExecEnviron* e, struct AstElement* a) {
    assert(a);
    assert(ekVar == a->kind);
    make_id(a->data.variable.name, a->data.variable.type, a->data.variable.index);
}

static void execProcedure(struct ExecEnviron* e, struct AstElement* a) {
    assert(a);
    assert(ekProcedure == a->kind);

    int stack_frame = stackSize;
    int *temp_var_map = malloc(sizeof(var_map));
    if (!temp_var_map) {
        fprintf(stderr, "No memory space for var_map\n");
        exit(1);
    }
    memcpy(temp_var_map, var_map, sizeof(var_map));

    struct AstElement* stament = sub_program_map[a->data.procedure.name];
    int i;

    for(i = 0; i < stament->data.statements.count; i++)
    {
        dispatchStatement(e, stament->data.statements.statements[i]);
    }

    stackSize = stack_frame;
    memcpy(var_map, temp_var_map, sizeof(var_map));
    free(temp_var_map);
}

void execAst(struct ExecEnviron* e, struct AstElement* a)
{
    dispatchStatement(e, a);
}

struct ExecEnviron* createEnv()
{
    assert(ekLastElement == (sizeof(valExecs)/sizeof(*valExecs)));
    assert(ekLastElement == (sizeof(runExecs)/sizeof(*runExecs)));
    return calloc(1, sizeof(struct ExecEnviron));
}

void freeEnv(struct ExecEnviron* e)
{
    free(e);
}