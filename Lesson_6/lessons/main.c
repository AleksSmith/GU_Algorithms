// Aleksey Kuznetsov <alek-kuzne@yandex.ru>
// Урок 6. Массивы.

#include"sources/arr_func.h"
#include"sources/sort.h"
#include"sources/search.h"

int main(int argc, char const *argv[])
{
    const int size = 50;
    const int val = 99;
    int array[size];
    fillRandIntArr(array, size, 100);
    printArr(array, size);
    printf("\n"); 
    sortInsert(array, size);
    // sortSelection(array, size);
    printArr(array, size);
    printf("\n%d", interpolarSearch(array, size, val));
    printf("\n");
    return 0;
}
