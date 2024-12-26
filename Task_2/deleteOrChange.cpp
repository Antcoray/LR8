#include <iostream>

#include "Task_2.h"
#include "utils.h"

buses* DeleteElement(buses* ptr, int& counter, int element) {
  if (ptr == nullptr) {
    std::cout << "Массив структур пустой\n";
    return ptr;
  }
  if (element == 0 || counter < element) {
    std::cout << "Такого элемента нет\n";
    return ptr;
  }
  // Если массив состоит из одного элемента, просто освобождаем память
  if (counter == 1) {
    free(ptr);
    ptr = nullptr;
    counter = 0;
    FILE* f = fopen("data.txt", "w");  // открываем для полной перезаписи файла
    fclose(f);
    return ptr;
  }

  // Сдвигаем все элементы после нужного индекса на одну позицию влево
  for (int i = element - 1; i < counter; ++i) {
    ptr[i] = ptr[i + 1];
  }

  // Уменьшаем размер массива
  --counter;

  ptr = (buses*)realloc(ptr, counter * sizeof(buses));
  // изменяем автовычисляемые поля
  for (int i = 0; i < counter; ++i) {
    ptr[i].id = i + 1;
  }
  return ptr;
}

buses* ChangeElement(buses* ptr, int counter, int element) {
  if (counter < element) {
    std::cout << "Такого элемента нет\n";
    return ptr;
  }
  std::cout << "\nИзмените данные для рейса " << ptr[element - 1].id << "\n\n";
  std::cout << "Что изменить?\n1 - пункт назначения\n2 - тип автобуса\n3 - "
               "время отправления\n4 - время прибытия\n";
  int choice = correctInputk(4);
  switch (choice) {
    case 1:
      std::cout << "Измените пункт назначения[80 символов макс.]: ";
      std::cin.ignore();
      std::cin.getline(ptr[element - 1].D.destination,
                       sizeof(ptr[element - 1].D.destination));
      break;
    case 2:
      std::cout << "Измените тип автобуса[16 символов макс.]: ";
      std::cin.ignore();
      std::cin.getline(ptr[element - 1].T.type,
                       sizeof(ptr[element - 1].T.type));
      break;
    case 3:
      std::cout << "Измените время отправления (в часах, дробное): ";
      ptr[element - 1].arrvl_time = correctInputk(0);
      break;
    case 4:
      std::cout << "Измените время прибытия (в часах, дробное): ";
      ptr[element - 1].arrvl_time = correctInputk(0);
      break;
  }
  return ptr;
}
