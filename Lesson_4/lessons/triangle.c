// Aleksey Kuznetsov <alek-kuzne@yandex.ru>
// Урок 4. Рекурсия, рекурсивные алгоритмы

#include<stdio.h>

//================================================================================================
//TRIANGLE NUMBERS
//===============================================================================================
int triangle(int num){ // рекурсивная функция нахождения треугольного числа
    if(num == 1)
        return 1;
    else
        return num + triangle(num - 1); 
}
void printPyramid(int num){   // функция печати треугольного числа в виде пирамиды
    int amd = 1;
    char str[5];
        while(amd <= num){
            sprintf(str, "%%%dd", num + 1 - amd); 
            printf(str, 1);
            int i = amd;
            while (i>1){
                printf("%2d", 1);
                --i;
            }
            puts("");
            amd++;
        }     
}
void printTriangle(int num){ // функция вывода треугольного числа в виде суммы
    int sum = 1;
    while (sum <= num){
        printf("%s%d", (sum > 1) ? "+" : "", sum);
        sum++;
    }
    
}
//end ETRIANGLE NUMBERS
//================================================================================================
int main(int argc, char const *argv[])
{
    //triangle nums===============================================================================
    for (int  i = 1; i <= 9; i++){
        printf("%d = ", triangle(i));
        printTriangle(i);
        puts("");
        printPyramid(i);
        puts("");
        }
    puts("");
    //end triangle nums===============================================================================
    return 0;
}

