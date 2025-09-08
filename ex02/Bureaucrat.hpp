#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class Aform; // Forward declaration to avoid circular dependency

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
    void signForm(Aform &form) const;
    void executeForm(const Aform &form) const;
};
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);


#endif