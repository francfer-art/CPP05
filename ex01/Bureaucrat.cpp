#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Default Bureaucrat"), grade(150) {

}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
    if (grade < 1)
        throw std::invalid_argument("Grade cannot be less than 1");
    else if (grade > 150)
        throw std::invalid_argument("Grade cannot be greater than 150");
    this->grade = grade;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat " << this->name << " destroyed." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if(this != &other) {
      this->grade = other.grade;
    }
    return *this;
}

const std::string &Bureaucrat:: getName() const {
  return this->name;
}

int Bureaucrat::getGrade() const {
  return this->grade;
}

void Bureaucrat::setGrade(int grade) {
  if (grade < 1) {
    throw std::invalid_argument("Grade cannot be less than 1");
  } else if (grade > 150) {
    throw std::invalid_argument("Grade cannot be greater than 150");
  }
  this->grade = grade;
}

void Bureaucrat::incrementGrade() {
  if (this->grade <= 1) {
    throw std::out_of_range("Cannot increment grade above 1");
  }
  this->grade--;
}

void Bureaucrat::decrementGrade() {
  if (this->grade >= 150) {
    throw std::out_of_range("Cannot decrement grade below 150");
  }
  this->grade++;
}

void Bureaucrat::showInfo() const {
  std::cout << this->name << ", bureaucrat grade " << this->grade << std::endl;
}

void Bureaucrat::signForm(Form &form) const {
  try {
    form.beSigned(*this);
  } catch(const std::exception &e) {
    std::cerr << this->name << " cannot sign form " << form.getName() << " because: " << e.what() << std::endl;
  }
}