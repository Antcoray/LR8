#include "utils.h"

#include <iostream>
// 0 - ввод дробного числа >0
// 1 - диалог с пользователем о необходимости продолжать ввод
// 2 - ввод целого числа >0 (добавить static_cast<int> при вызове)
// 3 - ввод целого числа от 1 до 4 (добавить static_cast<int> при вызове)
// 4 - ввод целого числа от 1 до 3 (добавить static_cast<int> при вызове)
// 5 - ввод целого числа от 1 до 6 (добавить static_cast<int> при вызове)
double correctInputk(int m, int b) {
  if (m == 1 && b == 0) {
    std::cout << "Продолжить ввод?[1 - да / 0 - нет] ";
  }
  if (m == 1 && b == 1) {
    std::cout << "[1 - да / 0 - нет] ";
  }
  double x = 0;
  bool incorrectInput = false;
  do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail() || std::cin.peek() != '\n' ||
        ((m == 2 || m == 3 || m == 4 || m == 5) ? std::cin.peek() == '.'
                                                : false)) {
      std::cin.clear();
      std::cout << "Некорректный ввод" << std::endl;
      std::cin.ignore(1000000, '\n');
      incorrectInput = true;
    }
    if (m == 1) {
      if (x != 1 && x != 0 && incorrectInput == false) {
        std::cout << "Некорректный ввод" << std::endl;
        incorrectInput = true;
      }
    }
    if (m == 2 || m == 0) {
      if (!(x >= 0) && incorrectInput == false) {
        std::cout << "Некорректный ввод" << std::endl;
        incorrectInput = true;
      }
    }
    if (m == 3) {
      if (!(x >= 1 && x <= 3) && incorrectInput == false) {
        std::cout << "Некорректный ввод" << std::endl;
        incorrectInput = true;
      }
    }
    if (m == 4) {
      if (!(x >= 1 && x <= 4) && incorrectInput == false) {
        std::cout << "Некорректный ввод" << std::endl;
        incorrectInput = true;
      }
    }
    if (m == 0) {
      if (!(x >= 0 && x <= 24) && incorrectInput == false) {
        std::cout << "Некорректный ввод" << std::endl;
        incorrectInput = true;
      }
    }
    if (m == 5) {
      if (!(x >= 0 && x <= 6) && incorrectInput == false) {
        std::cout << "Некорректный ввод" << std::endl;
        incorrectInput = true;
      }
    }
  } while (incorrectInput);
  return x;
}