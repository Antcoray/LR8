#include <cstdio>
#include <iostream>

#include "Task_1.h"
#include "utils.h"

void updateElementInFile(const char* filename, planes* element, int index) {
  FILE* f = fopen(filename, "rb+");  // Открываем файл для чтения и записи: r -
                                     // read, b - binary, + чтение и запись

  fseek(f, sizeof(int) + index * sizeof(planes),
        SEEK_SET);  // получаем нужное место в файле

  fwrite(element, sizeof(planes), 1, f);  // Записываем изменённый элемент

  fclose(f);
}

void updateElementCount(const char* filename, int count) {
  FILE* f = fopen(filename, "rb+");

  fwrite(&count, sizeof(int), 1,
         f);  // Записываем количество элементов в начале файла

  fclose(f);
}

planes* loadFromFile(const char* filename, int& count) {
  FILE* f = fopen(filename, "rb");  // Открываем файл ТОЛЬКО для чтения

  fread(&count, sizeof(int), 1, f);  // Читаем количество элементов

  planes* ptr = (planes*)malloc(
      count * sizeof(planes));  // Выделяем память под массив структур

  fread(ptr, sizeof(planes), count, f);   // Читаем структуры

  fclose(f);
  return ptr;
}
