#include <iostream>

#include "Task_1.h"
#include "utils.h"

planes* DeleteElement(planes* ptr, int& counter, int element) {
  if (ptr == nullptr) {
    std::cout << "\033[2J\033[2H";
    std::cout << "Массив структур пустой\n";
    CONTINUE();
    return ptr;
  }
  if (element == 0 || counter < element) {
    std::cout << "\033[2J\033[2H";
    std::cout << "Такого элемента нет\n";
    CONTINUE();
    return ptr;
  }
  // Если массив состоит из одного элемента, просто освобождаем память
  if (counter == 1) {
    free(ptr);
    ptr = nullptr;
    counter = 0;
    FILE* f = fopen("data.bin", "w");  // открываем для полной перезаписи файла
    fclose(f);
    return ptr;
  }

  // Сдвигаем все элементы после нужного индекса на одну позицию влево
  for (int i = element - 1; i < counter; ++i) {
    ptr[i] = ptr[i + 1];
    updateElementInFile("data.bin", &ptr[i], i);
  }

  // Уменьшаем размер массива
  --counter;

  ptr = (planes*)realloc(ptr, counter * sizeof(planes));
  // изменяем автовычисляемые поля
  for (int i = 0; i < counter; ++i) {
    ptr[i].id = i + 1;
    ptr[i].flight_length.total_minutes =
        15 * ptr[i].id + 200 + ptr[i].date.TIME.hours;
    updateElementInFile("data.bin", &ptr[i], i);
  }
  updateElementCount("data.bin", counter);
  return ptr;
}

planes* ChangeElement(planes* ptr, int counter, int element) {
  std::cout << "\033[2J\033[2H";
  if (counter < element) {
    std::cout << "Такого элемента нет\n";
    CONTINUE();
    return ptr;
  }
  std::cout << "\nИзмените данные для рейса " << ptr[element - 1].id << "\n\n";
  std::cout << "Что изменить?\n1 - пункт назначения\n2 - тип самолета\n3 - дату и "
               "время отправления\n";
  int choice = correctInputk(4);
  switch (choice) {
    case 1:
      std::cout << "Измените пункт назначения[80 символов макс.]: ";
      std::cin.ignore();
      std::cin.getline(ptr[element - 1].destination,
                       sizeof(ptr[element - 1].destination));
      break;
    case 2:
      std::cout << "Измените тип самолета[80 символов макс.]: ";
      std::cin.ignore();
      std::cin.getline(ptr[element - 1].type, sizeof(ptr[element - 1].type));
      break;
    case 3:
      std::cout << "Измените дату и время отправления ";
      std::cout << "\n\nВведите год: ";
      ptr[element - 1].date.year = correctInputk(6);

      std::cout << "\nВведите месяц: ";
      ptr[element - 1].date.month = correctInputk(7);

      std::cout << "\nВведите день: ";
      ptr[element - 1].date.day = correctInputk(8);

      std::cout << "\nВведите время отправления";

      std::cout << "\n\nВведите часы: ";
      ptr[element - 1].date.TIME.hours = correctInputk(9);

      std::cout << "\nВведите минуты: ";
      ptr[element - 1].date.TIME.minutes = correctInputk(10);
      break;
  }

  for (int i = 0; i < counter; ++i) {
    ptr[i].flight_length.total_minutes =
        15 * ptr[i].id + 200 + ptr[i].date.TIME.hours;
  }
  updateElementInFile("data.bin", &ptr[element - 1], element - 1);
  return ptr;
}
