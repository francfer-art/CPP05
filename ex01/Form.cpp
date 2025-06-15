#include "Form.hpp"
#include "Bureaucrat.hpp"

std::string Form::getName() const {
  return name;
}

bool Form::getIsSigned() const {
  return isSigned;
}

int Form::getSignGrade() const {
  return signGrade;
}

int Form::getExecuteGrade() const {
  return executeGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > signGrade) {
    throw std::runtime_error("Bureaucrat " + bureaucrat.getName() + " cannot sign form " + name + " because their grade is too low.");
  } else {
    isSigned = true;
    std::cout << bureaucrat.getName() << " signs form " << name << "." << std::endl;
  }
}

Form::Form(const std::string &name, int signGrade, int executeGrade)
  : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) {
  if (signGrade < 1 || executeGrade < 1) {
    throw std::invalid_argument("Sign and execute grades must be at least 1.");
  }
  if (signGrade > 150 || executeGrade > 150) {
    throw std::invalid_argument("Sign and execute grades must not exceed 150.");
  }
}

Form::~Form() {
  std::cout << "Form " << name << " destroyed." << std::endl;
}

void Form::showInfo() const {
  std::cout << "Form Information:" << std::endl;
  std::cout << "Form Name: " << name << std::endl;
  std::cout << "Is Signed: " << (isSigned ? "Yes" : "No") << std::endl;
  std::cout << "Sign Grade: " << signGrade << std::endl;
  std::cout << "Execute Grade: " << executeGrade << std::endl;
  std::cout << "--------------------------------" << std::endl;
}