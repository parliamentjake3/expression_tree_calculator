#ifndef _NODES_H_
#define _NODES_H_

class Expr_Node_Visitor;

// Base Expression Node

class Expr_Node
{
public:
    Expr_Node(void);
    virtual ~Expr_Node(void);

    // Used to traverse the tree
    virtual int eval(void) const = 0;
    virtual int get_precedence() const = 0;

    virtual void accept (Expr_Node_Visitor & v) = 0;
};

// Unary Expression Node

class Unary_Expr_Node : public Expr_Node
{
public:
    Unary_Expr_Node(Expr_Node *child);
    ~Unary_Expr_Node(void);

    int eval(void) const override;
    int get_precedence() const;

    virtual void accept (Expr_Node_Visitor & v);

protected:
    Expr_Node *child_;
};

// Number Expression Node

class Num_Expr_Node : public Expr_Node
{
public:
    Num_Expr_Node(int n);

    int eval(void) const override;
    int get_precedence() const;

    virtual void accept (Expr_Node_Visitor & v);

protected:
    int num_;
};

// Binary Expression Node

class Binary_Expr_Node : public Expr_Node
{
public:
    Binary_Expr_Node(Expr_Node *n1, Expr_Node *n2);
    virtual ~Binary_Expr_Node(void);

    virtual int eval(void) const = 0;

    Expr_Node* getLeft(void) const;
    Expr_Node* getRight(void) const;

    void setLeft(Expr_Node* node);
    void setRight(Expr_Node* node);

    virtual int get_precedence() const = 0;

    virtual void accept (Expr_Node_Visitor & v) = 0;

protected:
    Expr_Node *left_;
    Expr_Node *right_;
};

// Addition Expression Node

class Add_Expr_Node : public Binary_Expr_Node
{
public:
    Add_Expr_Node(Expr_Node *n1, Expr_Node *n2);

    int eval(void) const;
    virtual int get_precedence() const;

    virtual void accept (Expr_Node_Visitor & v);
};

// Subtraction Expr Node

class Sub_Expr_Node : public Binary_Expr_Node
{
public:
    Sub_Expr_Node(Expr_Node *n1, Expr_Node *n2);

    int eval(void) const;
    virtual int get_precedence() const;

    virtual void accept (Expr_Node_Visitor & v);
};

// Multiplication Expression Node

class Multi_Expr_Node : public Binary_Expr_Node
{
public:
    Multi_Expr_Node(Expr_Node *n1, Expr_Node *n2);

    int eval(void) const;
    virtual int get_precedence() const;

    virtual void accept (Expr_Node_Visitor & v);
};

// Division Expression Node

class Div_Expr_Node : public Binary_Expr_Node
{
public:
    Div_Expr_Node(Expr_Node *n1, Expr_Node *n2);

    int eval(void) const;
    virtual int get_precedence() const;

    virtual void accept (Expr_Node_Visitor & v);
};

// Modulus Expression Node

class Mod_Expr_Node : public Binary_Expr_Node
{
public:
    Mod_Expr_Node(Expr_Node *n1, Expr_Node *n2);

    int eval(void) const;
    virtual int get_precedence() const;

    virtual void accept (Expr_Node_Visitor & v);
};

#endif // _NODES_H_