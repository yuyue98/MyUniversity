#include "myheader.h"
#include "GluttonousSnake.h"


short dx = 1, dy = 0, randxy, score = 0;  
COORD coord;  

int main(int argc, char* argv[]) {
    /**
     * The c language project main program
     */
    snake.body[MAX_WIDE*MAX_HIGH] = 0;  
    snake.body[0] = (MAX_HIGH/2)<<8 | MAX_WIDE/2;  
    snake.len = 1;  
    srand((unsigned)time(NULL));   
    randxy = ((rand() % 16 + 0) <<8) | (rand() % 50 + 0);  
    SMALL_RECT rect;  
    rect.Top = 0, rect.Left = 0;  
    rect.Bottom = MAX_HIGH, rect.Right  = MAX_WIDE;
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &rect);  
    run();  
    printf("Your Score:%d", score);
    system("pause");
    return 0;
}