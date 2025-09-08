#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
  private:
    const std::string name;
    int grade;
  public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    const std::string &getName() const;
    int getGrade() const;
    void setGrade(int grade);
    void incrementGrade();
    void decrementGrade();
    void signForm(Form &form) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);


#endif