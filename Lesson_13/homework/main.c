// Aleksey Kuznetsov <alek-kuzne@yandex.ru>
// Урок 13. Графы

#include"../sources/geek.h"

void clearArr(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }

/* 1.) Реализовать обход графа в глубину с использованием стека void depthTraversStack(int** matrix, int size) */

}

void depthTraversStack(int** matrix, int start, const int size){
    OneLinkList *stack = (OneLinkList*)malloc(sizeof(OneLinkList));
    initOneLinkList(stack);
    int visited[size];
    clearArr(visited, size);
    pushOneLinkStack(stack, start);
    while(stack->size > 0){
        int indx = popOneLinkStack(stack);
        if(visited[indx] == 1) continue;
        visited[indx] = 1;
        printf("%d", indx);
        for (int i = 0; i < size; i++){
            if(get2dInt(matrix, indx, i) == 1 && visited[i] == 0)
                pushOneLinkStack(stack, i);
        }
        
    }


}

/* 2.) Моделируем робот поисковой системы.
Дан готовый неориентированный, невзвешенный, несмежный простой граф с петельными связями(т.е. могут быть ребра из вершины A в вершину A). Внутри графа могут
содержаться циклы.
Нужно обойти этот граф двумя способами и подсчитать количество ссылок на каждый из узлов графа (полустепень захода). 
a) Обход графа по матрице смежности (с подсчётом всех вершин графа) - void adjacencyCount(int** matrix, const int size)*/

void adjacencyCount(int** matrix, const int size){
    int links[size];
    clearArr(links, size);
    for (int  i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (matrix[i][j] == 1)
                links[i]++;
        }
    }
    for (int i = 0; i < size; i++){
        printf("%d-%d ", i, links[i]);
    }
    
}

/*
b) 
Обход графа функцией (с подсчётом только смежных со стартовой вершин) - void traversalCount(int** matrix, int start, const int size)
В конце обхода вывести два получившихся списка всех узлов в порядке уменьшения количества ссылок на них. */

void traversalCount(int** matrix, int start, const int size){
    OneLinkList *stack = (OneLinkList*)malloc(sizeof(OneLinkList));
    initOneLinkList(stack);
    int visited[size];
    int links[size];
    clearArr(visited, size);
    clearArr(links, size);
    pushOneLinkStack(stack, start);
    while(stack->size > 0){
        int indx = popOneLinkStack(stack);
        if(visited[indx] == 1) continue;
        visited[indx] = 1;
        printf("%d", indx);
        for (int i = 0; i < size; i++){
            if(get2dInt(matrix, indx, i) == 1)
                links[indx]++;
            if(get2dInt(matrix, indx, i) == 1 && visited[i] == 0)
                pushOneLinkStack(stack, i);
        }
        printf("-%d ",links[indx]);
    }
}


// Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main и все необходимые функции.

//int graf[n][n] = {
//        {0, 1, 1, 0, 0, 0},
//        {1, 0, 1, 1, 0, 0},
//        {1, 1, 0, 0, 0, 0},
//        {0, 1, 0, 1, 0, 0},
//        {0, 0, 0, 0, 0, 1},
//        {0, 0, 0, 0, 1, 0},
//};

int main(int argc, char const *argv[]){
    const int size = 6;
    int** graf = init2dIntArray(graf, size, size);
    set2dInt(graf, 0, 1, 1);
    set2dInt(graf, 0, 2, 1);
    set2dInt(graf, 1, 0, 1);
    set2dInt(graf, 1, 2, 1);
    set2dInt(graf, 1, 3, 1);
    set2dInt(graf, 2, 0, 1);
    set2dInt(graf, 2, 1, 1);
    set2dInt(graf, 3, 1, 1);
    set2dInt(graf, 3, 3, 1);
    set2dInt(graf, 4, 5, 1);
    set2dInt(graf, 5, 4, 1);
    print2dIntArray(graf,size,size,2);
    printf("\n");
// 1.
    printf("Task 1:\n");
    for (int i = 0; i < size; i++){
        depthTraversStack(graf, i, size);
        printf("\n");
    }
    printf("\n");
// 2.a.
    printf("Task 2a:\n");
    adjacencyCount(graf,size);
    printf("\n");
// 2.b
    printf("Task 2b:\n");
    traversalCount(graf, 4, size);
    printf("\n");
    
    return 0;

}

