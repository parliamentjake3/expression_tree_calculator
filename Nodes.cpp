#include "Nodes.h"
#include <stdexcept>

#include "Expr_Node_Visitor.h"

// Base Expression Node

Expr_Node::Expr_Node(void) {}
Expr_Node::~Expr_Node(void) {}

// Unary Expression Node

Unary_Expr_Node::Unary_Expr_Node(Expr_Node *child) : child_(child) {}
Unary_Expr_Node::~Unary_Expr_Node(void)
{
    delete this->child_;
}

int Unary_Expr_Node::eval(void) const
{
    // Convert positive int to a negative int
    return this->child_->eval() * -1;
}

int Unary_Expr_Node::get_precedence() const
{
    return 3;
}

void Unary_Expr_Node::accept(Expr_Node_Visitor & v) {
    v.Visit_Unary_Node(*this);
}

// Number Expression Node

Num_Expr_Node::Num_Expr_Node(int n) : num_(n) {}

int Num_Expr_Node::eval(void) const
{
    return this->num_;
}

int Num_Expr_Node::get_precedence() const
{
    return 0;
}

void Num_Expr_Node::accept(Expr_Node_Visitor & v) {
    v.Visit_Number_Node(*this);
}

// Binary Expression Node

Binary_Expr_Node::Binary_Expr_Node(Expr_Node *left, Expr_Node *right) : left_(left), right_(right){};
Binary_Expr_Node::~Binary_Expr_Node(void)
{
    delete left_;
    delete right_;
}

Expr_Node *Binary_Expr_Node::getLeft(void) const
{
    return this->left_;
}
Expr_Node *Binary_Expr_Node::getRight(void) const
{
    return this->right_;
}

void Binary_Expr_Node::setLeft(Expr_Node *node)
{
    this->left_ = node;
}
void Binary_Expr_Node::setRight(Expr_Node *node)
{
    this->right_ = node;
}

// Addition Expression Node

Add_Expr_Node::Add_Expr_Node(Expr_Node *left, Expr_Node *right) : Binary_Expr_Node(left, right){};

int Add_Expr_Node::eval() const
{
    if (this->left_ == nullptr || this->right_ == nullptr)
    {
        throw std::runtime_error("Attempted to evaluate addition with null operand(s).");
    }
    return this->left_->eval() + this->right_->eval();
}

int Add_Expr_Node::get_precedence() const
{
    return 1;
}

void Add_Expr_Node::accept(Expr_Node_Visitor & v) {
    v.Visit_Addition_Node(*this);
}

// Subtraction Expression Node

Sub_Expr_Node::Sub_Expr_Node(Expr_Node *left, Expr_Node *right) : Binary_Expr_Node(left, right){};

int Sub_Expr_Node::eval() const
{
    if (this->left_ == nullptr || this->right_ == nullptr)
    {
        throw std::runtime_error("Attempted to evaluate subtraction with null operand(s).");
    }
    return this->left_->eval() - this->right_->eval();
}

int Sub_Expr_Node::get_precedence() const
{
    return 1;
}

void Sub_Expr_Node::accept(Expr_Node_Visitor & v) {
    v.Visit_Subtraction_Node(*this);
}

// Multiplication Expression Node

Multi_Expr_Node::Multi_Expr_Node(Expr_Node *left, Expr_Node *right) : Binary_Expr_Node(left, right){};

int Multi_Expr_Node::eval() const
{
    if (this->left_ == nullptr || this->right_ == nullptr)
    {
        throw std::runtime_error("Attempted to evaluate multiplication with null operand(s).");
    }
    return this->left_->eval() * this->right_->eval();
}

int Multi_Expr_Node::get_precedence() const
{
    return 2;
}

void Multi_Expr_Node::accept(Expr_Node_Visitor & v) {
    v.Visit_Multiplication_Node(*this);
}

// Division Expression Node

Div_Expr_Node::Div_Expr_Node(Expr_Node *left, Expr_Node *right) : Binary_Expr_Node(left, right){};

int Div_Expr_Node::eval() const
{
    if (this->left_ == nullptr || this->right_ == nullptr)
    {
        throw std::runtime_error("Attempted to evaluate division with null operand(s).");
    }
    int right_eval = this->right_->eval();
    if (right_eval == 0)
    {
        throw std::runtime_error("Division by zero.");
    }
    return this->left_->eval() / this->right_->eval();
}

int Div_Expr_Node::get_precedence() const
{
    return 2;
}

void Div_Expr_Node::accept(Expr_Node_Visitor & v) {
    v.Visit_Division_Node(*this);
}

// Modulus Expression Node

Mod_Expr_Node::Mod_Expr_Node(Expr_Node *left, Expr_Node *right) : Binary_Expr_Node(left, right){};

int Mod_Expr_Node::eval() const
{
    if (this->left_ == nullptr || this->right_ == nullptr)
    {
        throw std::runtime_error("Attempted to evaluate modulus with null operand(s).");
    }
    int right_eval = this->right_->eval();
    if (right_eval == 0)
    {
        throw std::runtime_error("Modulus by zero.");
    }
    return this->left_->eval() % this->right_->eval();
}

int Mod_Expr_Node::get_precedence() const
{
    return 2;
}

void Mod_Expr_Node::accept(Expr_Node_Visitor & v) {
    v.Visit_Modulus_Node(*this);
}
