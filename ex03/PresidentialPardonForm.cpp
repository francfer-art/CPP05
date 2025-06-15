#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : Aform("PresidentialPardonForm", 25, 5), target(target) {
}
PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm for " << target << " destroyed." << std::endl;
}
void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const {
    if (!getIsSigned()) {
        throw std::runtime_error("Form " + getName() + " is not signed.");
    }
    if (bureaucrat.getGrade() > getExecuteGrade()) {
        throw std::runtime_error("Bureaucrat " + bureaucrat.getName() + " cannot execute form " + getName() + " because their grade is too low.");
    }
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}