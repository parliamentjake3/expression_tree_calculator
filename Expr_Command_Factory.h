#ifndef _EXPR_COMMAND_FACTORY_H_
#define _EXPR_COMMAND_FACTORY_H_

#include "Commands.h"

class Expr_Command_Factory {
public:

    Expr_Command_Factory() = default; 
    virtual ~Expr_Command_Factory() {};

    virtual int get_precedence(std::string token) = 0;

    virtual Expr_Command* get_command(std::string token) = 0;

    virtual Num_Command* create_number_command(int num) = 0;
    virtual Add_Command* create_add_command(void) = 0;
    virtual Sub_Command* create_subtract_command(void) = 0;
    virtual Multi_Command* create_multiply_command(void) = 0;
    virtual Div_Command* create_divide_command(void) = 0;
    virtual Mod_Command* create_modulus_command(void) = 0;
    virtual Par_Command* create_parenthesis_command(void) = 0;

private:
    Expr_Command_Factory(const Expr_Command_Factory&) {}
    const Expr_Command_Factory& operator = (const Expr_Command_Factory&);
};

#endif // _EXPR_COMMAND_FACTORY_H_
