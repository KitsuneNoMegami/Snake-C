#include "snake.h"
#include "grid.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <ncurses.h>

void init_snake(snake *s)
{
    s->body = 1;
    s->length = 8; // initialise the length at 8
    s->x = malloc(s->length * sizeof(int));
    s->y = malloc(s->length * sizeof(int));
    s->x[0] = WIDTH / 2;
    s->y[0] = HEIGHT / 2;
    s->score=0;
    s->speed=0;
}

void free_snake(snake *s)
{
    free(s->x);
    free(s->y);
    s->x = NULL;
    s->y = NULL;
    s->body = 0;
    s->length = 0;
}

int snake_get_head_x(snake *s){
    return s->x[0];
}

int snake_get_head_y(snake *s){
    return s->y[0];
}

void add_position(snake *s, int x, int y)
{
    if (s->body == s->length)
    {
        s->length *= 2;
        s->x = realloc(s->x, s->length * sizeof(int));
        s->y = realloc(s->y, s->length * sizeof(int));
    }
    s->x[s->body] = x;
    s->y[s->body] = y;
    s->body++;
}

void add_position_end(snake *s)
{
    int end_x= s->x[s->body-1];
    int end_y= s->y[s->body-1];
    add_position(s, end_x, end_y);
}

void move_body(snake *s)
{
    // Move each body segment to the position of the segment in front of it
    for (int i = s->body - 1; i > 0; i--)
    {
        s->x[i] = s->x[i - 1];
        s->y[i] = s->y[i - 1];
    }
}

int move_snake(int key, snake *s)
{
    int gameOver = false;

    switch (key)
    {
    case KEY_UP:
        if (s->y[0] > 1 && s->y[0] - 1 != s->y[1])
        {
            move_body(s);
            s->y[0] -= 1;
        }
        else
        {
            gameOver = true;
        }
        break;

    case KEY_DOWN:
        if (s->y[0] < HEIGHT - 2 && s->y[0] + 1 != s->y[1])
        {
            move_body(s);
            s->y[0] += 1;
        }
        else
        {
            gameOver = true;
        }
        break;

    case KEY_LEFT:
        if (s->x[0] > 1 && s->x[0] - 1 != s->x[1])
        {
            move_body(s);
            s->x[0] -= 1;
        }
        else
        {
            gameOver = true;
        }
        break;

    case KEY_RIGHT:
        if (s->x[0] < WIDTH - 2 && s->x[0] + 1 != s->x[1])
        {
            move_body(s);
            s->x[0] += 1;
        }
        else
        {
            gameOver = true;
        }
        break;
    }
    return gameOver;
}

