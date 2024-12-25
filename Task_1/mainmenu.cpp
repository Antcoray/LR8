#include <iostream>

#include "Task_1.h"
#include "utils.h"

void PrintStructArray(const planes *ptr, int n, int minValue) {
  if (ptr == nullptr || n == 0) {
    std::cout << "Массив структур пуст или не существует.\n";
    return;
  }

  std::cout << "Содержимое массива структур:\n\n";
  for (int i = minValue; i < n; ++i) {
    std::cout << "Рейс " << ptr[i].id << "\n";
    std::cout << "Тип самолета: " << ptr[i].type << "\n";
    std::cout << "Пункт назначения: " << ptr[i].destination << "\n";
    std::cout << "Время отбытия: " << ptr[i].dptr_time.hours << " ч \n";
    std::cout << "Время полета: " << ptr[i].flight_length.minutes
              << " минут\n\n";
  }
}

void mainmenu() {
  planes *ptr = nullptr;
  int counter = 0;

  while (true) {
    std::cout
        << "\nВыберите функцию, которую хотите использовать\n1 - создать "
           "новый массив структур\n2 - просмотр содержимого существующего "
           "массива\n3 - дополнение уже существующего массива структур "
           "новыми структурами\n4 - поиск и вывод на экран структур с "
           "заданным значением элемента\n5 - удаление и изменение элемента "
           "массива структур с заданным значением элемента\n6 - упорядочение "
           "массива структур по продолжительности полета\n0 - выйти\n";

    int choice = correctInputk(5);

    switch (choice) {
      case 1:
        ptr = function1(counter);
        break;
      case 2:
        PrintStructArray(ptr, counter, 0);
        break;
      case 3:
        addStructs(ptr, counter);
        break;
      case 4:
        FindStruct(ptr, counter);
        break;
    }
  }
}