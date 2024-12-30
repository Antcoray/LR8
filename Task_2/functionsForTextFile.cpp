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
    fscanf(f, "%d %d %d %d %d %15s %79s %d %d %d %d %d %d %d %d %d %d",
           &ptr[i].id.day, &ptr[i].id.month, &ptr[i].id.year,
           &ptr[i].id.hours, &ptr[i].id.minutes, 
           ptr[i].T, ptr[i].D,
           &ptr[i].dptr_time.day, &ptr[i].dptr_time.month,
           &ptr[i].dptr_time.year, &ptr[i].dptr_time.hours,
           &ptr[i].dptr_time.minutes,
           &ptr[i].arrvl_time.day, &ptr[i].arrvl_time.month,
           &ptr[i].arrvl_time.year, &ptr[i].arrvl_time.hours,
           &ptr[i].arrvl_time.minutes);
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
    fprintf(f, "%d %d %d %d %d %15s %79s %d %d %d %d %d %d %d %d %d %d\n",
            array[i].id.day, array[i].id.month, array[i].id.year,
            array[i].id.hours, array[i].id.minutes,
            array[i].T, array[i].D,
            array[i].dptr_time.day, array[i].dptr_time.month,
            array[i].dptr_time.year, array[i].dptr_time.hours,
            array[i].dptr_time.minutes,
            array[i].arrvl_time.day, array[i].arrvl_time.month,
            array[i].arrvl_time.year, array[i].arrvl_time.hours,
            array[i].arrvl_time.minutes);
  }

  fclose(f);
}

