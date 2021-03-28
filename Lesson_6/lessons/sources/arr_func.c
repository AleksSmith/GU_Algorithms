#include"arr_func.h"

void fillRandIntArr(int *arr, int size, int mdig){
    for (int i = 0; i < size; i++){
        arr[i] = rand() % mdig;
    }
}

void printArr(int *arr, int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

void swapInt(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}