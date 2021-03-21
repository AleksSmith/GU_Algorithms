// Aleksey Kuznetsov <alek-kuzne@yandex.ru>
// Урок 4. Рекурсия, рекурсивные алгоритмы

#include<stdio.h>

//===================================================================================================
//HANOI TOWER
//===================================================================================================
int operations = 0;

void put(int from, int to){  // вывод операции перекладывания
    printf("%d -> %d | ", from, to);
    if ((++operations) % 5 == 0){
        printf("\n");
    }
}
void hanoi(int from, int to, int n){ // рекурсивная реализация алгоритма "Ханойская башня"
    int temp = from ^ to;
    if(n == 1){
        put(from, to);
    } else{
        hanoi(from, temp, n-1);
        put(from, to);
        hanoi(temp, to, n-1);
    }
}
//end HANOI TOWER
int main(int argc, char const *argv[])
{
    //Hanoi Tower=================================================================================
    int disks;
    printf("Введите количечтво дисков в Ханойской башне: ");
    scanf("%d", &disks);
    printf("c какого и на какой столбик перекладывать кольца? (1 2 3):");
    int from;
    int to;
    scanf("%d%d", &from, &to);
    hanoi(from, to, disks);
    printf("\noperations = %d\n", operations);
    //end Hanoi Tower=================================================================================
    return 0;
}

