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
    ptr = (buses *)realloc(ptr, (i + 1) * sizeof(buses));

    std::cout << "\nВведите данные для рейса " << i + 1 << "\n\n";

    std::cout << "Введите пункт назначения[80 символов макс.]: ";
    std::cin.ignore();
    std::cin.getline(ptr[i].D.destination, sizeof(ptr[i].D.destination));

    std::cout << "Введите тип самолета[16 символов макс.]: ";
    std::cin.getline(ptr[i].T.type, sizeof(ptr[i].T.type));

    std::cout << "Введите время отправления (в часах, дробное): ";
    ptr[i].dptr_time = correctInputk(0);

    std::cout << "Введите время прибытия (в часах, дробное): ";
    ptr[i].arrvl_time = correctInputk(0);

    // автозаполнение
    ptr[i].id = i + 1;
    choice = static_cast<int>(correctInputk(1));
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
