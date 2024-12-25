#include <cstring>

#include "Task_1.h"
#include "utils.h"
planes *CreateArray(int n)  // создание массива n структур
{
  planes *ptr = (planes *)malloc(n * sizeof(planes));
  return ptr;
}

void DeleteArray(planes *ptr)  // удаление массива структур
{
  free(ptr);
}

void InputAllStructsUntilN(planes *ptr, int n) {  // ввод массива структур
  for (int i = 0; i < n; ++i) {
    // ввод полей i+1-ой структуры
    std::cout << "Введите данные рейса номер " << i + 1 << "\n\n";

    std::cout << "Введите пункт назначения[80 символов макс.]: ";
    std::cin.ignore();
    std::cin.getline(ptr[i].destination, sizeof(ptr[i].destination));

    std::cout << "\n\nВведите тип самолета[80 символов макс.]: ";
    std::cin.getline(ptr[i].type, sizeof(ptr[i].type));

    std::cout << "\n\nВведите время отбытия (в часах, дробное): ";
    ptr[i].dptr_time.hours = correctInputk(0);

    // автозаполнение остальных полей
    ptr[i].id = i + 1;
    ptr[i].flight_length.minutes =
        15 * ptr[i].id + 200 + static_cast<int>(ptr[i].dptr_time.hours);
  }
}

planes *InputAllStructsUntilTRAIT(int &counter) {
  int choice2 = 1;
  bool WasChanged[5] = {false, false, false, false, false};
  // инициализация переменных спец. значений
  int TraitOfID = -1;
  char TraitOfType[80];
  char TraitOfDestination[80];
  double TraitOfDptr_time = -1;
  int TraitOfFlight_length = -1;

  // ввод спец. значений
  while (choice2 == 1) {
    // меню
    std::cout << "Введите особый признак для одного или нескольких полей\n\n";
    std::cout << "1 - для номера рейса (автозаполняемое)\n2 - для пункта "
                 "назначения\n3 - для типа "
                 "самолета\n4 - для времени отбытия\n5 - для времени полета "
                 "(автозаполняемое)\n";
    int choice = static_cast<int>(correctInputk(3));
    if (choice == 1) {
      std::cout << "Введите особое значение номера рейса: ";
      TraitOfID = static_cast<int>(correctInputk(2));
      WasChanged[0] = true;

      choice2 = static_cast<int>(correctInputk(1));
    }
    if (choice == 2) {
      std::cout << "Введите особое значение пункта назначения: ";
      std::cin.ignore();
      std::cin.getline(TraitOfDestination, sizeof(TraitOfDestination));
      WasChanged[1] = true;
      choice2 = static_cast<int>(correctInputk(1));
    }
    if (choice == 3) {
      std::cout << "Введите особое значение типа самолета: ";
      std::cin.ignore();
      std::cin.getline(TraitOfType, sizeof(TraitOfType));
      WasChanged[2] = true;
      choice2 = static_cast<int>(correctInputk(1));
    }
    if (choice == 4) {
      std::cout << "Введите особое значение времени отбытия: ";
      TraitOfDptr_time = correctInputk(0);
      WasChanged[3] = true;
      choice2 = static_cast<int>(correctInputk(1));
    }
    if (choice == 5) {
      std::cout << "Введите особое значение времени полета: ";
      TraitOfDptr_time = static_cast<int>(correctInputk(2));
      WasChanged[4] = true;

      choice2 = static_cast<int>(correctInputk(1));
    }
  }

  // Ввод структур пока не появится особое значение поля
  bool stopInput = false;
  int i = 0;
  counter = 1;
  planes *ptr = nullptr;
  while (!stopInput) {
    // Перераспределяем память для новых структур с помощью realloc
    ptr = (planes *)realloc(ptr, (counter) * sizeof(planes));

    std::cout << "\nВведите данные для рейса " << i + 1 << "\n\n";

    std::cout << "Введите пункт назначения[80 символов макс.]: ";
    std::cin.ignore();
    std::cin.getline(ptr[i].destination, sizeof(ptr[i].destination));

    std::cout << "Введите тип самолета[80 символов макс.]: ";
    std::cin.getline(ptr[i].type, sizeof(ptr[i].type));

    std::cout << "Введите время отбытия (в часах, дробное): ";
    ptr[i].dptr_time.hours = correctInputk(0);

    // автозаполнение
    ptr[i].id = i + 1;
    ptr[i].flight_length.minutes =
        15 * ptr[i].id + 200 + static_cast<int>(ptr[i].dptr_time.hours);

    // Проверка на соответствие введенному признаку
    stopInput = true;
    if (WasChanged[0] && ptr[i].id != TraitOfID) {
      stopInput = false;
    }
    if (WasChanged[1] &&
        std::strcmp(ptr[i].destination, TraitOfDestination) != 0) {
      stopInput = false;
    }
    if (WasChanged[2] && std::strcmp(ptr[i].type, TraitOfType) != 0) {
      stopInput = false;
    }
    if (WasChanged[3] && ptr[i].dptr_time.hours != TraitOfDptr_time) {
      stopInput = false;
    }
    if (WasChanged[4] && ptr[i].flight_length.minutes != TraitOfFlight_length) {
      stopInput = false;
    }

    i++;  // Переход к следующей структуре
    counter++;
    if (!stopInput) {
      int b = static_cast<int>(correctInputk(1));
      if (b == 0) {
        break;
      }
    }
  }
  --counter;
  return ptr;
}

planes *InputAllStructsUntilInput(
    int &counter) {  // ввод структур до прекращения ввода
                     // пользователемs
  planes *ptr = nullptr;
  int i = 0;
  int choice = 1;
  while (choice == 1) {
    ptr = (planes *)realloc(ptr, (i + 1) * sizeof(planes));

    std::cout << "\nВведите данные для рейса " << i + 1 << "\n\n";

    std::cout << "Введите пункт назначения[80 символов макс.]: ";
    std::cin.ignore();
    std::cin.getline(ptr[i].destination, sizeof(ptr[i].destination));

    std::cout << "Введите тип самолета[80 символов макс.]: ";
    std::cin.getline(ptr[i].type, sizeof(ptr[i].type));

    std::cout << "Введите время отбытия (в часах, дробное): ";
    ptr[i].dptr_time.hours = correctInputk(0);

    // автозаполнение
    ptr[i].id = i + 1;
    ptr[i].flight_length.minutes =
        15 * ptr[i].id + 200 + static_cast<int>(ptr[i].dptr_time.hours);

    std::cout << "Перейти к следующему рейсу?";
    choice = static_cast<int>(correctInputk(1));
    ++i;
  }
  counter = i;
  return ptr;
}

planes *function1(int &counter2) {
  std::cout << "Выберите как заполнить данные: \n1 - ввод определенного "
               "количества структур\n2 - ввод до появления структуры с особым "
               "признаком\n3 - ввод произвольного количества структур\n";
  int choice = static_cast<int>(correctInputk(4));
  planes *ptr = nullptr;
  if (choice == 1) {
    std::cout << "Введите количество рейсов: ";
    int n = static_cast<int>(correctInputk(2));
    ptr = CreateArray(n);
    InputAllStructsUntilN(ptr, n);
    counter2 = n;
  }
  if (choice == 2) {
    int counter = 0;
    ptr = InputAllStructsUntilTRAIT(counter);
    counter2 = counter;
  }
  if (choice == 3) {
    int counter = 0;
    ptr = InputAllStructsUntilInput(counter);
    counter2 = counter;
  }
  return ptr;
}
