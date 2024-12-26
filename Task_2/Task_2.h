#pragma once
#include <cstdio>
#include <iostream>

#include "utils.h"
union chars {
  char type[16];
  char destination[80];
};

typedef struct buses {
  int id;             // номер рейса
  chars T;            // тип самолета
  chars D;            // пункт назначения
  double dptr_time;   // время отбытия
  double arrvl_time;  // время прибытия

} buses;

buses* function1(int& counter);
void mainmenu();
buses* addStructs(buses* ptr, int& counter);
void PrintStructArray(const buses* ptr, int n, int mainValue);
buses* DeleteElement(buses* ptr, int& counter, int element);
buses* ChangeElement(buses* ptr, int counter, int element);
void quick(buses* ptr, int counter);
void updateElementInFile(const char* filename, buses* element, int index);
buses* loadFromFile(const char* filename, int& count);
void updateElementInFile(const char* filename, buses* array, int count);