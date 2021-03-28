#include"sort.h"

void sortInsert(int *arr, int size){
    int temp, pos;
    for (int i = 1; i < size; i++){
        temp = arr[i];
        pos = i - 1;
        while (pos >= 0 && arr[pos] > temp){
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}

void sortSelection(int *arr, int size){
    int min;
    for (int i = 0; i < size - 1; i++){
        min = i;
        for (int j = i+1; j < size; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        swapInt(&arr[i], &arr[min]);
    }
}
