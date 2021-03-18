// Aleksey Kuznetsov <alek-kuzne@yandex.ru>
// Урок 3. Сложность алгоритма и простые алгоритмы

// 1) Написать функцию проверки, является ли число простым
// 1.1.) Блок-схему
// block_diagrams/isprime.jpg
// 1.2.) В коде на языке С

int isPrimeNum(int num){
    if(num < 2)
        return -1;
    for (int i = 2; i <= (num/2); i++)
    {
        if((num % i) == 0)
            return 0;
    }
            return 1;
    
}
// 2.) При помощи инструментов визуализации алгоритмов создать простую блок-схему, описывающую
// циклический алгоритм сложения чисел от [1] до [10]
// block_diagrams/sum.jpg

// Результатом домашней работы должны стать три файла - две картинки с блок-схемами и одна программа
// на языке С.


#include<stdio.h>

int main(int argc, char const *argv[])
{
    // 1.2
    int c;
    do
    {
        printf("Введите натуральное число больше 1: ");
        scanf("%d", &c);
    } while (c < 2);
            
    printf("чиcло %d %sпростое\n", c, isPrimeNum(c) ? "" : "не ");
    return 0;
}

