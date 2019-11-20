#ifndef STATEMENT_H
#define STATEMENT_H

typedef struct _Stat {
    enum {ekassignment, ekprint, ekprocedure, ekcompound, ekif, ekwhile, ekreturn, eknop} type;
    typedef struct {
        char name[100];
        float val;
    } ekassignment;
    typedef struct {
        float val;
    } ekprint;
    typedef struct {
        char name[100];
    } ekprocedure;
    typedef struct {
        float val;
    } ekreturn;

    struct _Stat* link;
} Stat;

Stat *makeAssignmentStat(char *name, float val);
Stat *makePrintStat(float val);
Stat *makeProcedureStat(char *name);
Stat *makeCompoundStat(Stat *stat);
#endif