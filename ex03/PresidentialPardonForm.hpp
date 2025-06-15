#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Aform {
  private:
    std::string target;

  public:
    PresidentialPardonForm(const std::string &target);
    ~PresidentialPardonForm();

    void execute(const Bureaucrat &bureaucrat) const;
    // Additional methods can be added here if needed
};

#endif