#include <iostream>

#include "Task_2.h"
#include "utils.h"

buses* addStructs(buses* ptr, int& counter) {
  if (ptr == nullptr || counter == 0) {
    std::cout << "\033[2J\033[2H";
    std::cout << "Массив структур пуст или не существует.\n";
    CONTINUE();
    return nullptr;
  }

  int i = counter;
  int choice = 1;
  while (choice == 1) {
    std::cout << "\033[2J\033[2H";
    ptr = (buses*)realloc(ptr, (i + 1) * sizeof(buses));

    std::cout << "Введите данные для рейса " << i + 1 << "\n\n";

    std::cout << "Введите пункт назначения[80 символов макс.]: ";
    std::cin.ignore();
    std::cin.getline(ptr[i].D, sizeof(ptr[i].D));

    std::cout << "Введите тип автобуса[16 символов макс.]: ";
    std::cin.getline(ptr[i].T, sizeof(ptr[i].T));

    std::cout << "\nВведите дату отправления ";

    std::cout << "\n\nВведите год: ";
    ptr[i].dptr_time.year = correctInputk(6);

    std::cout << "\n\nВведите месяц: ";
    ptr[i].dptr_time.month = correctInputk(7);

    std::cout << "\n\nВведите день: ";
    ptr[i].dptr_time.day = correctInputk(8);

    std::cout << "Введите время отправления";

    std::cout << "\n\nВведите часы: ";
    ptr[i].dptr_time.hours = correctInputk(9);

    std::cout << "\n\nВведите минуты: ";
    ptr[i].dptr_time.minutes = correctInputk(10);

    std::cout << "\nВведите дату прибытия ";
    std::cout << "\n\nВведите год: ";
    ptr[i].arrvl_time.year = correctInputk(6);

    std::cout << "\nВведите месяц: ";
    ptr[i].arrvl_time.month = correctInputk(7);

    std::cout << "\nВведите день: ";
    ptr[i].arrvl_time.day = correctInputk(8);

    std::cout << "Введите время прибытия";

    std::cout << "\n\nВведите часы: ";
    ptr[i].arrvl_time.hours = correctInputk(9);

    std::cout << "\nВведите минуты: ";
    ptr[i].arrvl_time.minutes = correctInputk(10);

    // автозаполнение
    ptr[i].id.id = i + 1;
    ptr[i].total_minutes.sum = (((ptr[i].arrvl_time.year - 2000) * 365 + ptr[i].arrvl_time.month * 30 + ptr[i].arrvl_time.day) * 24 + ptr[i].arrvl_time.hours) * 60 + ptr[i].arrvl_time.minutes;
    std::cout << "Перейти к следующему рейсу?";
    choice = correctInputk(1);
    ++i;
  }
  counter = i;
  return ptr;
}
