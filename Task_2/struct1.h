
#include "union.h"
typedef struct buses { 
  ints id;            // номер рейса
  char T[16];            // тип автобуса
  char D[80];            // пункт назначения
  ints dptr_time;   // время отбытия
  ints arrvl_time;  // время прибытия
  ints total_minutes; // для сортировки
} buses;