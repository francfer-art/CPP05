#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 42);
        b1.showInfo();

        b1.incrementGrade();
        b1.showInfo();

        b1.decrementGrade();
        b1.showInfo();

        std::cout << "--------------------------" << std::endl;

        Bureaucrat b2("Bob", 150);
        b2.showInfo();

        b2.decrementGrade();
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;

    try {
        Bureaucrat b3("Charlie", 0);
    } catch (const std::exception &e) {
        std::cerr << "Exception caught while creating Charlie: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("Diana", 200);
    } catch (const std::exception &e) {
        std::cerr << "Exception caught while creating Diana: " << e.what() << std::endl;
    }

    return 0;
}
