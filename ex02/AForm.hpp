#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include <cstdlib>

class Bureaucrat;

class Aform {
  private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int executeGrade;
  public:
    Aform(const std::string &name, int signGrade, int executeGrade);
    ~Aform();
    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(const Bureaucrat&bureaucrat);
    void showInfo() const;
    virtual void execute(const Bureaucrat &bureaucrat) const = 0;
};

#endif