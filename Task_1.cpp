#include "Task_1.h"

planes *CreateArray(int n) //создание массива n структур
    {
        planes *ptr = (planes*)malloc(n * sizeof(planes));
        return ptr;
    }

void DeleteArray(planes *ptr) //удаление массива структур
    {
        free(ptr);
    }

int main(){
    return 0;
}