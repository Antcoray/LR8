#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include "Task_2.h"
#include "utils.h"

buses* loadFromFile(const char* filename, int& count) {
  FILE* f = fopen(filename, "r");
  if (!f) {
    printf("Ошибка открытия файла для чтения.\n");
    return NULL;
  }

  // Считываем количество элементов
  fscanf(f, "%d\n", &count);

  // Выделяем память под массив структур
  buses* ptr = (buses*)malloc(count * sizeof(buses));

  // Читаем каждую структуру
  for (int i = 0; i < count; ++i) {
    fscanf(f, "%d %15s %79s %lf %lf", &ptr[i].id, ptr[i].T.type,
           ptr[i].D.destination, &ptr[i].dptr_time, &ptr[i].arrvl_time);
  }

  fclose(f);
  return ptr;
}

void updateElementInFile(const char* filename, buses* array, int count) {
  FILE* f = fopen(filename, "w");
  if (!f) {
    printf("Ошибка открытия файла для записи.\n");
    return;
  }

  // Записываем количество элементов
  fprintf(f, "%d\n", count);

  // Записываем каждую структуру
  for (int i = 0; i < count; ++i) {
    fprintf(f, "%d %s %s %.2f %.2f\n", array[i].id, array[i].T.type,
            array[i].D.destination, array[i].dptr_time, array[i].arrvl_time);
  }

  fclose(f);
}
