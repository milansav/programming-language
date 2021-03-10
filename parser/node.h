#ifndef NODE_H
#define NODE_H

enum statement_type
{
    FUNCTION,
    VARIABLE,
    CONSTANT,
    CONDITION,
    LOOP,
    RETURN,
    ASSIGN,
    BRANCH,
    BIN_OP,
    NO_OP
};

typedef struct constant{
    int value;
} constant;

typedef struct variable{
    int value;
    char* label;
} variable;

typedef struct assign{
    unsigned char leftType; //1 variable, 0 const
    union left
    {
        struct variable* _var;
        struct constant* _const;
    } left;

    unsigned char rightType; //1 variable, 0 const
    union right
    {
        struct variable* _var;
        struct constant* _const;
    } right;
} assign;

typedef struct statement{
    unsigned char type;
    union node
    {
        struct constant* _const;
        struct variable* _var;
    } node;
} statement;


#endif