typedef union dptr_arrvl {  // время отбытия (часы, минуты), время полета (минуты)
  struct {
  int hours;
  int minutes;
  };
  int total_minutes;
} dptr_arrvl;
