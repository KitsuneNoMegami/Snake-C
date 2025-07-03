#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <ncurses.h>

#include "snake.h"
#include "grid.h"

int main(){
    draw_grid();
    return EXIT_SUCCESS;
}