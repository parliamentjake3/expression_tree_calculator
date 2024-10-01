#ifndef _POSTFIX_EXECUTOR_H_
#define _POSTFIX_EXECUTOR_H_

#include "Commands.h" 
#include "Array.h"   
#include "Stack.h"   
#include <stdexcept> 

// COMMENT Place your class implementation in a source file and not inside
// the header file.

// Moved implementation to a source file

class PostfixExecutor {
public:
    PostfixExecutor();
    int execute(const Array<Expr_Command*>& postfix, Stack<int> & stack);
};

#endif // _POSTFIX_EXECUTOR_H_
