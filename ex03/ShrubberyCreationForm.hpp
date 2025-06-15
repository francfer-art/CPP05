#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class ShrubberyCreationForm : public Aform {
  private:
    std::string target;
  public:
    ShrubberyCreationForm(const std::string &target);
    ~ShrubberyCreationForm();
    
    void execute(const Bureaucrat &bureaucrat) const;
};

#endif