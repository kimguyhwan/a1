#include <stdio.h>
#include <math.h>
#include <Windows.h>

#define PI 3.14159226535897

void moveCursor(int x, int y)
{
    printf("\x1b[%d;%dH", y, x);
}


void printBomb(int isExploded)
{

    if (isExploded)
    {
        printf("\x1b[A^^^^^^^");
        printf("\x1b[B\x1b[7D!!Bomb!!");
        printf("\x1b[B\x1b[7D^^^^^^^^");
    }
    else
        printf("(  b  )");
}

int main()
{
    int startX = 14, startY = 9;
    int x = startX, y = startY;

    int bombX = 2, bombY = 2;
    const int BOMB_LEN = 7;


    int dirX[4] = { 0, 1, 0, -1 };
    int dirY[4] = { 1, 0,-1,  0 };

    int tx, ty, nx, ny;
    int i, j, d;


    tx = x; ty = y;
    for (i = 0; i < 12; i = i + 1)
    {
        d = i % 4;


        int step = (i == 0 ? 1 : (i == 11 ? 13 : i + 2));

        for (j = 0; j < step; j = j + 1)
        {
            tx += dirX[d];
            ty += dirY[d];
            moveCursor(tx, ty);
            printf("#");
        }
    }


    moveCursor(bombX, bombY);
    printBomb(0);


    tx = x; ty = y;
    moveCursor(tx, ty); printf("*");

    for (i = 0; i < 12; i = i + 1)
    {
        d = i % 4;
        int step = (i == 0 ? 1 : (i == 11 ? 13 : i + 2));

        for (j = 0; j < step; j = j + 1)
        {
            Sleep(200);


            moveCursor(tx, ty); printf(" ");


            nx = tx + dirX[d];
            ny = ty + dirY[d];


            if (ny == bombY && nx >= bombX && nx <= bombX + BOMB_LEN - 1) {
                moveCursor(bombX, bombY);
                printBomb(1);
                moveCursor(10, 20);
                return 0;
            }


            tx = nx; ty = ny;
            moveCursor(tx, ty); printf("*");
        }
    }

    moveCursor(10, 20);
    return 0;
}