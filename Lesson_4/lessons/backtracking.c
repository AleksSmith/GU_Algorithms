// Aleksey Kuznetsov <alek-kuzne@yandex.ru>
// Урок 4. Рекурсия, рекурсивные алгоритмы

#include<stdio.h>
#include<stdlib.h>

#define HEIGHT 8
#define WIDTH 8
#define QUEENS 8
#define KNIGHTS HEIGHT*WIDTH-1

int board[HEIGHT][WIDTH];

void annul(){       // функция очистки поля
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            board[i][j] = 0;
        }
    }
}

void printBoard(){  // функция печати поля
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            printf("%3d",board[i][j]);
        }
        printf("\n");
    }
}
/*================================================================================================= 
eight queens
 ==================================================================================================
 */
int checkQueen(int y, int x ){  // функция проверки - бъёт ли кого-то ферзь
    for (int  i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            if(board[i][j] != 0){
                if(!(i == y && j == x)){
                    if(i == y || j == x) return 0;
                    if(abs(i - y) == abs(j - x)) return 0;
                }
            }
        }
    }
    return 1;
}

int checkBoard(){       // функция проверки поля
    for (int y = 0; y < HEIGHT; y++){
        for (int x = 0; x < WIDTH; x++){
            if(board[y][x] != 0){
                if (checkQueen(y, x) == 0)
                    return 0;
            }
        }
    }
    return 1;    
}

int queens(int n){      // реализация рекурсивной функции расстановки ферзей на поле
    if(checkBoard() == 0) return 0;
    if(n == QUEENS + 1) return 1;
    for (int y = 0; y < HEIGHT; y++){
        for (int x = 0; x < WIDTH; x++){
            if(board[y][x] == 0){
                board[y][x] = n;
                if (queens(n + 1))
                    return 1;
                board[y][x] = 0;
            }
        }
    }
    return 0;
}
/*================================================================================================
 end eight queens */

/*================================================================================================ 
the knight walks on the chessboard 
==================================================================================================
*/

int possible[][2] = { {-2,1}, {-1,2}, {1,2}, {2,1},
                      {2,-1}, {1,-2}, {-1,-2}, {-2,-1} };

int isPossible(int x, int y){
    return (x >= 0) && (x < WIDTH) && (y >= 0) && (y < HEIGHT) && (board[y][x] == 0);
}

int knightMove(int x, int y, int move){
    int nextX;
    int nextY;
    board[y][x] = move;
    if(move > KNIGHTS) return 1;
    for (int i = 0; i < 8; i++){
        nextX = x + possible[i][1];
        nextY = y + possible[i][0];
        if(isPossible(nextX, nextY) && knightMove(nextX, nextY, move + 1))
            return 1;
    }
    board[y][x] = 0;
    return 0;
}

/*================================================================================================ 
the knight walks on the chessboard  */

int main(int argc, char const *argv[]){
    
/* eight queens */
    annul();
    queens(1);
    printBoard();
    printf("\n");
/* knight walks */
    annul();
    knightMove(0,0,1);
    printBoard();
    return 0;
}