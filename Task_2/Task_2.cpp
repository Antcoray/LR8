#include "Task_2.h"

#include <cstring>

#include "utils.h"

void mainintro() {
  std::string info = R"(
    ___________________________________________
    | Лабораторная работа 8. Задание 2        |
    |-----------------------------------------|
    |Выполнил студент группы 453501           |
    |Колесников Антон Сергеевич               |
    |Вариант 12                               |
    |_________________________________________|
    
    )";

  std::cout << info << "\n\n";
}

int main() {
  mainintro();
  mainmenu();
  return 0;
}