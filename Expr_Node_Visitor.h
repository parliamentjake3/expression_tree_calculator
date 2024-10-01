#ifndef _EXPR_NODE_VISITOR_H_
#define _EXPR_NODE_VISITOR_H_

#include "Nodes.h"

class Expr_Node_Visitor {
public:
    Expr_Node_Visitor (void);
    virtual ~Expr_Node_Visitor (void);

    virtual void Visit_Number_Node (const Num_Expr_Node & node) = 0;

    virtual void Visit_Addition_Node (const Add_Expr_Node & node) = 0;
    virtual void Visit_Subtraction_Node (const Sub_Expr_Node & node) = 0;
    virtual void Visit_Multiplication_Node (const Multi_Expr_Node & node) = 0;
    virtual void Visit_Division_Node (const Div_Expr_Node & node) = 0;
    virtual void Visit_Modulus_Node (const Mod_Expr_Node & node) = 0;

    virtual void Visit_Unary_Node (const Unary_Expr_Node & node) = 0;
};

#endif // _EXPR_NODE_VISITOR_H_