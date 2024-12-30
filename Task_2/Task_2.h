#pragma once
#include <cstdio>
#include <iostream>
#include <string>
#include "utils.h"
union ints{
  struct{
  int day;
  int month;
  int year;
  int hours;
  int minutes;
  };
  int id;
  int sum;
};

typedef struct buses { 
  ints id;            // номер рейса
  char T[16];            // тип автобуса
  char D[80];            // пункт назначения
  ints dptr_time;   // время отбытия
  ints arrvl_time;  // время прибытия
  ints total_minutes; // для сортировки
} buses;

buses* function1(int& counter);
void mainmenu();
buses* addStructs(buses* ptr, int& counter);
void PrintStructArray(buses* ptr, int n, int mainValue, int a = 0);
buses* DeleteElement(buses* ptr, int& counter, int element);
buses* ChangeElement(buses* ptr, int counter, int element);
void quick(buses* ptr, int counter);
void updateElementInFile(const char* filename, buses* element, int index);
buses* loadFromFile(const char* filename, int& count);
void updateElementInFile(const char* filename, buses* array, int count);
void CONTINUE();