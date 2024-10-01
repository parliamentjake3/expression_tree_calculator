#ifndef _EXPR_TREE_BUILDER_H_
#define _EXPR_TREE_BUILDER_H_

#include "Expr_Builder.h"
#include "Stack.h"

class Expr_Tree_Builder : public Expr_Builder
{

public:
    Expr_Tree_Builder(void);
    ~Expr_Tree_Builder(void);

    void start_expression(void);

    void process_operator(Binary_Expr_Node *op, int precedence);

    void build_number(int n);
    void build_unary_operator(void);
    void build_add_operator(void);
    void build_sub_operator(void);
    void build_multi_operator(void);
    void build_div_operator(void);
    void build_mod_operator(void);

    void build_open_parenthesis(void);
    void build_close_parenthesis(void);

    Expr_Node *get_expression(void);

    void finalize_operators(void);
    void finalize_operator(void);

private:
    Expr_Node *tree_;
    Stack<Expr_Node *> operands_;
    Stack<Binary_Expr_Node *> operators_;
};

#endif // _EXPR_TREE_BUILDER_H