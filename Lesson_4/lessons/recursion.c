// Aleksey Kuznetsov <alek-kuzne@yandex.ru>
// Урок 4. Рекурсия, рекурсивные алгоритмы

#include<stdio.h>

void rec(int a){  // пример рекурсивной функции
    printf("%5d", a);
    if(a > 0)
        rec(a - 1);
}
int sumDigitIter(int num){   // итеративная функция сложения цифр числа 
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int sumDigitRec(int num){    // рекурсивная функция сложения цифр числа
    if(num > 0)
        return num % 10 + sumDigitRec(num / 10);
    else
        return 0;

}
int fib(int n){  // рекурсивная функция нахождения числа Фибоначчи 
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fib(n-1)+fib(n-2);
}
int factorialRec(int num){  // рекурсивная функция нахождения факториала числа
    if(num <= 0)
        return 1;
    return num * factorialRec(num - 1);
}
int factorialIter(int num){  // итеративная функция нахождения факториала числа
    if(num < 0)
        return -1;
    int res = 1;
    for (int i = 1; i <= num; i++){
        res *= i;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    rec(10);
    
    printf("\n%d\n", sumDigitIter(123456789));
    printf("%d\n", sumDigitRec(123456789));
    
    for (int i = 0; i < 30; i++){
        printf("%d ",fib(i));
    }
    
    printf("\nВведите число: ");
    int n;
    scanf("%d", &n);
    printf("factorialRec(%d) = %d\n", n, factorialRec(n));    
    printf("factorialIter(%d) = %d\n", n, factorialIter(n));
    
    return 0;
}

