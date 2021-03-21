// Aleksey Kuznetsov <alek-kuzne@yandex.ru>
// Урок 4. Рекурсия, рекурсивные алгоритмы

#include<stdio.h>

// 1). Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.
void decToBin(int n){
    if (n >= 2)
        decToBin(n / 2);
    printf("%d", n % 2);
}
// 2). Реализовать функцию возведения числа [a] в степень [b]:
//  a) Рекурсивно.
int expo(int a, int b){
    if(b == 1)
        return a;
    else
        return a * expo(a, b - 1);
}
//  b) Рекурсивно, используя свойство чётности степени (то есть, если степень, в которую нужно
//      возвести число, чётная, основание возводится в квадрат, а показатель делится на два,
//      а если степень нечётная - результат умножается на основание, а показатель уменьшается на единицу)
int alterExpo(int a, int b){
    if(b == 1)
        return a;
    else if((b % 2) == 0)
        return alterExpo(a*a, b/2);
    else 
        return a * alterExpo(a, b - 1);
}
// 3). Реализовать нахождение количества маршрутов шахматного короля с препятствиями (где единица -
//      это наличие препятствия, а ноль - свободная для хода клетка)

// S(m, n) = S(m-1, n) + S(m, n-1);
// S(m, n) = 1, если одна из координат равна 0
// S(m, n) = 0, если m и n стартовые координаты

int field[5][5] = { {0,0,0,0,0}, 
                    {0,1,0,0,0},
                    {0,1,0,1,0},
                    {0,0,0,0,0},
                    {0,0,0,1,0}}; // поле с припятствиями

int routes(int x, int y){   // реализация движения короля
    if( x == 0 && y == 0) 
        return 0;
    else if(field[y][x] == 1)
        return 0;
    else if( x == 0 ^ y == 0) 
        return 1;
    else
        return routes(x, y - 1) + routes(x - 1, y);
}

// Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main и четыре
// функции, соответствующие каждому из заданий.

int main(int argc, char const *argv[]){
    // 1.
    int num;
    printf("Введите число: ");
    scanf("%d", &num);
    printf("%d -> Ob", num);
    decToBin(num);    
    printf("\n");
    // 2.a
    int a = 3;
    int b = 8;
    printf("%d^%d = %d\n", a, b, expo(a,b));
    // 2.b
    a = 2;
    b = 4;
    printf("%d^%d = %d\n", a, b, alterExpo(a,b));
    b = 5;
    printf("%d^%d = %d\n", a, b, alterExpo(a,b));
    // 3.
    const int sizeX = 5;
    const int sizeY = 5;
    for (int y = 0; y < sizeY; y++){
        for (int x = 0; x < sizeX; x++){
            printf("%5d", routes(x,y));
        }
        printf("\n");
    }
    return 0;
}

