#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>

Base* generate(void) { 
    int random = std::rand() % 3;
    if (random == 0)
        return(new A());
    else if (random == 1)
        return(new B());
    else
        return(new C());
}

void    identify(Base* p) {
    if (!p)
        return;
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
    return;
}

void    identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
    } catch (const std::exception&) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
    } catch (const std::exception&) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
    } catch (const std::exception&) {}
}

int main(void) {
    std::srand(std::time(NULL));
    Base* test1 = generate();
    std::cout << "Pointer identify: ";
    identify(test1);
    std::cout << "Reference identify: ";
    identify(*test1);
    delete (test1);
    return (0);
}