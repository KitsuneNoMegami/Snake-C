#include "snake.h"
#include "grid.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

void create_apple(int *apple)
{
    apple[0] = 1 + (rand() % (WIDTH - 2));  // X coordinate: 1 to WIDTH-2
    apple[1] = 1 + (rand() % (HEIGHT - 2)); // Y coordinate: 1 to HEIGHT-2
}

void eat_apple(snake *s, int *apple)
{
    if (snake_get_head_x(s) == apple[0] && snake_get_head_y(s) == apple[1])
    {
        add_position_end(s);
        create_apple(apple);
        s->score += 25;
        if (s->score % 100 == 0)
        {
            s->speed += 100;
            int new_timeout = (850 - s->speed) > 150 ? (850 - s->speed) : 150;
            timeout(new_timeout);
        }
    }
}