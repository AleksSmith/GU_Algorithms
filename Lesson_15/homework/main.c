// Aleksey Kuznetsov <alek-kuzne@yandex.ru>
// Урок 15. Хеш-таблицы

#include <stdio.h>

/* 1.) Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
    int simpleHashSum(char* in) */
int simpleHashSum(char *in)
{
    int hash = 0;
    int i = 0;
    while (in[i] != '\0')
    {
        hash += (int)in[i];
        i++;
    }
    return hash;
}

/* 2.) Имеются монеты номиналом 50, 10, 5, 2, 1 коп. Напишите функцию которая минимальным количеством монет наберет сумму 98 коп.
    Для решения задачи используйте “жадный” алгоритм.
    int* exchange(int* money, int size, int sum)
    Входные параметры:
    int* money - Массив с доступными номиналами монет размером size. Например: int money[] = {50, 10, 5, 2, 1};, size = 5.
    Выходные параметры:
    Можно просто вывести необходимые монеты в консоль, либо вернуть указатель int* на массив, в котором первый элемент будет хранить его размер.
    Считается что монет каждого номинала у нас неограниченное количество. */

int exchange(int *money, int size, int change)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        while ((sum + money[i]) <= change)
        {
            printf("%d ", money[i]);
            sum += money[i];
        }
    }
    return sum;
}

// Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main и все необходимые функции.

int main(int argc, char const *argv[])
{
    // 1.
    printf("Task 1: ");
    char arr[] = "HelloWorld!";
    printf("hash = %d\n", simpleHashSum(arr));
    // 2.
    printf("Task 2: ");
    const int change = 98;
    const int size = 5;
    int money[] = {50, 10, 5, 2, 1};
    printf(": change = %d\n", exchange(money, size, change));
    return 0;
}
