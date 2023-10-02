#pragma once

#include <string>

int gettok();

enum token {
    TOK_EQ = 0, 
    TOK_PRINT,
    TOK_NUM,
    TOK_ID,
    TOK_EOF,
};

static std::string id;
static double num;