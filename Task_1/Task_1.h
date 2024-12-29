#pragma once
#include <iostream>
#include <cstdio>
#include "utils.h"
#include <string>
union dptr_arrvl {  // время отбытия (часы, минуты), время полета (минуты)
  struct {
  int hours;
  int minutes;
  };
  int total_minutes;
};

struct datetime{
  int day;
  int month;
  int year;
  dptr_arrvl TIME;
};

typedef struct planes {
  int id;                    // номер рейса
  char type[80];             // тип самолета
  char destination[80];      // пункт назначения
  datetime date;           // время отбытия
  dptr_arrvl flight_length;  // длительность полета

} planes;

planes* function1(int& counter);
void mainmenu();
planes* addStructs(planes* ptr, int& counter);
void PrintStructArray(const planes *ptr, int n, int mainValue, int f = 0);
void FindStruct(planes* ptr, int counter);
planes* DeleteElement(planes* ptr, int& counter, int element);
planes* ChangeElement(planes* ptr, int counter, int element);
void quick(planes* ptr, int counter);
void updateElementInFile(const char* filename, planes* element, int index);
void updateElementCount(const char* filename, int count);
planes* loadFromFile(const char* filename, int& count);
void CONTINUE();