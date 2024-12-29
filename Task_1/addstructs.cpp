#include <iostream>

#include "Task_1.h"
#include "utils.h"

planes* addStructs(planes* ptr, int& counter) {
  if (ptr == nullptr || counter == 0) {
    std::cout << "Массив структур пуст или не существует.\n";
    return nullptr;
  }
  std::cout << "\033[2J\033[2H";
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

    std::cout << "\nВведите дату отправления";

    std::cout << "\n\nВведите год: ";
    ptr[i].date.year = correctInputk(6);

    std::cout << "\n\nВведите месяц: ";
    ptr[i].date.month = correctInputk(7);

    std::cout << "\nВведите день: ";
    ptr[i].date.day = correctInputk(8);

    std::cout << "Введите время отправления";

    std::cout << "\n\nВведите часы: ";
    ptr[i].date.TIME.hours = correctInputk(9);

    std::cout << "\n\nВведите минуты: ";
    ptr[i].date.TIME.minutes = correctInputk(10);

    // автозаполнение остальных полей
    ptr[i].id = i + 1;
    ptr[i].flight_length.total_minutes =
        15 * ptr[i].id + 200 + ptr[i].date.TIME.hours;
    updateElementInFile("data.bin", &ptr[i], i);
    std::cout << "Перейти к следующему рейсу?";
    choice = correctInputk(1);
    ++i;
  }
  counter = i;
  updateElementCount("data.bin", counter);
  return ptr;
}
