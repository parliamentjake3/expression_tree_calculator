#ifndef _EVAL_EXPR_TREE_H_
#define _EVAL_EXPR_TREE_H_

#include "Expr_Node_Visitor.h"

class Eval_Expr_Tree : public Expr_Node_Visitor{
public:
    
    Eval_Expr_Tree(void);
    ~Eval_Expr_Tree(void);

    virtual void Visit_Number_Node (const Num_Expr_Node & node) override;

    virtual void Visit_Addition_Node (const Add_Expr_Node & node) override;
    virtual void Visit_Subtraction_Node (const Sub_Expr_Node & node) override;
    virtual void Visit_Multiplication_Node (const Multi_Expr_Node & node) override;
    virtual void Visit_Division_Node (const Div_Expr_Node & node) override;
    virtual void Visit_Modulus_Node (const Mod_Expr_Node & node) override;

    virtual void Visit_Unary_Node (const Unary_Expr_Node & node) override;

    int result (void) const;

private:
    int result_;
};

#endif // _EVAL_EXPR_TREE_H_