#include "InfixToPostfixConverter.h"

bool InfixToPostfixConverter::infix_to_postfix(const std::string &infix, Expr_Command_Factory &factory, Array<Expr_Command *> &postfix)
    {
        std::istringstream input(infix);
        std::string token;
        Expr_Command *cmd = 0;
        Stack<Expr_Command *> temp;

        // set postfix size based on the length of infix
        postfix.resize(infix.length());
        int postfix_index = 0;

        while (input >> token)
        {

            // Check for positive and negative numbers
            if (token[0] == '-' && token.length() > 1 && std::all_of(token.begin() + 1, token.end(), ::isdigit))
            {
                // All characters after '-' are digits, valid negative number
                Expr_Command *cmd = factory.create_number_command(std::stoi(token));
                postfix[postfix_index++] = cmd;
            }
            else if (std::all_of(token.begin(), token.end(), ::isdigit))
            {
                // All characters are digits, valid positive number
                Expr_Command *cmd = factory.create_number_command(std::stoi(token));
                postfix[postfix_index++] = cmd;
            }

            // Check for operators
            else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%")
            {
                // Check for precedence
                while (!temp.is_empty() && temp.top()->precedence() >= factory.get_precedence(token))
                {
                    postfix[postfix_index++] = temp.pop();
                }

                // Push token command to the stack
                Expr_Command *cmd = factory.get_command(token);
                temp.push(cmd);
            }

            // Check for parenthesis
            else if (token == "(")
            {

                // Push temporaty parenthesis command to the stack
                Expr_Command *cmd = factory.create_parenthesis_command();
                temp.push(cmd);
            }
            else if (token == ")")
            {
                while (!temp.is_empty() && temp.top()->token() != "(")
                {
                    postfix[postfix_index++] = temp.pop();
                }
                // Pop the left parenthesis from the stack, but don't add it to the postfix expression
                if (!temp.is_empty())
                    temp.pop();
            }
            else
            {
                // Unsupported token
                std::cerr << "Unsupported token encountered: " << token << std::endl;
                return false;
            }
        }

        // COMMENT Where is the rest of the infix-to-postfix alogrithm?! This is
        // a critical part so the calculator actually works.

        // added precedence, negative numbers and parenthesis above

        // Add all the commands in the stack to the postfix
        while (!temp.is_empty())
        {
            postfix[postfix_index] = temp.pop();
            postfix_index++;
        }

        // resize the postfix to the correct length
        postfix.resize(postfix_index);
        return true;
    }