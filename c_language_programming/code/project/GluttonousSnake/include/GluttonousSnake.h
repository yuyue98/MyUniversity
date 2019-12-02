#ifndef GLUTTONOUSSNAKE_H
#define GLUTTONOUSSNAKE_H
  
struct Snake{  
    short len;  
    short body[MAX_WIDE*MAX_HIGH];  
}snake; 

void draw();
void  run();

#endif