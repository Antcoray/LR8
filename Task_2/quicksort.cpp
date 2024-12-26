#include <cstring>
#include <iostream>

#include "Task_2.h"
#include "utils.h"

// Функция для обмена элементов в массиве
void swap(buses& a, buses& b) {
  buses temp = a;
  a = b;
  b = temp;
}

// Разделение массива
int partition(buses* ptr, int low, int high) {
  // Выбираем опорный элемент (например, последний элемент массива)
  int p = ptr[high].arrvl_time;
  int i = low - 1;

  // Проходим по массиву и перемещаем элементы, меньшие опорного, влево
  for (int j = low; j <= high - 1; j++) {
    if (ptr[j].arrvl_time < p) {  // Сравниваем по полю arrvl_time
      i++;  // Увеличиваем индекс меньшего элемента
      swap(ptr[i], ptr[j]);  // Меняем местами элементы
    }
  }

  // Перемещаем опорный элемент на правильную позицию
  swap(ptr[i + 1], ptr[high]);
  return i + 1;
}

// Основная функция быстрой сортировки
void quickSort(buses* ptr, int low, int high) {
  if (low < high) {
    // Находим индекс опорного элемента
    int pi = partition(ptr, low, high);

    quickSort(ptr, low, pi - 1);  // Сортировка левой части
    quickSort(ptr, pi + 1, high);  // Сортировка правой части
  }
}

void printarray(buses* ptr, int size, char destination[80], double TiMe) {
  int j = 0;
  for (int i = 0; i < size; ++i) {
    if (std::strcmp(ptr[i].D.destination, destination) == 0 &&
        ptr[i].arrvl_time < TiMe) {
      std::cout << "Рейс " << ptr[i].id << "\n";
      std::cout << "Тип автобуса: " << ptr[i].T.type << "\n";
      std::cout << "Пункт назначения: " << ptr[i].D.destination << "\n";
      std::cout << "Время отправления: " << ptr[i].dptr_time << " ч \n";
      std::cout << "Время прибытия: " << ptr[i].arrvl_time << " ч \n";
      ++j;
    }
  }

  if (j == 0) {
    std::cout << "Нужные рейсы не найдены\n\n";
  }
}

void quick(buses* ptr, int counter) {
  if (counter <= 1) {
    std::cout << "массив слишком мал\n";
  }
  buses* NewPtr = ptr;

  char destination[80];

  quickSort(NewPtr, 0, counter - 1);

  std::cout << "Введите нужный пункт назначения\n";
  std::cin.ignore();
  std::cin.getline(destination, sizeof(destination));
  std::cout << "введите время для поиска\n";
  double TiMe = correctInputk(0);
  std::cout << "\nОтсортированный массив по времени отбытия меньше заданного "
               "(по возрастанию):\n";
  printarray(NewPtr, counter, destination, TiMe);

   free(NewPtr);
}