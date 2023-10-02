#include "lexer.h"

//------------------------
// Lexer
//------------------------

int gettok() {
    static int last_char = ' ';

    while(isspace(last_char))
        last_char = getchar();
    
    if(last_char == '#') {
        do
            last_char = getchar();
        while(last_char != EOF && last_char != '\n');
        if(last_char != EOF)
            return gettok();
    }

    if(isdigit(last_char)) {
        std::string num_str;
        do {
            num_str += last_char;
            last_char = getchar();
        } while(isdigit(last_char) || last_char == '.');

        num = strtod(num_str.c_str(), 0);
        return TOK_NUM;
    }

    if(isalpha(last_char)) {
        id = last_char;
        while(isalnum(last_char = getchar()))
            id += last_char;
        if(id == "print")
            return TOK_PRINT;
        return TOK_ID;
    }

    if(last_char == '=')
        return TOK_EQ;

    if(last_char == EOF)
        return TOK_EOF;

    int this_char = last_char;
    last_char = getchar();
    return this_char;
}