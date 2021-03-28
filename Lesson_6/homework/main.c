// Aleksey Kuznetsov <alek-kuzne@yandex.ru>
// Урок 6. Массивы.
#include<stdio.h>
#include<math.h>

void printArr(int *arr, int hight, int width);
void swapInt(int *a, int *b);
void swapDouble(double *a, double *b);

// 1). Реализовать пузырьковую сортировку двумерного массива
// например, массив:
// 1,9,2
// 5,7,6
// 4,3,8
// должен на выходе стать:
// 1,2,3
// 4,5,6
// 7,8,9

int bubbleSort(int *arr, int hight, int width){
    for (int n = 0; n < hight * width; n++){
        for (int i = 0; i < hight * width - 1 - n; i++){
            if(*(arr + i) > *(arr + i + 1))
                swapInt(arr + i, arr + i + 1);
        }    
    }
}

// 2). Описать подробную блок-схему алгоритма Трабба-Прадо-Кнута - WIKI (Только пожалуйста не копируйте оттуда бездумно код, постарайтесь сначала выполнить
// задание самостоятельно)
// 1 - запросить у пользователя 11 чисел и записать их в последовательность П
// 2 - инвертировать последовательность П
// 3 - для каждого элемента последовательности П произвести вычисление по формуле sqrt(fabs(Х)) + 5 * pow(Х, 3) и если результат вычислений 
// превышает 400 - проинформировать пользователя.

// 3). Реализовать алгоритм Трабба-Прадо-Кнута в коде на языке С

double func(double x){
    return (sqrt(fabs(x)) + 5 * pow(x, 3));
}

void TPK(){
    const int size = 11;
    double arr[size];
    for (int  i = 0; i < size; i++){
        printf("Введите %d элемент последовательности: ", i);
        scanf("%lf", &arr[i]);
    }
    int l = 0;
    int r = size - 1;
    while (l < r){
        swapDouble(&arr[l], &arr[r]);
        l++; r--;
    }
    for (int i = 0; i < size; i++){
        if (func(arr[i]) > 400)
            printf("Результат с %d элементом > 400\n", i);
        else
            printf("%d %.2f\n", i, arr[i]);
    }
}

// Результатом выполнения задания должны стать два файла:
// 1. Файл с кодом на языке С, содержащим функцию main и две функции, соответствующие сортировке и алгоритму Трабба-Прадо-Кнута,
// 2. Файл с изображением блок схемы алгоритма Трабба-Прадо-Кнута в любом популярном формате (jpg, png, gif) или в виде PlantUML файла (.puml)



int main(int argc, char const *argv[]){
//   1.
    int array[3][3] = {{1,9,2},{5,7,6},{4,3,8}};
    printArr(&array[0][0],3,3);
    printf("\n");
    bubbleSort(&array[0][0],3,3);
    printArr(&array[0][0],3,3);
//  3.
    TPK();
    return 0;
}

void printArr(int *arr, int hight, int width){
    for (int y = 0; y < hight; y++){
        for (int x = 0; x < width; x++){
            printf("%d ", *(arr + x + y*(width)));
        }
        printf("\n");
    }
}

void swapInt(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swapDouble(double *a, double *b){
    double tmp = *a;
    *a = *b;
    *b = tmp;
}