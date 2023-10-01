#pragma once

#include <string>
#include <memory>

typedef enum {A_plus, A_minus, A_mult, A_div} A_binop;

class A_stm {
public:
    ~A_stm() = default;
};

class A_assign_stm : public A_stm {
public:
    A_assign_stm(const std::string &id, std::unique_ptr<A_exp> exp)
        : id(id), exp(std::move(exp)) {}
private:
    std::string id;
    std::unique_ptr<A_exp> exp;
};

class A_print_stm : public A_stm {
public:
    A_print_stm(std::unique_ptr<A_exp_list> exps)
        : exp_list(std::move(exps)) {}
private:
    std::unique_ptr<A_exp_list> exp_list;
};

class A_stm_list {
public:
    A_stm_list()
        : s(std::move(s)), stm_list(std::move(stm_list)) {}
private:
    std::unique_ptr<A_stm> s;
    std::unique_ptr<A_stm_list> stm_list;
};

class A_exp {
public:
    ~A_exp() = default;
};

class A_id_exp : public A_exp {
public:
    A_id_exp(const std::string &id)
        : id(id) {}
private:
    std::string id;
};

class A_num_exp : public A_exp {
public:
    A_num_exp(int num)
        : num(num) {}
private:
    int num;
};

class A_binop_exp : public A_exp {
public:
    A_binop_exp(A_binop op, std::unique_ptr<A_exp> exp1, std::unique_ptr<A_exp> exp2)
        : op(op), exp1(std::move(exp1)), exp2(std::move(exp2)) {}
private:
    A_binop op;
    std::unique_ptr<A_exp> exp1;
    std::unique_ptr<A_exp> exp2;
};

class A_exp_list {
public:
    ~A_exp_list() = default;
};

class A_pair_exp_list : public A_exp_list {
public:
    A_pair_exp_list(std::unique_ptr<A_exp> exp, std::unique_ptr<A_exp_list> exp_list)
        : exp(std::move(exp)), exp_list(std::move(exp_list)) {}
private:
    std::unique_ptr<A_exp> exp;
    std::unique_ptr<A_exp_list> exp_list;
};

class A_last_exp_list : public A_exp_list {
public:
    A_last_exp_list(std::unique_ptr<A_exp> exp)
        : exp(std::move(exp)) {}
private:
    std::unique_ptr<A_exp> exp;
};