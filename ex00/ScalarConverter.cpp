#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <cerrno>

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
    type    find_type(const std::string literal) {
        if (literal.empty())
            return T_INVALID;
        else if (isChar(literal))
            return T_CHAR;
        else if (isInt(literal))
            return T_INT;
        else if (isDouble(literal))
            return T_DOUBLE;
        else if (isFloat(literal))
            return T_FLOAT;
        return T_INVALID;
    }
    
    void    convert_char(const std::string& literal) {
        char    c = (literal.length() == 3)? literal[1] : literal[0];
        std::cout << "char: " << c << std::endl; 
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f\n";
        std::cout << "double: " << static_cast<double>(c) << std::endl;
    }

    void    convert_int(const std::string& literal) {
        errno = 0;
        long    lit = std::strtol(literal.c_str(), NULL, 10);
        if (errno == ERANGE || lit < INT_MIN || lit > INT_MAX) {
            std::cout << "char: impossible\n"
                    << "int: impossible\n"
                    << "float: impossible\n"
                    << "double: impossible" << std::endl;
            return;
        }
        int i = static_cast<int>(lit);
        std::cout << "char: " << static_cast<char>(i) << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << static_cast<float>(i) << "f\n";
        std::cout << "double: " << static_cast<double>(i) << std::endl;
    }

    void    convert_double(const std::string& literal) {
        double  d = std::strtod(literal.c_str(), NULL);
        std::cout << "char: " << static_cast<char>(d) << std::endl; 
        std::cout << "int: " << static_cast<int>(d) << std::endl;
        std::cout << "float: " << static_cast<float>(d) << "f\n";
        std::cout << "double: " << d << std::endl;
    }

    void    convert_float(const std::string& literal) {
        float   f = static_cast<float>(std::strtod(literal.c_str(), NULL));
        std::cout << "char: " << static_cast<char>(f) << std::endl; 
        std::cout << "int: " << static_cast<int>(f) << std::endl;
        std::cout << "float: " << f << "f\n";
        std::cout << "double: " << static_cast<double>(f) << std::endl;
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
    type data = find_type(literal);
    switch (data) {
        case    T_INVALID:
            std::cout << "Error: invalid string literal\n";
            break;
        case    T_CHAR:
            convert_char(literal);
            break;
        case    T_INT:
            convert_int(literal);
            break;
        case    T_DOUBLE:
            convert_double(literal);
            break;
        case    T_FLOAT:
            convert_float(literal);
            break;
    }
}