#include <cstring>
#include <iostream>

#include "Task_1.h"
#include "utils.h"

void FindStruct(planes* ptr, int counter) {
  std::cout << "\033[2J\033[2H";
  if (ptr == nullptr || counter == 0) {
    std::cout << "Массив структур пуст или не существует.\n";
    CONTINUE();
    return;
  }
  bool WasChanged[5] = {false, false, false, false, false};
  // инициализация переменных спец. значений
  int TraitOfID = -1;
  char TraitOfType[80];
  char TraitOfDestination[80];

int TraitOfDptr_time_year = -1;
  int TraitOfDptr_time_month = -1;
  int TraitOfDptr_time_day = -1;
  int TraitOfDptr_time_hours = -1;
  int TraitOfDptr_time_minutes = -1;

  int TraitOfFlight_length = -1;

  std::cout << "Введите особое значение для поиска\n\n";
  std::cout << "1 - для номера рейса (автозаполняемое)\n2 - для пункта "
               "назначения\n3 - для типа "
               "самолета\n4 - для времени отбытия\n5 - для времени полета "
               "(автозаполняемое)\n";
  int choice = correctInputk(3);
  if (choice == 1) {
    std::cout << "Введите особое значение номера рейса: ";
    TraitOfID = correctInputk(2);
    WasChanged[0] = true;
  }
  if (choice == 2) {
    std::cout << "Введите особое значение пункта назначения: ";
    std::cin.ignore();
    std::cin.getline(TraitOfDestination, sizeof(TraitOfDestination));
    WasChanged[1] = true;
  }
  if (choice == 3) {
    std::cout << "Введите особое значение типа самолета: ";
    std::cin.ignore();
    std::cin.getline(TraitOfType, sizeof(TraitOfType));
    WasChanged[2] = true;
  }
  if (choice == 4) {
    std::cout << "Введите особое значение времени отправления\n\n";
      std::cout << "Введите год: ";
      TraitOfDptr_time_year = correctInputk(6);
      std::cout << "Введите месяц: ";
      TraitOfDptr_time_month = correctInputk(7);
      std::cout << "Введите день: ";
      TraitOfDptr_time_day = correctInputk(8);
      std::cout << "Введите часы: ";
      TraitOfDptr_time_hours = correctInputk(9);
      std::cout << "Введите минуты: ";
      TraitOfDptr_time_minutes = correctInputk(10);
    WasChanged[3] = true;
  }
  if (choice == 5) {
    std::cout << "Введите особое значение времени полета: ";
    TraitOfFlight_length = correctInputk(2);
    WasChanged[4] = true;
  }
  for (int i = 0; i < counter; ++i) {
    if (WasChanged[0] && ptr[i].id == TraitOfID) {
      PrintStructArray(ptr, i + 1, i, 1);
    }
    if (WasChanged[1] &&
        std::strcmp(ptr[i].destination, TraitOfDestination) == 0) {
      PrintStructArray(ptr, i + 1, i, 1);
    }
    if (WasChanged[2] && std::strcmp(ptr[i].type, TraitOfType) == 0) {
      PrintStructArray(ptr, i + 1, i, 1);
    }
    if (WasChanged[3] && ptr[i].date.year == TraitOfDptr_time_year && ptr[i].date.month == TraitOfDptr_time_month && ptr[i].date.day == TraitOfDptr_time_day && ptr[i].date.TIME.hours == TraitOfDptr_time_hours && ptr[i].date.TIME.minutes == TraitOfDptr_time_minutes) {
      PrintStructArray(ptr, i + 1, i, 1);
    }
    if (WasChanged[4] && ptr[i].flight_length.total_minutes == TraitOfFlight_length) {
      PrintStructArray(ptr, i + 1, i, 1);
    }
  }
  CONTINUE();
}
