#include "PostfixExecutor.h"

PostfixExecutor::PostfixExecutor() {}

int PostfixExecutor::execute(const Array<Expr_Command*>& postfix, Stack<int> & stack) {

        // Loops through every index of the postfix
        for (size_t i = 0; i < postfix.size(); ++i) {
            // Ensure the command object exists
            if (postfix[i] == nullptr) {
                throw std::runtime_error("Null command encountered in execution.");
            }

            // Execute the command
            postfix[i]->execute();
        }

        // After executing all commands, the final result should be on the stack.
        if (stack.size() != 1) {
            throw std::runtime_error("Invalid expression.");
        }

        // Return the result
        return stack.pop();
    }