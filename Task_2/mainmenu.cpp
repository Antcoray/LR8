#include <iostream>

#include "Task_2.h"
#include "utils.h"

void PrintStructArray(buses *ptr, int n, int minValue) {
  if (ptr == nullptr || n == 0) {
    std::cout << "Массив структур пуст или не существует.\n";
    return;
  }

  std::cout << "Содержимое массива структур:\n\n";
  for (int i = minValue; i < n; ++i) {
    std::cout << "Рейс " << ptr[i].id << "\n";
    std::cout << "Тип автобуса: " << ptr[i].T.type << "\n";
    std::cout << "Пункт назначения: " << ptr[i].D.destination << "\n";
    std::cout << "Время отправления: " << ptr[i].dptr_time << " ч \n";
    std::cout << "Время прибытия: " << ptr[i].arrvl_time << " ч \n";
  }
}

void mainmenu() {
  buses *ptr = nullptr;
  int counter = 0;

  std::cout
      << "Загрузить сохраненные данные?(иначе очистить сохраненный файл)\n";
  int unq = correctInputk(1, 1);

  if (unq == 1) {
    ptr = loadFromFile("data.txt", counter);
  }

  while (true) {
    std::cout
        << "\nВыберите функцию, которую хотите использовать\n1 - создать "
           "новый массив структур\n2 - просмотр содержимого существующего "
           "массива\n3 - дополнение уже существующего массива структур "
           "новыми структурами\n4 - удаление элемента\n5 - изменение "
           "элемента "
           "\n6 - Вывести информацию о рейсах, которыми можно воспользоваться "
           "для прибытия в пункт назначения раньше заданного времени. \n0 - "
           "выйти\n";

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
        std::cout << "Какой элемент вы хотите удалить?\n";
        element = correctInputk(2);
        DeleteElement(ptr, counter, element);
        break;
      case 5:
        std::cout << "Какой элемент вы хотите изменить?\n";
        element = correctInputk(2);
        ChangeElement(ptr, counter, element);
        break;
      case 6:

        quick(ptr, counter);
        break;
      case 0:
        return;
    }
    updateElementInFile("data.txt", ptr, counter);
  }
}