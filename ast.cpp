#include "ast.h"

std::unique_ptr<A_stm> A_Assign_Stm(const std::string &id, std::unique_ptr<A_exp> exp)
{
    return std::unique_ptr<A_assign_stm>(new A_assign_stm(id, std::move(exp)));
}

std::unique_ptr<A_print_stm> A_Print_Stm(std::unique_ptr<A_exp_list> exps)
{
    return std::unique_ptr<A_print_stm>(new A_print_stm(std::move(exps)));
}

std::unique_ptr<A_id_exp> A_Id_Exp(const std::string &id)
{
    return std::unique_ptr<A_id_exp>(new A_id_exp(id));
}

std::unique_ptr<A_num_exp> A_Num_Exp(int num)
{
    return std::unique_ptr<A_num_exp>(new A_num_exp(num));
}

std::unique_ptr<A_binop_exp> A_Binop_Exp(A_binop op, std::unique_ptr<A_exp> exp1, std::unique_ptr<A_exp> exp2)
{
    return std::unique_ptr<A_binop_exp>(new A_binop_exp(op, std::move(exp1), std::move(exp2)));
}

std::unique_ptr<A_pair_exp_list> A_Pair_Exp_List(std::unique_ptr<A_exp> exp, std::unique_ptr<A_exp_list> exp_list)
{
    return std::unique_ptr<A_pair_exp_list>(new A_pair_exp_list(std::move(exp), std::move(exp_list)));
}

std::unique_ptr<A_exp_list> A_Last_Exp_List(std::unique_ptr<A_exp> exp)
{
    return std::unique_ptr<A_exp_list>(new A_last_exp_list(std::move(exp)));
}

std::unique_ptr<A_stm_list> A_Empty_Stm()
{
    return std::unique_ptr<A_stm_list>(nullptr);
}