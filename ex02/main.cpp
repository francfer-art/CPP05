#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1); // Grade 1 = máxima autoridad

        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Marvin");

        // ---------- Shrubbery ----------
        std::cout << "\n-- Intento de ejecución sin firmar (Shrubbery) --\n";
        try {
            bob.executeForm(shrubbery);
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        std::cout << "\n-- Firmando el formulario Shrubbery --\n";
        bob.signForm(shrubbery);

        std::cout << "\n-- Ejecutando el formulario Shrubbery --\n";
        bob.executeForm(shrubbery);

        // ---------- Robotomy ----------
        std::cout << "\n-- Firmando el formulario Robotomy --\n";
        bob.signForm(robotomy);

        std::cout << "\n-- Ejecutando el formulario Robotomy (varias veces para ver el azar) --\n";
        for (int i = 0; i < 5; ++i)
            bob.executeForm(robotomy);

        // ---------- Pardon ----------
        std::cout << "\n-- Firmando el formulario Presidential Pardon --\n";
        bob.signForm(pardon);

        std::cout << "\n-- Ejecutando el formulario Presidential Pardon --\n";
        bob.executeForm(pardon);

    } catch (const std::exception& e) {
        std::cerr << "Excepción general: " << e.what() << std::endl;
    }

    return 0;
}
