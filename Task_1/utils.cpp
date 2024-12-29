#include "utils.h"

#include <iostream>
// 0 - ввод дробного числа >0
// 1 - диалог с пользователем о необходимости продолжать ввод
// 2 - ввод целого числа >0 (добавить static_cast<int> при вызове)
// 3 - ввод целого числа от 1 до 4 (добавить static_cast<int> при вызове)
// 4 - ввод целого числа от 1 до 3 (добавить static_cast<int> при вызове)
// 5 - ввод целого числа от 1 до 7 (добавить static_cast<int> при вызове)
// 6 - ввод года, 7 - месяца, 8 - дня, 9 - часов, 10 - минут (добавить static_cast<int> при вызове)
int correctInputk(int m, int b) {
  if (m == 1 && b == 0) {
    std::cout << "Продолжить ввод?[1 - да / 0 - нет] ";
  }
  if (m == 1 && b == 1) {
    std::cout << "[1 - да / 0 - нет] ";
  }
  int x = 0;
  bool incorrectInput = false;
  do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail() || std::cin.peek() != '\n' ||
        ((m == 2 || m == 3 || m == 4 || m == 5 || m == 6 || m == 7 || m == 8 || m == 9 || m == 10) ? (std::cin.peek() == '.')
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
      if (!(x >= 1 && x <= 4) && incorrectInput == false) {
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
      if (!(x >= 0 && x <= 7) && incorrectInput == false) {
        std::cout << "Некорректный ввод" << std::endl;
        incorrectInput = true;
      }
    }
    if(m == 6){
      if (!(x >= 2024) && incorrectInput == false) {
        std::cout << "Некорректный ввод" << std::endl;
        incorrectInput = true;
      }
    }
    if (m == 7) {
      if (!(x >= 1 && x <= 12) && incorrectInput == false) {
        std::cout << "Некорректный ввод" << std::endl;
        incorrectInput = true;
      }
    }
    if (m == 8) {
      if (!(x >= 1 && x <= 31) && incorrectInput == false) {
        std::cout << "Некорректный ввод" << std::endl;
        incorrectInput = true;
      }
    }
    if (m == 9) {
      if (!(x >= 0 && x <= 23) && incorrectInput == false) {
        std::cout << "Некорректный ввод" << std::endl;
        incorrectInput = true;
      }
    }
    if (m == 10) {
      if (!(x >= 0 && x <= 59) && incorrectInput == false) {
        std::cout << "Некорректный ввод" << std::endl;
        incorrectInput = true;
      }
    }
  } while (incorrectInput);
  return x;
}