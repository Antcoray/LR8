#include <cstring>
#include <iostream>

#include "Task_1.h"
#include "utils.h"

// Функция для обмена элементов в массиве
void swap(planes& a, planes& b) {
  planes temp = a;
  a = b;
  b = temp;
}

// Разделение массива
int partition(planes* ptr, int low, int high) {
  // Выбираем опорный элемент (например, последний элемент массива)
  int p = ptr[high].flight_length.total_minutes;
  int i = low - 1;

  // Проходим по массиву и перемещаем элементы, меньшие опорного, влево
  for (int j = low; j <= high - 1; j++) {
    if (ptr[j].flight_length.total_minutes < p) {  // Сравниваем по полю flight_length
      i++;  // Увеличиваем индекс меньшего элемента
      swap(ptr[i], ptr[j]);  // Меняем местами элементы
    }
  }

  // Перемещаем опорный элемент на правильную позицию
  swap(ptr[i + 1], ptr[high]);
  return i + 1;
}

// Основная функция быстрой сортировки
void quickSort(planes* ptr, int low, int high) {
  if (low < high) {
    // Находим индекс опорного элемента
    int pi = partition(ptr, low, high);

    quickSort(ptr, low, pi - 1);  // Сортировка левой части
    quickSort(ptr, pi + 1, high);  // Сортировка правой части
  }
}

void printarray(planes* ptr, int size, char destination[80]) {
  int j = 0;
  for (int i = 0; i < size; ++i) {
    if (std::strcmp(ptr[i].destination, destination) == 0) {
      std::cout << "Рейс " << ptr[i].id << "\n";
      std::cout << "Тип самолета: " << ptr[i].type << "\n";
      std::cout << "Пункт назначения: " << ptr[i].destination << "\n";
      std::cout << "Время отбытия: " << ptr[i].date.TIME.hours << " ч " << ptr[i].date.TIME.minutes << " мин " << ptr[i].date.day << "." << ptr[i].date.month << "." << ptr[i].date.year << "\n";
      std::cout << "Время полета: " << ptr[i].flight_length.total_minutes
                << " минут\n\n";
      ++j;
    }
  }

  if (j == 0) {
    std::cout << "Нужные рейсы не найдены\n\n";
  }
}

void quick(planes* ptr, int counter) {
  std::cout << "\033[2J\033[2H";
  if (counter < 1) {
    std::cout << "массив слишком мал для сортировки\n";
    CONTINUE();
    return;
  }
  planes* NewPtr = ptr;

  char destination[80];

  quickSort(NewPtr, 0, counter - 1);

  std::cout << "Введите нужный пункт назначения\n";
  std::cin.ignore();
  std::cin.getline(destination, sizeof(destination));

  std::cout << "\nОтсортированный массив по продолжительности полета(по возрастанию):\n";
  printarray(NewPtr, counter, destination);
  CONTINUE();
}