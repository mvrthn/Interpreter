#include "tokenizer.hpp"

std::vector<Token> tokenize(std::string& str) {
    std::vector<Token> tokens;
    std::stringstream buff;
    int len = str.length();
    int i;
    for(i = 0; i < len; i++) {
        char c = str[i];
        if(std::isalpha(c)) {
            buff << c;
            while(++i < len && std::isalnum(str[i])) {
                buff << str[i];
            }
            std::string s = buff.str();
            buff.clear();
            if(s == "quit") {
                tokens.push_back({.type = TokenType::quit});
            }
            else if(s == "let") {
                tokens.push_back({.type = TokenType::let});
            }
            else if(s == "cls" || s == "clear") {
                tokens.push_back({.type = TokenType::cls});
            }
            else {
                tokens.push_back({.type = TokenType::str, .val = s});
            }
            if(i == len) {
                break;
            }
            i--;
        }
        else if(std::isdigit(c)) {
            buff << c;
            while(++i < len && std::isdigit(str[i])) {
                buff << str[i];
            }
            if(i < len && std::isalpha(str[i])) {
                break;
            }
            tokens.push_back({.type = TokenType::num, .val = buff.str()});
            buff.clear();
            if(i == len) {
                break;
            }
            i--;
        }
        else if(c == '=') {
            tokens.push_back({.type = TokenType::eq});
        }
        else if(std::isspace(c)) {
            continue;
        }
        else {
            break;
        }
    }
    if(i < len) {
        std::cout << "Invalid syntax\n" << str << std::endl;
        for(int j = 0; j < i; i++) {
            std::cout << " ";
        }
        std::cout << "^\n\n";
        return {};
    }
    return tokens;
}