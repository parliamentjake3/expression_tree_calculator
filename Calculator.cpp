 #include "Calculator.h"
 #include "Eval_Expr_Tree.h"

void Calculator::runCalculator(void)
{

    Stack_Expr_Command_Factory factory(calcStack);
    InfixToPostfixConverter converter;
    PostfixExecutor executor;

    std::string input;
    std::cout << "Enter expression (or type 'QUIT' to exit): \n";

    while (std::getline(std::cin, input))
    {

        if (input == "QUIT")
            break;

        try
        {
            // Array to hold the postfix command objects created by the converter
            Array<Expr_Command *> postfixCommands;

            // Convert infix to postfix, storing command objects in postfixCommands
            bool conversionSuccess = converter.infix_to_postfix(input, factory, postfixCommands);

            if (!conversionSuccess)
            {
                continue;
            }

            // Execute the postfix commands and get the result
            int result = executor.execute(postfixCommands, calcStack);

            std::cout << result << std::endl;

            // Cleanup dynamically created command objects in postfixCommands
            for (size_t i = 0; i < postfixCommands.size(); ++i)
            {
                delete postfixCommands[i];
            }
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}

void Calculator::runTreeCalculator(void)
{
    Expr_Tree_Builder builder;

    std::string input;
    std::cout << "Enter expression (or type 'QUIT' to exit): \n";

    while (std::getline(std::cin, input))
    {
        if (input == "QUIT")
            break;

        try
        {
            builder.start_expression();

            if (!parse_expression(input, builder))
            {
                std::cout << "Invalid expression." << std::endl;
                continue;
            }

            Expr_Node *expr = builder.get_expression();
            if (expr == nullptr)
            {
                std::cout << "Empty expression." << std::endl;
                continue;
            }
            
            // COMMENT You are supposed to use the visitor pattern to evaluate the
            // expression tree.

            // Implemented the visitor pattern and and evaluation visitor class

            Eval_Expr_Tree eval;

            expr->accept(eval);
            int result = eval.result();

            std::cout << result << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}

bool Calculator::parse_expression(const std::string &expression, Expr_Tree_Builder &builder)
{
    std::istringstream tokens(expression);
    std::string token;
    bool lastTokenWasOperator = true; 
    bool lastTokenWasNumber = false; 

    while (tokens >> token)
    {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1 && isdigit(token[1])) || (token[0] == '+' && token.size() > 1 && isdigit(token[1])))
        {
            if (lastTokenWasNumber)
            {
                // Two consecutive numbers detected, return false to indicate invalid expression
                return false;
            }
            // Handle numbers (unsigned, negative, and explicit positive)
            builder.build_number(std::stoi(token));
            lastTokenWasOperator = false;
            lastTokenWasNumber = true;
        }
        else if (token == "+" )
        {
            // COMMENT This approach is not the ideal implementation of the builder pattern
            // because you are making the concrete builder also the director. Under this design
            // approach, you are requiring each concrete builder to understand how to "parse" a
            // token and convert it to a "part". This limits your ability to use different
            // concrete builders with your client.

            // removed the build operator based on token parsing
            
            builder.build_add_operator();
            lastTokenWasOperator = true;
            lastTokenWasNumber = false;
        }
        else if (token == "-" )
        {
            builder.build_sub_operator();
            lastTokenWasOperator = true;
            lastTokenWasNumber = false;
        }
        else if (token == "*" )
        {
            builder.build_multi_operator();
            lastTokenWasOperator = true;
            lastTokenWasNumber = false;
        }
        else if (token == "/" )
        {
            builder.build_div_operator();
            lastTokenWasOperator = true;
            lastTokenWasNumber = false;
        }
        else if (token == "%" )
        {
            builder.build_mod_operator();
            lastTokenWasOperator = true;
            lastTokenWasNumber = false;
        }
        else if (token == "(")
        {
            builder.build_open_parenthesis();
            lastTokenWasOperator = true;
            lastTokenWasNumber = false;
        }
        else if (token == ")")
        {
            builder.build_close_parenthesis();
            lastTokenWasOperator = false;
            lastTokenWasNumber = false;
        }
        else
        {
            // Invalid Token
            return false;
        }
    }
    if (!lastTokenWasOperator)
    {
        // Final token should not be an operator
        return true;
    }
    else
    {
        std::cout << "Invalid expression: ends with an operator." << std::endl;
        return false;
    }
}
