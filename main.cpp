#include <iostream>
#include <string>
#include <vector>

#include "tokenizer.hpp"

struct var {
    std::string name;
    std::string val;
};

int main() {
    bool repeat = true;
    std::vector<var> variables;

    while(repeat) {
        std::string input;

        std::cout << ">";
        std::cin >> input;

        std::vector<Token> tokens = tokenize(input);

        for(auto& token : tokens) {
            std::cout << token << std::endl;
        }
    }

    return 0;
}