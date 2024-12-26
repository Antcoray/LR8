#include <iostream>

#include "Task_2.h"
#include "utils.h"

buses* addStructs(buses* ptr, int& counter) {
  if (ptr == nullptr || counter == 0) {
    std::cout << "Массив структур пуст или не существует.\n";
    return nullptr;
  }

  int i = counter;
  int choice = 1;
  while (choice == 1) {
    ptr = (buses*)realloc(ptr, (i + 1) * sizeof(buses));

    std::cout << "Введите данные для рейса " << i + 1 << "\n\n";

    std::cout << "Введите пункт назначения[80 символов макс.]: ";
    std::cin.ignore();
    std::cin.getline(ptr[i].D.destination, sizeof(ptr[i].D.destination));

    std::cout << "Введите тип автобуса[16 символов макс.]: ";
    std::cin.getline(ptr[i].T.type, sizeof(ptr[i].T.type));

    std::cout << "Введите время отправления (в часах, дробное): ";
    ptr[i].dptr_time = correctInputk(0);

    std::cout << "Введите время прибытия (в часах, дробное): ";
    ptr[i].arrvl_time = correctInputk(0);

    // автозаполнение
    ptr[i].id = i + 1;
    updateElementInFile("data.bin", &ptr[i], i);
    std::cout << "Перейти к следующему рейсу?";
    choice = static_cast<int>(correctInputk(1));
    ++i;
  }
  counter = i;
  updateElementInFile("data.txt", ptr, counter);
  return ptr;
}
