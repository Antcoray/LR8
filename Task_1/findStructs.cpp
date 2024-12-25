#include <cstring>
#include <iostream>

#include "Task_1.h"
#include "utils.h"

void FindStruct(planes* ptr, int counter) {
  if (ptr == nullptr || counter == 0) {
    std::cout << "Массив структур пуст или не существует.\n";
    return;
  }
  bool WasChanged[5] = {false, false, false, false, false};
  // инициализация переменных спец. значений
  int TraitOfID = -1;
  char TraitOfType[80];
  char TraitOfDestination[80];
  double TraitOfDptr_time = -1;
  int TraitOfFlight_length = -1;

  std::cout << "Введите особое значение для поиска\n\n";
  std::cout << "1 - для номера рейса (автозаполняемое)\n2 - для пункта "
               "назначения\n3 - для типа "
               "самолета\n4 - для времени отбытия\n5 - для времени полета "
               "(автозаполняемое)\n";
  int choice = static_cast<int>(correctInputk(3));
  if (choice == 1) {
    std::cout << "Введите особое значение номера рейса: ";
    TraitOfID = static_cast<int>(correctInputk(2));
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
    std::cout << "Введите особое значение времени отбытия: ";
    TraitOfDptr_time = correctInputk(0);
    WasChanged[3] = true;
  }
  if (choice == 5) {
    std::cout << "Введите особое значение времени полета: ";
    TraitOfDptr_time = static_cast<int>(correctInputk(2));
    WasChanged[4] = true;
  }
  for (int i = 0; i < counter; ++i) {
    if (WasChanged[0] && ptr[i].id == TraitOfID) {
      PrintStructArray(ptr, i + 1, i);
    }
    if (WasChanged[1] &&
        std::strcmp(ptr[i].destination, TraitOfDestination) == 0) {
      PrintStructArray(ptr, i + 1, i);
    }
    if (WasChanged[2] && std::strcmp(ptr[i].type, TraitOfType) == 0) {
      PrintStructArray(ptr, i + 1, i);
    }
    if (WasChanged[3] && ptr[i].dptr_time.hours == TraitOfDptr_time) {
      PrintStructArray(ptr, i + 1, i);
    }
    if (WasChanged[4] && ptr[i].flight_length.minutes == TraitOfFlight_length) {
      PrintStructArray(ptr, i + 1, i);
    }
  }
}
