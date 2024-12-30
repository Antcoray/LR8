#include "struct2.h"

typedef struct planes {
  int id;                    // номер рейса
  char type[80];             // тип самолета
  char destination[80];      // пункт назначения
  datetime date;           // время отбытия
  dptr_arrvl flight_length;  // длительность полета

} planes;