#ifndef _EXPR_BUILDER_H
#define _EXPR_BUILDER_H

#include "Nodes.h"

class Expr_Builder
{
public:
    virtual void start_expression(void) = 0;

    virtual void build_number(int n) = 0;

    virtual void build_unary_operator(void) = 0;
    virtual void build_add_operator(void) = 0;
    virtual void build_sub_operator(void) = 0;
    virtual void build_multi_operator(void) = 0;
    virtual void build_div_operator(void) = 0;
    virtual void build_mod_operator(void) = 0;

    virtual void build_open_parenthesis(void) = 0;
    virtual void build_close_parenthesis(void) = 0;

    virtual Expr_Node *get_expression(void) = 0;
};

#endif // _EXPR_BUILDER_H
