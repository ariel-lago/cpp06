#include "ScalarConverter.hpp"
#include <ostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./ScalarConverter 'string representation of a c++ literal'\n");
        return (1);
    }
    ScalarConverter(argv[1]);
    return 0;
}