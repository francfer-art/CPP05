#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration to avoid circular dependency

class Form {
  private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int executeGrade;
  public:
    Form(const std::string &name, int signGrade, int executeGrade);
    ~Form();
    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(const Bureaucrat&bureaucrat);
    void showInfo() const;
};

#endif