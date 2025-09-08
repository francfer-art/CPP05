#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : Aform("RobotomyRequestForm", 72, 45), target(target) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm for " << target << " destroyed." << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const {
    if (!getIsSigned()) {
        throw std::runtime_error("Form " + getName() + " is not signed.");
    }
    if (bureaucrat.getGrade() > getExecuteGrade()) {
        throw std::runtime_error("Bureaucrat " + bureaucrat.getName() + " cannot execute form " + getName() + " because their grade is too low.");
    }

    std::cout << "Drilling noises... ";
    if (rand() % 2 == 0) {
        std::cout << target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed for " << target << "." << std::endl;
    }
}