#include <iostream>

union dptr_arrvl {  // время отбытия или прибытия
  int hours;
  int minutes;
};

typedef struct planes {
  int id;                   // номер рейса
  char type[80];         // тип самолета
  char destination[80];  // пункт назначения
  dptr_arrvl dptr_time;      // время отбытия
  dptr_arrvl arrvl_time; // время прибытия
} planes;