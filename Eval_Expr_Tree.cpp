#include "Eval_Expr_Tree.h"

Eval_Expr_Tree::Eval_Expr_Tree (void){}
Eval_Expr_Tree::~Eval_Expr_Tree (void){}

void Eval_Expr_Tree::Visit_Number_Node(const Num_Expr_Node &node){
    result_ = node.eval();
}
void Eval_Expr_Tree::Visit_Addition_Node(const Add_Expr_Node &node){
    int left_result = node.getLeft()->eval();
    int right_result = node.getRight()->eval(); 
    result_ = left_result + right_result;
}
void Eval_Expr_Tree::Visit_Subtraction_Node(const Sub_Expr_Node &node){
    int left_result = node.getLeft()->eval();
    int right_result = node.getRight()->eval(); 
    result_ = left_result - right_result;
}
void Eval_Expr_Tree::Visit_Multiplication_Node(const Multi_Expr_Node &node){
    int left_result = node.getLeft()->eval();
    int right_result = node.getRight()->eval(); 
    result_ = left_result * right_result;
}
void Eval_Expr_Tree::Visit_Division_Node(const Div_Expr_Node &node){
    int left_result = node.getLeft()->eval();
    int right_result = node.getRight()->eval(); 
    result_ = left_result / right_result;
}
void Eval_Expr_Tree::Visit_Modulus_Node(const Mod_Expr_Node &node){
    int left_result = node.getLeft()->eval();
    int right_result = node.getRight()->eval(); 
    result_ = left_result % right_result;
}
void Eval_Expr_Tree::Visit_Unary_Node(const Unary_Expr_Node &node){
    int child_result = node.eval(); 
    result_ = child_result;
}

int Eval_Expr_Tree::result (void) const{
    return result_;
}