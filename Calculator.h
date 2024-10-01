#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <iostream>
#include <string>
#include "InfixToPostfixConverter.h"
#include "PostfixExecutor.h"
#include "Stack_Expr_Command_Factory.h"
#include "Array.h"
#include "Commands.h"
#include "Stack.h"
#include "Expr_Tree_Builder.h"

class Calculator {
private:
    Stack<int> calcStack;

public:
    void runCalculator(void);
    void runTreeCalculator(void);
    bool parse_expression(const std::string& expression, Expr_Tree_Builder& builder);
};

#endif // _CALCULATOR_H_
