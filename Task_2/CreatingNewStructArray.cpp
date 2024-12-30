#include <cstring>

#include "Task_2.h"
#include "utils.h"
buses *CreateArray(int n)  // создание массива n структур
{
  buses *ptr = (buses *)malloc(n * sizeof(buses));
  return ptr;
}

void DeleteArray(buses *ptr)  // удаление массива структур
{
  free(ptr);
}

buses *InputAllStructsUntilInput(
    int &counter) {  // ввод структур до прекращения ввода
                     // пользователем
  buses *ptr = nullptr;
  int i = 0;
  int choice = 1;
  while (choice == 1) {
    std::cout << "\033[2J\033[2H";
    ptr = (buses *)realloc(ptr, (i + 1) * sizeof(buses));

    std::cout << "\nВведите данные для рейса " << i + 1 << "\n\n";

    std::cout << "Введите пункт назначения[80 символов макс.]: ";
    std::cin.ignore();
    std::cin.getline(ptr[i].D, sizeof(ptr[i].D));

    std::cout << "Введите тип автобуса[16 символов макс.]: ";
    std::cin.getline(ptr[i].T, sizeof(ptr[i].T));

    std::cout << "\nВведите дату отправления ";

    std::cout << "\n\nВведите год: ";
    ptr[i].dptr_time.year = correctInputk(6);

    std::cout << "\nВведите месяц: ";
    ptr[i].dptr_time.month = correctInputk(7);

    std::cout << "\nВведите день: ";
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

    std::cout << "\nВведите время прибытия";

    std::cout << "\n\nВведите часы: ";
    ptr[i].arrvl_time.hours = correctInputk(9);

    std::cout << "\nВведите минуты: ";
    ptr[i].arrvl_time.minutes = correctInputk(10);

    // автозаполнение
    ptr[i].id.id = i + 1;
    ptr[i].total_minutes.sum = (((ptr[i].dptr_time.year - 2000) * 365 + ptr[i].dptr_time.month * 30 + ptr[i].dptr_time.day) * 24 + ptr[i].dptr_time.hours) * 60 + ptr[i].dptr_time.minutes;
    choice = correctInputk(1);
    ++i;
  }
  counter = i;
  return ptr;
}

buses *function1(int &counter2) {
  buses *ptr = nullptr;
  int counter = 0;
  ptr = InputAllStructsUntilInput(counter);
  counter2 = counter;
  return ptr;
}
