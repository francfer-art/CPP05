#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Aform {
  private:
    std::string target;
  public:
    RobotomyRequestForm(const std::string &target);
    ~RobotomyRequestForm();

    void execute(const Bureaucrat &bureaucrat) const;

    // Additional methods can be added here if needed
};

#endif