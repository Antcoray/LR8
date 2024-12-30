#include <cstring>
\
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
    std::cout << "\033[2J\033[2H";
    // ввод полей i+1-ой структуры
    std::cout << "Введите данные рейса номер " << i + 1 << "\n\n";

    std::cout << "Введите пункт назначения[80 символов макс.]: ";
    std::cin.ignore();
    std::cin.getline(ptr[i].destination, sizeof(ptr[i].destination));

    std::cout << "\n\nВведите тип самолета[80 символов макс.]: ";
    std::cin.getline(ptr[i].type, sizeof(ptr[i].type));

    std::cout << "\nВведите дату отправления";

    std::cout << "\n\nВведите год: ";
    ptr[i].date.year = correctInputk(6);

    std::cout << "Введите месяц: ";
    ptr[i].date.month = correctInputk(7);

    std::cout << "Введите день: ";
    ptr[i].date.day = correctInputk(8);

    std::cout << "\nВведите время отправления";

    std::cout << "\n\nВведите часы: ";
    ptr[i].date.TIME.hours = correctInputk(9);

    std::cout << "Введите минуты: ";
    ptr[i].date.TIME.minutes = correctInputk(10);

    // автозаполнение остальных полей
    ptr[i].id = i + 1;
    ptr[i].flight_length.total_minutes =
        15 * ptr[i].id + 200 + ptr[i].date.TIME.hours;

    updateElementInFile("data.bin", &ptr[i], i);
    updateElementCount("data.bin", i + 1);
  }
}

planes *InputAllStructsUntilTRAIT(int &counter) {
  int choice2 = 1;
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

  // ввод спец. значений
  while (choice2 == 1) {
    std::cout << "\033[2J\033[2H";
    // меню
    std::cout << "Введите особый признак для одного или нескольких полей\n\n";
    std::cout << "1 - для номера рейса (автозаполняемое)\n2 - для пункта "
                 "назначения\n3 - для типа "
                 "самолета\n4 - для времени и даты отправления\n5 - для времени полета "
                 "(автозаполняемое)\n";
    int choice = correctInputk(3);
    if (choice == 1) {
      std::cout << "Введите особое значение номера рейса: ";
      TraitOfID = correctInputk(2);
      WasChanged[0] = true;

      choice2 = correctInputk(1);
    }
    if (choice == 2) {
      std::cout << "Введите особое значение пункта назначения: ";
      std::cin.ignore();
      std::cin.getline(TraitOfDestination, sizeof(TraitOfDestination));
      WasChanged[1] = true;
      choice2 = correctInputk(1);
    }
    if (choice == 3) {
      std::cout << "Введите особое значение типа самолета: ";
      std::cin.ignore();
      std::cin.getline(TraitOfType, sizeof(TraitOfType));
      WasChanged[2] = true;
      choice2 = correctInputk(1);
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
      choice2 = correctInputk(1);
    }
    if (choice == 5) {
      std::cout << "Введите особое значение времени полета: ";
      TraitOfFlight_length = correctInputk(2);
      WasChanged[4] = true;

      choice2 = correctInputk(1);
    }
  }

  // Ввод структур пока не появится особое значение поля
  bool stopInput = false;
  int i = 0;
  counter = 1;
  planes *ptr = nullptr;
  while (!stopInput) {
    std::cout << "\033[2J\033[2H";
    // Перераспределяем память для новых структур с помощью realloc
    ptr = (planes *)realloc(ptr, (counter) * sizeof(planes));

    std::cout << "\nВведите данные для рейса " << i + 1 << "\n\n";

    std::cout << "Введите пункт назначения[80 символов макс.]: ";
    std::cin.ignore();
    std::cin.getline(ptr[i].destination, sizeof(ptr[i].destination));

    std::cout << "Введите тип самолета[80 символов макс.]: ";
    std::cin.getline(ptr[i].type, sizeof(ptr[i].type));

    std::cout << "Введите дату отправления";

    std::cout << "\n\nВведите год: ";
    ptr[i].date.year = correctInputk(6);

    std::cout << "\n\nВведите месяц: ";
    ptr[i].date.month = correctInputk(7);

    std::cout << "\n\nВведите день: ";
    ptr[i].date.day = correctInputk(8);

    std::cout << "Введите время отправления";

    std::cout << "\n\nВведите часы: ";
    ptr[i].date.TIME.hours = correctInputk(9);

    std::cout << "\n\nВведите минуты: ";
    ptr[i].date.TIME.minutes = correctInputk(10);

    // автозаполнение остальных полей
    ptr[i].id = i + 1;
    ptr[i].flight_length.total_minutes =
        15 * ptr[i].id + 200 + ptr[i].date.TIME.hours;

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
    if (WasChanged[3] && ptr[i].date.year != TraitOfDptr_time_year && ptr[i].date.month != TraitOfDptr_time_month && ptr[i].date.day != TraitOfDptr_time_day && ptr[i].date.TIME.hours != TraitOfDptr_time_hours && ptr[i].date.TIME.minutes != TraitOfDptr_time_minutes) {
      stopInput = false;
    }
    if (WasChanged[4] && ptr[i].flight_length.total_minutes != TraitOfFlight_length) {
      stopInput = false;
    }
    updateElementInFile("data.bin", &ptr[i], i);
    i++;  // Переход к следующей структуре
    counter++;
    if (!stopInput) {
      int b = correctInputk(1);
      if (b == 0) {
        break;
      }
    }
  }
  --counter;
  updateElementCount("data.bin", counter);
  return ptr;
}

planes *InputAllStructsUntilInput(
    int &counter) {  // ввод структур до прекращения ввода
                     // пользователем
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

    std::cout << "Введите дату отправления ";

    std::cout << "\n\nВведите год: ";
    ptr[i].date.year = correctInputk(6);

    std::cout << "\n\nВведите месяц: ";
    ptr[i].date.month = correctInputk(7);

    std::cout << "\n\nВведите день: ";
    ptr[i].date.day = correctInputk(8);

    std::cout << "Введите время отправления";

    std::cout << "\n\nВведите часы: ";
    ptr[i].date.TIME.hours = correctInputk(9);

    std::cout << "\n\nВведите минуты: ";
    ptr[i].date.TIME.minutes = correctInputk(10);

    // автозаполнение остальных полей
    ptr[i].id = i + 1;
    ptr[i].flight_length.total_minutes =
        15 * ptr[i].id + 200 + ptr[i].date.TIME.hours;
    updateElementInFile("data.bin", &ptr[i], i);
    choice = correctInputk(1);
    ++i;
  }
  counter = i;
  updateElementCount("data.bin", counter);
  return ptr;
}

planes *function1(int &counter2) {
  std::cout << "\033[2J\033[2H";
  std::cout << "Выберите как заполнить данные: \n1 - ввод определенного "
               "количества структур\n2 - ввод до появления структуры с особым "
               "признаком\n3 - ввод произвольного количества структур\n";
  int choice = correctInputk(4);
  planes *ptr = nullptr;
  if (choice == 1) {
    std::cout << "\033[2J\033[2H";
    std::cout << "Введите количество рейсов: ";
    int n = correctInputk(2);
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
