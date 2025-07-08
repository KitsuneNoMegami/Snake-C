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
    mvwprintw(log, 1, 2, "Controls:");
    mvwprintw(log, 2, 2, "Arrow keys to move : UP, DOWN, LEFT, RIGHT");
    mvwprintw(log, 4, 2, "q to quit");

    wrefresh(log);
    return EXIT_SUCCESS;
}

void draw_lose(WINDOW *game){
    wclear(game);
    box(game, ACS_VLINE, ACS_HLINE);
    
    int center_y = HEIGHT / 2;
    int center_x = WIDTH / 2;
    
    // Large text using multiple lines
    mvwprintw(game, center_y - 4, center_x - 18, "################################");
    mvwprintw(game, center_y - 3, center_x - 18, "#                              #");
    mvwprintw(game, center_y - 2, center_x - 18, "#          G A M E             #");
    mvwprintw(game, center_y - 1, center_x - 18, "#          O V E R             #");
    mvwprintw(game, center_y,     center_x - 18, "#         You lose...          #");
    mvwprintw(game, center_y + 1, center_x - 18, "#                              #");
    mvwprintw(game, center_y + 2, center_x - 18, "#   Press any key to exit...   #");
    mvwprintw(game, center_y + 3, center_x - 18, "#                              #");
    mvwprintw(game, center_y + 4, center_x - 18, "################################");
    
    wrefresh(game);
}