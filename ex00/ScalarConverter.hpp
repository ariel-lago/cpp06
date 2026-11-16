#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <exception>
# include <ostream>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& origin);
        ScalarConverter& operator=(const ScalarConverter& rhs);
        ~ScalarConverter();
    public:
        static void convert(const std::string literal);
};

#endif