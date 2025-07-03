#pragma once
typedef struct snake
{
    int *x;
    int *y;
    int length; // the maximum length of the body
    int body;   // the actual length
} snake;

// Function declarations
void init_snake(snake *s);
void free_snake(snake *s);
void add_position(snake* s,int x, int y);
