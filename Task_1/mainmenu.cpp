#include <iostream>

#include "Task_1.h"
#include "utils.h"

void CONTINUE() {
  std::cout << "Введите любой символ чтобы продолжить...";
  std::string a;
  std::cin >> a;
}

void PrintStructArray(const planes *ptr, int n, int minValue, int f) {
  if (ptr == nullptr || n == 0) {
    std::cout << "\033[2J\033[2H";
    std::cout << "Массив структур пуст или не существует.\n";
    CONTINUE();
    return;
  }
  if(f == 0){
  std::cout << "\033[2J\033[2H";
  }
  std::cout << "Содержимое массива структур:\n\n";
  for (int i = minValue; i < n; ++i) {
    std::cout << "Рейс " << ptr[i].id << "\n";
    std::cout << "Тип самолета: " << ptr[i].type << "\n";
    std::cout << "Пункт назначения: " << ptr[i].destination << "\n";
    std::cout << "Время отбытия: " << ptr[i].date.TIME.hours << " ч " << ptr[i].date.TIME.minutes << " мин " << ptr[i].date.day << "." << ptr[i].date.month << "." << ptr[i].date.year << "\n";
    std::cout << "Время полета: " << ptr[i].flight_length.total_minutes
              << " минут\n\n";
  }
  if(f == 0){
  CONTINUE();
  }
}

void mainmenu() {
  planes *ptr = nullptr;
  int counter = 0;

  std::cout
      << "Загрузить сохраненные данные?(иначе очистить сохраненный файл)\n";
  int unq = correctInputk(1, 1);

  if (unq == 1) {
    ptr = loadFromFile("data.bin", counter);
  } else {
    FILE *f = fopen("data.bin", "w");  // открываем для полной перезаписи файла
    fclose(f);
  }
  while (true) {
    std::cout << "\033[2J\033[2H";
    std::cout
        << "\nВыберите функцию, которую хотите использовать\n1 - создать "
           "новый массив структур\n2 - просмотр содержимого существующего "
           "массива\n3 - дополнение уже существующего массива структур "
           "новыми структурами\n4 - поиск и вывод на экран структур с "
           "заданным значением элемента\n5 - удаление элемента\n6 - изменение "
           "элемента "
           "\n7 - упорядочение "
           "массива структур по продолжительности полета в заданный пункт "
           "назначения\n0 - выйти\n";

    int choice = correctInputk(5);
    int element = -1;

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
      case 5:
        std::cout << "Какой элемент вы хотите удалить?\n";
        element = correctInputk(2);
        DeleteElement(ptr, counter, element);
        break;
      case 6:
        std::cout << "Какой элемент вы хотите изменить?\n";
        element = correctInputk(2);
        ChangeElement(ptr, counter, element);
        break;
      case 7:
        quick(ptr, counter);
        break;
      case 0:
        return;
    }
  }
}