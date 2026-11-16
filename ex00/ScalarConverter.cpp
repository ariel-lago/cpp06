#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <cctype>

namespace {
    enum type {
        T_CHAR,
        T_INT,
        T_FLOAT,
        T_DOUBLE,
        T_INVALID
    };

    bool    isChar(const std::string literal) {
        if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') 
            return true;
        else if (literal.length() == 1 && !isdigit(static_cast<unsigned char>(literal[0])))
            return true;
        return false;
    }

    bool    isInt(const std::string literal) {
        size_t i = 0;
        if (literal[i] == '-' || literal[i] == '+') {
            i++;
        }
        for (; i < literal.length(); i++) {
            if (!isdigit(static_cast<unsigned char>(literal[i])))
                return false;
        }
        return true;
    }

    bool    isDouble(const std::string literal) {
        size_t i = 0;
        bool    dot = 0;
        bool    digit = 0;

        if (literal == "-inf" || literal == "+inf" || literal == "nan")
            return true;
        if (literal[i] == '-' || literal[i] == '+')
            i++;
        for (; i< literal.length(); i++) {
            if (isdigit(static_cast<unsigned char>(literal[i])))
                digit = 1;
            else if (literal[i] == '.' && !dot)
                dot = 1;
            else
                return false;
        }
        return (dot && digit);
    }

    bool    isFloat(const std::string literal) {
        size_t i = 0;
        bool    dot = 0;
        bool    digit = 0;

        if (literal == "-inff" || literal == "+inff" || literal == "nanf")
            return true;
        if (literal[i] == '-' || literal[i] == '+')
            i++;
        if (literal[literal.length() - 1] != 'f')
            return false;
        for (; i< (literal.length() - 1); i++) {
            if (isdigit(static_cast<unsigned char>(literal[i])))
                digit = 1;
            else if (literal[i] == '.' && !dot)
                dot = 1;
            else
                return false;
        }
        return (dot && digit);
    }
    
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& origin) {(void)origin;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
    (void)rhs;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string literal) { 

}