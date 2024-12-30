#include <iostream>

#include "Task_2.h"
#include "utils.h"

buses* DeleteElement(buses* ptr, int& counter, int element) {
  if (ptr == nullptr) {
    std::cout << "\033[2J\033[2H";
    std::cout << "Массив структур пустой\n";
    CONTINUE();
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
    ptr[i].id.id = i + 1;
  }
  return ptr;
}

buses* ChangeElement(buses* ptr, int counter, int element) {
  if (counter < element) {
    std::cout << "\033[2J\033[2H";
    std::cout << "Такого элемента нет\n";
    CONTINUE();
    return ptr;
  }
  std::cout << "\033[2J\033[2H";
  std::cout << "\nИзмените данные для рейса " << ptr[element - 1].id.id << "\n\n";
  std::cout << "Что изменить?\n1 - пункт назначения\n2 - тип автобуса\n3 - "
               "время отправления\n4 - время прибытия\n";
  int choice = correctInputk(3);
  switch (choice) {
    case 1:
      std::cout << "Измените пункт назначения[80 символов макс.]: ";
      std::cin.ignore();
      std::cin.getline(ptr[element - 1].D,
                       sizeof(ptr[element - 1].D));
      break;
    case 2:
      std::cout << "Измените тип автобуса[16 символов макс.]: ";
      std::cin.ignore();
      std::cin.getline(ptr[element - 1].T,
                       sizeof(ptr[element - 1].T));
      break;
    case 3:
    std::cout << "\nИзмените дату отправления ";

    std::cout << "\n\nВведите год: ";
    ptr[element - 1].dptr_time.year = correctInputk(6);

    std::cout << "\n\nВведите месяц: ";
    ptr[element - 1].dptr_time.month = correctInputk(7);

    std::cout << "\n\nВведите день: ";
    ptr[element - 1].dptr_time.day = correctInputk(8);

    std::cout << "\nИзмените время отправления";

    std::cout << "\n\nВведите часы: ";
    ptr[element - 1].dptr_time.hours = correctInputk(9);

    std::cout << "\nВведите минуты: ";
    ptr[element - 1].dptr_time.minutes = correctInputk(10);
    break;
    case 4:
    std::cout << "\nИзмените дату прибытия ";

    std::cout << "\n\nВведите год: ";
    ptr[element - 1].arrvl_time.year = correctInputk(6);

    std::cout << "\nВведите месяц: ";
    ptr[element - 1].arrvl_time.month = correctInputk(7);

    std::cout << "\nВведите день: ";
    ptr[element - 1].arrvl_time.day = correctInputk(8);

    std::cout << "\nИзмените время прибытия";

    std::cout << "\n\nВведите часы: ";
    ptr[element - 1].arrvl_time.hours = correctInputk(9);

    std::cout << "\nВведите минуты: ";
    ptr[element - 1].arrvl_time.minutes = correctInputk(10);
    // avtozapolnenie
    ptr[element - 1].total_minutes.sum = (((ptr[element - 1].arrvl_time.year - 2000) * 365 + ptr[element - 1].arrvl_time.month * 30 + ptr[element - 1].arrvl_time.day) * 24 + ptr[element - 1].arrvl_time.hours) * 60 + ptr[element - 1].arrvl_time.minutes;
    break;
  }
  return ptr;
}
