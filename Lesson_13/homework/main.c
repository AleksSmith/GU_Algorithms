// Aleksey Kuznetsov <alek-kuzne@yandex.ru>
// Урок 13. Графы

#include"../sources/geek.h"


/* 1.) Реализовать обход графа в глубину с использованием стека void depthTraversStack(int** matrix, int size) */

void clearVisited(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
}

void depthTraversStack(int** matrix, int start, const int size){
    OneLinkList *stack = (OneLinkList*)malloc(sizeof(OneLinkList));
    initOneLinkList(stack);
    int visited[size];
    clearVisited(visited, size);
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
    OneLinkList *stack = (OneLinkList*)malloc(sizeof(OneLinkList));
    initOneLinkList(stack);
    int visited[size];
    int links[size];
    clearVisited(visited, size);
    clearVisited(links, size);
    pushOneLinkStack(stack, 0);
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

/*
b) Обход графа функцией (с подсчётом только смежных со стартовой вершин) - void traversalCount(int** matrix, int start, const int size)
В конце обхода вывести два получившихся списка всех узлов в порядке уменьшения количества ссылок на них. */



// Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main и все необходимые функции.

//int matrix[n][n] = {
//        {0, 1, 1, 0, 0, 0},
//        {0, 0, 0, 1, 1, 1},
//        {0, 0, 0, 0, 0, 1},
//        {1, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 1, 0},
//};

int main(int argc, char const *argv[]){
    // 1.
    printf("Task 1\n");
    const int size = 6;
    int** graf = init2dIntArray(graf, size, size);
    set2dInt(graf, 0, 1, 1);
    set2dInt(graf, 0, 2, 1);
    set2dInt(graf, 1, 3, 1);
    set2dInt(graf, 1, 4, 1);
    set2dInt(graf, 1, 5, 1);
    set2dInt(graf, 2, 5, 1);
    set2dInt(graf, 3, 0, 1);
    set2dInt(graf, 5, 4, 1);
    print2dIntArray(graf,size,size,2);
    printf("\n");
    for (int i = 0; i < size; i++){
        depthTraversStack(graf, i, size);
        printf("\n");
    }
    printf("\n");
    // 2.a.
     printf("Task 2a\n");
    int** adjacency = init2dIntArray(adjacency, size, size);
    set2dInt(adjacency, 0, 1, 1);
    set2dInt(adjacency, 0, 2, 1);
    set2dInt(adjacency, 0, 3, 1);
    set2dInt(adjacency, 1, 0, 1);
    set2dInt(adjacency, 1, 3, 1);
    set2dInt(adjacency, 1, 4, 1);
    set2dInt(adjacency, 1, 5, 1);
    set2dInt(adjacency, 2, 0, 1);
    set2dInt(adjacency, 2, 5, 1);
    set2dInt(adjacency, 3, 0, 1);
    set2dInt(adjacency, 3, 1, 1);
    set2dInt(adjacency, 4, 1, 1);
    set2dInt(adjacency, 4, 4, 1);
    set2dInt(adjacency, 4, 5, 1);
    set2dInt(adjacency, 5, 1, 1);
    set2dInt(adjacency, 5, 2, 1);
    set2dInt(adjacency, 5, 4, 1);
    print2dIntArray(adjacency,size,size,2);
    printf("\n");
    adjacencyCount(adjacency,size);
    printf("\n");

    
    return 0;

}

