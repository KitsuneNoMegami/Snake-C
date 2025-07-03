#include "grid.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <ncurses.h>

/**
 * Draw the grid of the game
 */
int draw_grid(snake *s)
{
    initscr();
    clear(); // Clear screen before drawing

    // Draw top border
    for (int c = 0; c < WIDTH; c++)
    {
        printw("--");
    }
    printw("-\n");

    // Draw grid content
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH + 1; j++)
        {
            bool snake_drawn = false;

            // Check if this position contains snake
            for (int cood = 0; cood < s->body; cood++)
            {
                if (s->y[cood] == i && s->x[cood] == j)
                {
                    if (cood == 0)
                    {
                        mvprintw(i + 1, j * 2, SNAKE_HEAD); // +1 for top border offset
                    }
                    else
                    {
                        mvprintw(i + 1, j * 2, SNAKE_BODY);
                    }
                    snake_drawn = true;
                    break;
                }
            }

            // Draw borders or empty space if no snake
            if (!snake_drawn)
            {
                if (j == 0 || j == WIDTH)
                {
                    mvprintw(i + 1, j * 2, "|");
                }
                else
                {
                    mvprintw(i + 1, j * 2, ".");
                }
            }
        }
    }

    // Draw bottom border
    move(HEIGHT + 1, 0);
    for (int c = 0; c < WIDTH; c++)
    {
        printw("--");
    }
    printw("-\n");
    refresh();
    return EXIT_SUCCESS;
}
