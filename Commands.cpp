#include "Commands.h"

// COMMENT Place your class implementation in a source file and not inside
// the header file.

// Moved all Command implementation in one (Commands.cpp) file

// Number Command

Num_Command::Num_Command (Stack<int> & s, int n) : s_(s), n_(n) {}

void Num_Command::execute(){
    this->s_.push(this->n_);
}

int Num_Command::precedence(){
    return 0;
}

std::string Num_Command::token(){
    return "";
}

// Addition Command

Add_Command::Add_Command (Stack <int> & s, int p, std::string t) : s_ (s), precedence_(p), t_(t) {}

void Add_Command::execute() {
    int n1 = this->s_.pop(), n2 = this->s_.pop();
    this->s_.push(n2 + n1);
}

int Add_Command::precedence(){
    return this->precedence_;
}

std::string Add_Command::token(){
    return this->t_;
}

// Subtraction Command

Sub_Command::Sub_Command (Stack <int> & s, int p, std::string t) : s_ (s), precedence_(p), t_(t) {}

void Sub_Command::execute() {
    int n1 = this->s_.pop(), n2 = this->s_.pop();
    this->s_.push(n2 - n1);
}

int Sub_Command::precedence(){
    return this->precedence_;
}

std::string Sub_Command::token(){
    return this->t_;
}

// Multiplication Command

Multi_Command::Multi_Command (Stack <int> & s, int p, std::string t) : s_ (s), precedence_(p), t_(t) {}

void Multi_Command::execute() {
    int n1 = this->s_.pop(), n2 = this->s_.pop();
    this->s_.push(n2 * n1);
}

int Multi_Command::precedence(){
    return this->precedence_;
}

std::string Multi_Command::token(){
    return this->t_;
}

// Division Command

Div_Command::Div_Command (Stack <int> & s, int p, std::string t) : s_ (s), precedence_(p), t_(t) {}

void Div_Command::execute() {
    int n1 = this->s_.pop(), n2 = this->s_.pop();
    if(n1 == 0) {
        throw std::runtime_error("Division by zero error.");
    }
    this->s_.push(n2 / n1);
}

int Div_Command::precedence(){
    return this->precedence_;
}

std::string Div_Command::token(){
    return this->t_;
}

// Modulus Command

Mod_Command::Mod_Command (Stack <int> & s, int p, std::string t) : s_ (s), precedence_(p), t_(t) {}

void Mod_Command::execute() {
    int n1 = this->s_.pop(), n2 = this->s_.pop();
    if(n1 == 0) {
        throw std::runtime_error("Mod by zero error.");
    }
    this->s_.push(n2 % n1);
}

int Mod_Command::precedence(){
    return this->precedence_;
}

std::string Mod_Command::token(){
    return this->t_;
}

// Parenthesis Command

Par_Command::Par_Command (Stack <int> & s, int p, std::string t) : s_ (s), precedence_(p), t_(t) {}

void Par_Command::execute(){
    return;
}

int Par_Command::precedence(){
    return this->precedence_;
}

std::string Par_Command::token(){
    return this->t_;
}
