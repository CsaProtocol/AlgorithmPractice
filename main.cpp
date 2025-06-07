/* ************************************************************************** */

#include <iostream>

#include "container/dictionary.hpp"
#include "zlasdtest/test.hpp"
#include "zmytest/test.hpp"

/* ************************************************************************** */

int main() {
  int choice = 0;
  while (choice != 5) {
    std::cout << "\n\nLasd Libraries 2025" << "\n";
    std::cout << "Seleziona il test da eseguire:" << "\n";
    std::cout << "1. zlasdtest" << "\n";
    std::cout << "2. zmytest - Entire zmytest suite" << "\n";
    std::cout << "3. zmytest Exercise 1" << "\n";
    std::cout << "4. zmytest Exercise 2" << "\n";
    std::cout << "5. Exit" << "\n";
    std::cin >> choice;
    switch(choice) {
    case 1:
      lasdtest();
      break;
    case 2:
      zmytest::mytest();
      break;
    case 3:
      zmytest::mytestex1();
      break;
    case 4:
      zmytest::mytestex2();
      break;
    case 5:
      return 0;
    default:
      std::cout << "Scelta non valida" << "\n";
    }
  }
}