// Aleksey Kuznetsov <alek-kuzne@yandex.ru>
// Урок 4. Рекурсия, рекурсивные алгоритмы

#include<stdio.h>

//================================================================================================
//ANAGRAMS
//===============================================================================================
void rotate(char *word, int size, int n){   // функция циклической перестановки элементов массива
    int pos = size - n;
    char temp = word[pos];
    int i;
    for (i = pos + 1; i < size; i++){
        word[i-1] = word[i];
    }
    word[i-1] = temp;
}

void display(char *word, int size){  // функция вывода
    for (int i = 0; i < size; i++){
        printf("%c",word[i]);
    }
    puts("");
}

void getAnagram(char *word, int size, int n){ // рекурсивная функция поиска анаграмм
    if(n == 1)
        return;
    for (int i = 0; i < n; i++){
        getAnagram(word,size,n-1);
        if(n == 2)
            display(word,size);
        rotate(word, size, n);
    }
}
// end ANAGRAMS
//===================================================================================================
int main(int argc, char const *argv[])
{
     //Anagrams ===================================================================================
    int size = 4;
    char carr[64];
    printf("Введите слово из %d букв: ", size);
    scanf("%s", carr);
    getAnagram(carr, size, size);
    //end Anagrams ===================================================================================
    return 0;
}

