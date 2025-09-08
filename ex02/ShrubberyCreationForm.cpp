#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : Aform("ShrubberyCreationForm", 145, 137), target(target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm for " << target << " destroyed." << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const {
    if (!getIsSigned()) {
        throw std::runtime_error("Form " + getName() + " is not signed.");
    }
    if (bureaucrat.getGrade() > getExecuteGrade()) {
        throw std::runtime_error("Bureaucrat " + bureaucrat.getName() + " cannot execute form " + getName() + " because their grade is too low.");
    }
    std::ofstream file((target + "_shrubbery").c_str());
    if (file.is_open()) {
        file << "      🌲\n"
             << "     🌳🌳\n"
             << "    🌲🌲🌲\n"
             << "   🌳🌳🌳🌳\n"
             << "      ||\n";
        file.close();
    }
}