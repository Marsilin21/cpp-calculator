#include <string>
#include <cmath>
#include "calculator.h"

bool ReadNumber(Number &result) {
    if (!(std::cin >> result)) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }
    return true;
}


bool RunCalculatorCycle(){

    Number result = 0;
    if (!ReadNumber(result)) {
        return false;
    }
    
    Number memory = 0;
    bool has_memory = false;

    std::string cmd;

    while (std::cin >> cmd) {
        if (cmd == "q") {
            return true;
        } else if (cmd == "=") {
            std::cout << result << std::endl;
        } else if (cmd == "c") {
            result = 0;
        } else if (cmd == ":") {
            Number arg;
            if (!(std::cin >> arg)) {
                std::cerr << "Error: Numeric operand expected" << std::endl;
                return false;
            }
            result = arg;
        } else if (cmd == "+") {
            Number arg;
            if (!(std::cin >> arg)) {
                std::cerr << "Error: Numeric operand expected" << std::endl;
                return false;
            }
            result += arg;
        } else if (cmd == "-") {
            Number arg;
            if (!(std::cin >> arg)) {
                std::cerr << "Error: Numeric operand expected" << std::endl;
                return false;
            }
            result -= arg;
        } else if (cmd == "*") {
            Number arg;
            if (!(std::cin >> arg)) {
                std::cerr << "Error: Numeric operand expected" << std::endl;
                return false;
            }
            result *= arg;
        } else if (cmd == "/") {
            Number arg;
            if (!(std::cin >> arg)) {
                std::cerr << "Error: Numeric operand expected" << std::endl;
                return false;
            }
            result /= arg; 
        } else if (cmd == "**") {
            Number arg;
            if (!(std::cin >> arg)) {
                std::cerr << "Error: Numeric operand expected" << std::endl;
                return false;
            }
            result = std::pow(result, arg);
        } else if (cmd == "s") {
            memory = result;
            has_memory = true;
        } else if (cmd == "l"){
            if (!has_memory){
                std::cerr << "Error: Memory is empty" <<std::endl;
                return false;
            }else {
                result = memory;
            }
        }else {
            std::cerr << "Error: Unknown token " << cmd << std::endl;
            return false;
        }
    }
    return true;
}