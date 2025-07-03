#include "snake.h"
#include "grid.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <ncurses.h>

void init_snake(snake* s){
    s->body=1;
    s->length=8; //initialise the length at 8
    s->x=malloc(s->length*sizeof(int));
    s->y=malloc(s->length*sizeof(int));
    s->x[0]= WIDTH/2;
    s->y[0]=HEIGHT/2;
}

void free_snake(snake* s)
{
    free(s->x);
    free(s->y);
    s->x=NULL;
    s->y=NULL;
    s->body=0;
    s->length=0;
}

void add_position(snake* s, int x, int y){
    if (s->body==s->length){
        s->length*=2;
        s->x=realloc(s->x,s->length);
        s->y=realloc(s->y,s->length);
    }
    s->x[s->body]=x;
    s->y[s->body]=y;
    s->body++;
}