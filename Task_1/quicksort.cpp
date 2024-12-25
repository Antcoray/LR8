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

// Разделение массива и возвращение индекса опорного элемента
int partition(planes* ptr, int low, int high) {
  // Выбираем опорный элемент (например, последний элемент массива)
  int p = ptr[high].dptr_time.hours;  // Сортировка по полю `id`
  int i = low - 1;

  // Проходим по массиву и перемещаем элементы, меньшие опорного, влево
  for (int j = low; j <= high - 1; j++) {
    if (ptr[j].dptr_time.hours < p) {  // Сравниваем по полю `id`
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

    // Рекурсивно сортируем элементы до и после опорного элемента
    quickSort(ptr, low, pi - 1);  // Сортировка левой части
    quickSort(ptr, pi + 1, high);  // Сортировка правой части
  }
}

// Функция для вывода массива
void printarray(planes* ptr, int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << "Рейс " << ptr[i].id << "\n";
    std::cout << "Тип самолета: " << ptr[i].type << "\n";
    std::cout << "Пункт назначения: " << ptr[i].destination << "\n";
    std::cout << "Время отбытия: " << ptr[i].dptr_time.hours << " ч \n";
    std::cout << "Время полета: " << ptr[i].flight_length.minutes
              << " минут\n\n";
  }
}

void quick(planes* ptr, int counter) {
  planes* NewPtr = ptr;
  // Вызов функции быстрой сортировки по полю `id`
  quickSort(NewPtr, 0, counter - 1);

  std::cout << "\nОтсортированный массив по времени полета(по возрастанию):\n";
  printarray(NewPtr, counter);

  // Освобождаем память
  delete[] NewPtr;
}