#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Intern someIntern;
        Bureaucrat boss("Boss", 1);

        std::cout << "\n-- Creando formularios válidos --\n";

        Aform* shrubbery = someIntern.makeForm("shrubbery request", "garden");
        Aform* robotomy = someIntern.makeForm("robotomy request", "R2D2");
        Aform* pardon = someIntern.makeForm("presidential pardon", "Ford Prefect");

        if (shrubbery) {
            boss.signForm(*shrubbery);
            boss.executeForm(*shrubbery);
        }

        if (robotomy) {
            boss.signForm(*robotomy);
            boss.executeForm(*robotomy);
        }

        if (pardon) {
            boss.signForm(*pardon);
            boss.executeForm(*pardon);
        }

        std::cout << "\n-- Intentando crear un formulario inválido --\n";
        Aform* unknown = someIntern.makeForm("cake baking request", "kitchen");
        if (unknown) {
            boss.signForm(*unknown);
            boss.executeForm(*unknown);
        }
        delete shrubbery;
        delete robotomy;
        delete pardon;
        delete unknown;

    } catch (const std::exception& e) {
        std::cerr << "Excepción atrapada en main: " << e.what() << std::endl;
    }

    return 0;
}
