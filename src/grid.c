#include "grid.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <ncurses.h>


int draw_grid(WINDOW *game, snake *s)
{
    wclear(game); // Clear screen before drawing

    // Redraw the border (since wclear removes it)
    box(game, ACS_VLINE, ACS_HLINE);

    // Draw grid content (leave space for borders - start at 1,1 and end before borders)
    for (int i = 1; i < HEIGHT - 1; i++)
    {
        for (int j = 1; j < WIDTH - 1; j++)
        {
            mvwprintw(game, i, j, ".");
        }
    }

    // Draw snake positions
    for (int i = 0; i < s->body; i++)
    {
        // Make sure snake positions are within the bordered area
        if (s->x[i] >= 1 && s->x[i] < WIDTH - 1 && s->y[i] >= 1 && s->y[i] < HEIGHT - 1)
        {
            mvwprintw(game, s->y[i], s->x[i], (i == 0) ? SNAKE_HEAD : SNAKE_BODY);
        }
    }

    wrefresh(game);
    return EXIT_SUCCESS;
}

int draw_rules(WINDOW *log)
{
    wclear(log);

    // Redraw the border
    box(log, ACS_VLINE, ACS_HLINE);

    // Draw rules inside the border
    mvwprintw(log, 1, 1, "Controls:");
    mvwprintw(log, 2, 1, "Arrow keys to move");
    mvwprintw(log, 3, 1, "q to quit");
    mvwprintw(log, 4, 1, "Press any key to continue...");

    wrefresh(log);
    return EXIT_SUCCESS;
}
