#ifndef _STACK_EXPR_COMMAND_FACTORY_H_
#define _STACK_EXPR_COMMAND_FACTORY_H_

#include "Expr_Command_Factory.h"
#include "Stack.h"
#include "Commands.h"

// COMMENT Place your class implementation in a source file and not inside
// the header file.

// Moved the implementation to a source file

class Stack_Expr_Command_Factory : public Expr_Command_Factory {
public:
	Stack_Expr_Command_Factory(Stack<int> & stack);

	virtual int get_precedence(std::string token);

	virtual Expr_Command* get_command(std::string token);

	virtual Num_Command* create_number_command(int num);
	virtual Add_Command* create_add_command(void);
	virtual Sub_Command* create_subtract_command(void);
	virtual Multi_Command* create_multiply_command(void);
	virtual Div_Command* create_divide_command(void);
	virtual Mod_Command* create_modulus_command(void);
	virtual Par_Command* create_parenthesis_command(void);

private:
	Stack<int> & stack_;
};

#endif // _STACK_EXPR_COMMAND_FACTORY_H_
