#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
  std::cout << "Intern created." << std::endl;
}

Intern::~Intern() {
  std::cout << "Intern destroyed." << std::endl;
}

static Aform* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static Aform* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static Aform* createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

Aform* Intern::makeForm(const std::string &formName, const std::string &target){
   const std::string names[] = {
        "shrubbery request",
        "robotomy request",
        "presidential pardon"
    };

    Aform* (*creators[])(const std::string&) = {
        createShrubbery,
        createRobotomy,
        createPresidential
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == names[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target);
        }
    }

    std::cout << "Intern can't create form: " << formName << std::endl;
    return NULL;
}
