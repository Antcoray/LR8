#include <iostream>

#include "Task_1.h"
#include "utils.h"

planes* addStructs(planes* ptr, int& counter) {
  if (ptr == nullptr || counter == 0) {
    std::cout << "Массив структур пуст или не существует.\n";
    return nullptr;
  }

  int i = counter;
  int choice = 1;
  while (choice == 1) {
    ptr = (planes*)realloc(ptr, (i + 1) * sizeof(planes));

    std::cout << "Введите данные для рейса " << i + 1 << "\n\n";

    std::cout << "Введите пункт назначения[80 символов макс.]: ";
    std::cin.ignore();
    std::cin.getline(ptr[i].destination, sizeof(ptr[i].destination));

    std::cout << "Введите тип самолета[80 символов макс.]: ";
    std::cin.getline(ptr[i].type, sizeof(ptr[i].type));

    std::cout << "Введите время отбытия (в часах, дробное): ";
    ptr[i].dptr_time.hours = static_cast<int>(correctInputk(0));

    // автозаполнение
    ptr[i].id = i + 1;
    ptr[i].flight_length.minutes =
        15 * ptr[i].id + 200 + static_cast<int>(ptr[i].dptr_time.hours);
    
    std::cout << "Перейти к следующему рейсу?";
    choice = static_cast<int>(correctInputk(1));
    ++i;
  }
  counter = i;
  return ptr;
}
