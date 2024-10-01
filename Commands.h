#ifndef _COMMANDS_H_
#define _COMMANDS_H_

#include "Stack.h"

// COMMENT Place your class implementation in a source file and not inside
// the header file.

// Moved all Command defenitions in one (Commands.h) file

// Base Expression Command

class Expr_Command {
public:
	virtual void execute() = 0;
    virtual int precedence() = 0;
    virtual std::string token() = 0;
};

// Number Command

class Num_Command : public Expr_Command {
public:
	Num_Command (Stack<int> & s, int n);
	void execute() override;
    int precedence() override;
    std::string token() override;
private:
	Stack<int> & s_;
	int n_;
};

// Addition Command

class Add_Command : public Expr_Command {
public:
    Add_Command (Stack <int> & s, int p, std::string t);
    void execute() override;
    int precedence() override;
    std::string token() override;
private:
	Stack<int> & s_;
    int precedence_;
    std::string t_;
};

// Subtraction Command

class Sub_Command : public Expr_Command {
public:
    Sub_Command (Stack <int> & s, int p, std::string t);
    void execute() override;
    int precedence() override;
    std::string token() override;
private:
	Stack<int> & s_;
    int precedence_;
    std::string t_;
};

// Multiplication Command

class Multi_Command : public Expr_Command {
public:
    Multi_Command (Stack <int> & s, int p, std::string t);
    void execute() override;
    int precedence() override;
    std::string token() override;
private:
	Stack<int> & s_;
    int precedence_;
    std::string t_;
};

// Division Command

class Div_Command : public Expr_Command {
public:
    Div_Command (Stack <int> & s, int p, std::string t);
    void execute() override;
    int precedence() override;
    std::string token() override;
private:
	Stack<int> & s_;
    int precedence_;
    std::string t_;
};

// Modulus Command

class Mod_Command : public Expr_Command {
public:
    Mod_Command (Stack <int> & s, int p, std::string t);
    void execute() override;
    int precedence() override;
    std::string token() override;
private:
	Stack<int> & s_;
    int precedence_;
    std::string t_;
};

// Paranthesis Command

class Par_Command : public Expr_Command {
public:
    Par_Command(Stack <int> & s, int p, std::string t);
    void execute() override;
    int precedence() override;
    std::string token() override;
private:
    Stack<int> & s_;
    int precedence_;
    std::string t_;
};

#endif // _COMMANDS_H_