#ifndef ASTGEN_H
#define ASTGEN_H


struct AstElement
{
    enum {ekId, ekNumber, ekBinExpression, ekAssignment, ekWhile, ekCall, ekStatements, ekLastElement} kind;
    union
    {
        float val;
        int name;
        int index;
        struct
        {
            struct AstElement *left, *right;
            char op;
        }expression;
        struct
        {
            int name;
            int index;
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

struct AstElement* makeAssignment(int name, int index,struct AstElement* val);
struct AstElement* makeExpByNum(float val);
struct AstElement* makeExpByName(int name, int index);
struct AstElement* makeExp(struct AstElement* left, struct AstElement* right, char op);
struct AstElement* makeStatement(struct AstElement* dest, struct AstElement* toAppend);
struct AstElement* makeWhile(struct AstElement* cond, struct AstElement* exec);
struct AstElement* makeCall(int name, struct AstElement* param);
#endif