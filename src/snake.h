#pragma once
typedef struct snake
{
    int *x;
    int *y;
    int length; // the maximum length of the body
    int body;   // the actual length
    int score;
    int speed;
} snake;

// Function declarations
void init_snake(snake *s);
void free_snake(snake *s);
int snake_get_head_x(snake *s);
int snake_get_head_y(snake *s);
void add_position(snake* s,int x, int y);
void add_position_end(snake *s);
void move_body(snake *s);
int move_snake(int key, snake *s);
