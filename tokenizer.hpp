#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

enum TokenType {
    quit, let, eq, str, num, cls
};

struct Token {
    TokenType type;
    std::string val = "";

    inline friend std::ostream& operator<<(std::ostream& os, const Token& token) {
        return os << "[" << token.type << "]";
    }
};

std::vector<Token> tokenize(std::string&);

