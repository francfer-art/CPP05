#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  try {
    Bureaucrat b("Alice", 50);
    Form f("NDA", 30, 20);
    std::cout << b << std::endl;
    b.signForm(f);

    Bureaucrat boss("Bob", 30);
    boss.signForm(f);

    boss.signForm(f);

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}
