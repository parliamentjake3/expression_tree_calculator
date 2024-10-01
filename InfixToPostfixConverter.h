#ifndef _INFIXTOPOSTFIXCONVERTER_H_
#define _INFIXTOPOSTFIXCONVERTER_H_

#include <sstream>
#include <cctype>
#include <algorithm>
#include <iostream>

#include "Expr_Command_Factory.h"
#include "Stack.h"
#include "Array.h"
#include "Commands.h"

// COMMENT Place your class implementation in a source file and not inside
// the header file.

// moved the infix_to_postfix function to a source file

class InfixToPostfixConverter
{
public:
    bool infix_to_postfix(const std::string &infix, Expr_Command_Factory &factory, Array<Expr_Command *> &postfix);
};

#endif // _INFIXTOPOSTFIXCONVERTER_H_
