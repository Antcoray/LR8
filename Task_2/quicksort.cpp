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
  int p = ptr[high].total_minutes.sum;
  int i = low - 1;

  // Проходим по массиву и перемещаем элементы, меньшие опорного, влево
  for (int j = low; j <= high - 1; j++) {
    if (ptr[j].total_minutes.sum < p) {  // Сравниваем по полю total_minutes
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

void printarray(buses* ptr, int size, char destination[80], int TiMe) {
  int j = 0;
  for (int i = 0; i < size; ++i) {
    if (std::strcmp(ptr[i].D, destination) == 0 &&
        ptr[i].total_minutes.sum < TiMe) {
      std::cout << "\nРейс " << ptr[i].id.id << "\n";
      std::cout << "Тип автобуса: " << ptr[i].T << "\n";
      std::cout << "Пункт назначения: " << ptr[i].D << "\n";
      std::cout << "Время отправления: " << ptr[i].dptr_time.hours << " ч " << ptr[i].dptr_time.minutes << " мин " << ptr[i].dptr_time.day << "." << ptr[i].dptr_time.month << "." << ptr[i].dptr_time.year << "\n";
      std::cout << "Время прибытия: " << ptr[i].arrvl_time.hours << " ч " << ptr[i].arrvl_time.minutes << " мин " << ptr[i].arrvl_time.day << "." << ptr[i].arrvl_time.month << "." << ptr[i].arrvl_time.year << "\n";
      ++j;
    }
  }

  if (j == 0) {
    std::cout << "Нужные рейсы не найдены\n\n";
  }

}

void quick(buses* ptr, int counter) {
  std::cout << "\033[2J\033[2H";
  if (counter < 1) {
    std::cout << "массив слишком мал\n";
    CONTINUE();
    return;
  }
  buses* NewPtr = ptr;

  char destination[80];

  quickSort(NewPtr, 0, counter - 1);

  std::cout << "Введите нужный пункт назначения\n";
  std::cin.ignore();
  std::cin.getline(destination, sizeof(destination));
  std::cout << "введите дату и время для поиска\n\n";
  
    std::cout << "\nВведите дату прибытия ";
    std::cout << "\n\nВведите год: ";
    int year = correctInputk(6);

    std::cout << "\nВведите месяц: ";
    int month = correctInputk(7);

    std::cout << "\nВведите день: ";
    int day = correctInputk(8);

    std::cout << "\nВведите время прибытия";

    std::cout << "\n\nВведите часы: ";
    int hours = correctInputk(9);

    std::cout << "\nВведите минуты: ";
    int minutes = correctInputk(10);
    int TiMe = (((year - 2000)* 365 + month * 30 + day) * 24 + hours) * 60 + minutes;
  std::cout << "\nОтсортированный массив по времени отбытия меньше заданного "
               "(по возрастанию):\n";
  printarray(NewPtr, counter, destination, TiMe);
  CONTINUE();
}