#ifndef INTER_HPP
#define INTER_HPP

#include "AForm.hpp"

class Intern {
  public:
    Intern();
    ~Intern();
    Aform* makeForm(const std::string &formName, const std::string &target);
};

#endif