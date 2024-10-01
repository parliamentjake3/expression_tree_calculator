#include "Expr_Tree_Builder.h"
#include <iostream>

Expr_Tree_Builder::Expr_Tree_Builder(void) : tree_(nullptr) {}

Expr_Tree_Builder::~Expr_Tree_Builder(void)
{
    delete this->tree_;
}

void Expr_Tree_Builder::start_expression(void)
{
    this->tree_ = nullptr;
    while (!this->operands_.is_empty())
        this->operands_.pop();
    while (!this->operators_.is_empty())
        this->operators_.pop();
}

Expr_Node *Expr_Tree_Builder::get_expression(void)
{
    finalize_operators();
    if (!operands_.is_empty())
        this->tree_ = operands_.top();
    return this->tree_;
}

void Expr_Tree_Builder::process_operator(Binary_Expr_Node *op, int precedence)
{
    while (!this->operators_.is_empty() && this->operators_.top() != nullptr && this->operators_.top()->get_precedence() >= precedence)
    {
        finalize_operator();
    }
    this->operators_.push(op);
}

void Expr_Tree_Builder::build_number(int n)
{
    this->operands_.push(new Num_Expr_Node(n));
}

void Expr_Tree_Builder::build_unary_operator(void)
{
    if (!operands_.is_empty())
    {
        Expr_Node *child = operands_.top();
        operands_.pop();
        Unary_Expr_Node *unary_node = new Unary_Expr_Node(child);
        operands_.push(unary_node);
    }
    else
    {
        std::cerr << "Error: Unary minus cannot find an operand." << std::endl;
    }
}

void Expr_Tree_Builder::build_add_operator(void)
{
    process_operator(new Add_Expr_Node(nullptr, nullptr), 1);
}

void Expr_Tree_Builder::build_sub_operator(void)
{
    process_operator(new Sub_Expr_Node(nullptr, nullptr), 1);
}

void Expr_Tree_Builder::build_multi_operator(void)
{
    process_operator(new Multi_Expr_Node(nullptr, nullptr), 2);
}

void Expr_Tree_Builder::build_div_operator(void)
{
    process_operator(new Div_Expr_Node(nullptr, nullptr), 2);
}

void Expr_Tree_Builder::build_mod_operator(void)
{
    process_operator(new Mod_Expr_Node(nullptr, nullptr), 2);
}

void Expr_Tree_Builder::build_open_parenthesis(void)
{
    this->operators_.push(nullptr);
}

void Expr_Tree_Builder::build_close_parenthesis(void)
{
    // Pop and process all operators until the open parenthesis marker is found
    while (!operators_.is_empty() && operators_.top() != nullptr)
    {
        finalize_operator();
    }
    // Remove the open parenthesis marker from the stack
    if (!operators_.is_empty())
    {
        operators_.pop();
    }
}

void Expr_Tree_Builder::finalize_operators(void)
{
    while (!operators_.is_empty())
    {
        finalize_operator();
    }
}

void Expr_Tree_Builder::finalize_operator(void)
{
    if (this->operators_.is_empty())
        return;

    Binary_Expr_Node *op = this->operators_.top();
    this->operators_.pop();

    // Check for sufficient operands
    if (!this->operands_.is_empty())
    {
        op->setRight(this->operands_.top());
        this->operands_.pop();
    }
    if (!this->operands_.is_empty())
    {
        op->setLeft(this->operands_.top());
        this->operands_.pop();
    }

    // Push the newly created sub-expression back onto the operands stack
    this->operands_.push(op);
}
