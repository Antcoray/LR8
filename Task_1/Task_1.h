#include <iostream>

#include "utils.h"
union dptr_arrvl {  // время отбытия (часы), время полета (минуты)
  double hours;
  int minutes;
};

typedef struct planes {
  int id;                    // номер рейса
  char type[80];             // тип самолета
  char destination[80];      // пункт назначения
  dptr_arrvl dptr_time;      // время отбытия
  dptr_arrvl flight_length;  // длительность полета

} planes;

planes* function1(int& counter);
void mainmenu();
planes* addStructs(planes* ptr, int& counter);
void PrintStructArray(const planes *ptr, int n, int mainValue);
void FindStruct(planes* ptr, int counter);