#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  try {
    Bureaucrat b("Alice", 50);
    Form f("NDA", 30, 20);
    f.showInfo();
    b.signForm(f); // Alice no puede firmarlo (grade 50 > signGrade 30)

    Bureaucrat boss("Bob", 30);
    boss.signForm(f); // Bob sí puede

    // Intentar firmarlo otra vez
    boss.signForm(f); // Ya está firmado

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}
