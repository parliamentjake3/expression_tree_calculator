#include "Stack_Expr_Command_Factory.h"

Stack_Expr_Command_Factory::Stack_Expr_Command_Factory (Stack<int> & stack) : stack_(stack) {}

int Stack_Expr_Command_Factory::get_precedence(std::string token){
	if(token == "+" || token == "-"){
		return 1;
	}
	else if(token == "*" || token == "/" || token == "%"){
		return 2;
	}

	return 3;
}

Expr_Command* Stack_Expr_Command_Factory::get_command(std::string token){
	if(token == "+"){
		return this->create_add_command();
	}
	else if(token == "-"){
		return this->create_subtract_command();
	}
	else if(token == "*"){
		return this->create_multiply_command();
	}
	else if(token == "/"){
		return this->create_divide_command();
	}

	else if(token == "%"){
		return this->create_modulus_command();
	}
	else{
		return this->create_parenthesis_command();
	}
}

Num_Command* Stack_Expr_Command_Factory::create_number_command(int num) {
		return new Num_Command(this->stack_, num);
}

Add_Command* Stack_Expr_Command_Factory::create_add_command(void) {
		return new Add_Command(this->stack_, 1, "+");
}

Sub_Command* Stack_Expr_Command_Factory::create_subtract_command(void) {
		return new Sub_Command(this->stack_, 1, "-");
}

Multi_Command* Stack_Expr_Command_Factory::create_multiply_command(void) {
		return new Multi_Command(this->stack_, 2, "*");
}

Div_Command* Stack_Expr_Command_Factory::create_divide_command(void) {
		return new Div_Command(this->stack_, 2, "/");
}

Mod_Command* Stack_Expr_Command_Factory::create_modulus_command(void) {
		return new Mod_Command(this->stack_, 2, "%");
}

Par_Command* Stack_Expr_Command_Factory::create_parenthesis_command(void) {
	return new Par_Command(this->stack_, 3, "(");
}