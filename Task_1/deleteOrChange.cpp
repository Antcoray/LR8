#include <iostream>

#include "Task_1.h"
#include "utils.h"

planes* DeleteElement(planes* ptr, int& counter, int element) {
  if (ptr == nullptr) {
    std::cout << "Массив структур пустой\n";
    return ptr;
  }

  // Если массив состоит из одного элемента, просто освобождаем память
  if (counter == 1) {
    free(ptr);
    ptr = nullptr;
    counter = 0;
    return ptr;
  }

  // Сдвигаем все элементы после `index` на одну позицию влево
  for (int i = element - 1; i < counter; ++i) {
    ptr[i] = ptr[i + 1];
  }

  // Уменьшаем размер массива
  --counter;

  ptr = (planes*)realloc(ptr, counter * sizeof(planes));

  return ptr;
}


