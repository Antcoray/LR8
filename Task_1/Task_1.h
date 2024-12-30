#pragma once
#include <iostream>
#include <cstdio>
#include "utils.h"
#include <string>
#include "structs.h"


planes* function1(int& counter);
void mainmenu();
planes* addStructs(planes* ptr, int& counter);
void PrintStructArray(const planes *ptr, int n, int mainValue, int f = 0);
void FindStruct(planes* ptr, int counter);
planes* DeleteElement(planes* ptr, int& counter, int element);
planes* ChangeElement(planes* ptr, int counter, int element);
void quick(planes* ptr, int counter);
void updateElementInFile(const char* filename, planes* element, int index);
void updateElementCount(const char* filename, int count);
planes* loadFromFile(const char* filename, int& count);
void CONTINUE();