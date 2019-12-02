#include "myheader.h"
#include "GluttonousSnake.h"

extern short dx, dy, randxy, score;  
extern COORD coord;  

void draw()  
{  
    for(short i = 0; i < snake.len; i++){  
        coord.X = snake.body[i] & 127;  
        coord.Y = snake.body[i] >> 8;  
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  
        putchar('*');  
    }  
    coord.X = randxy & 127;  
    coord.Y = randxy >> 8;  
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  
    putchar('*');  
}  
void  run()  
{  
    char key;  
    short i, j;  
    while( snake.body[0] > 0 && ( (snake.body[0] & 127) < MAX_WIDE) && (snake.body[0]>>8 < MAX_HIGH) ){  
        draw();  
        for(;kbhit();)  key = getch();  
        switch(key){  
        case 'W': dx = 0, dy = -1; break;  
        case 'S': dx = 0, dy = 1; break;  
        case 'A': dx = -1, dy = 0; break;  
        case 'D': dx = 1, dy = 0; break;  
        }  
        for(j = 1; j < snake.len; j++)  
            if(snake.body[j] == snake.body[0])  
                return;  
        if(randxy == snake.body[0]){  
                snake.len++, score += 10;  
                randxy = ((rand() % 16 + 0) <<8) | (rand() % 50 + 0);  
        }  
        for(i = snake.len-1; i > 0; i--)  
            snake.body[i] = snake.body[i-1];  
        snake.body[0] = ((snake.body[0] & 127) + dx) | ((snake.body[0] >>8) + dy)<<8;  
        Sleep(500);  
        system("cls");    
    }  
} 