#include "grid.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <ncurses.h>


int draw_grid(WINDOW *game, snake *s, int* apple)
{
    wclear(game); // Clear screen before drawing

    // Redraw the border (since wclear removes it)
    box(game, ACS_VLINE, ACS_HLINE);

    // Draw grid content (leave space for borders - start at 1,1 and end before borders)
    for (int i = 1; i < HEIGHT - 1; i++)
    {
        for (int j = 1; j < WIDTH - 1; j++)
        {
            mvwprintw(game, i, j*3, " . ");
        }
    }
    
    // Dessiner la pomme
    mvwprintw(game, apple[1], apple[0]*3, FOOD);

    // Dessiner les positions du serpent
    for (int i = 0; i < s->body; i++)
    {
        // Make sure snake positions are within the bordered area
        if (s->x[i] >= 1 && s->x[i] < WIDTH - 1 && s->y[i] >= 1 && s->y[i] < HEIGHT - 1)
        {
            mvwprintw(game, s->y[i], s->x[i]*3, (i == 0) ? SNAKE_HEAD : SNAKE_BODY);
        }
    }

    mvwprintw(game, 0, 1, " Game ");
    mvwprintw(game, HEIGHT-1, 1, " Score : %d ", s->score);
    mvwprintw(game,HEIGHT-1, 10,"Speed : %d",s->speed%100);
    wrefresh(game);
    return EXIT_SUCCESS;
}

int draw_rules(WINDOW *log)
{
    wclear(log);

    // Redraw the border
    box(log, ACS_VLINE, ACS_HLINE);

    mvwprintw(log, 0, 1, " Rules ");
    mvwprintw(log, 2, 2, "Controls:");
    mvwprintw(log, 3, 2, "Arrow keys to move : UP, DOWN, LEFT, RIGHT");
    mvwprintw(log, 4, 2, "q to quit");

    wrefresh(log);
    return EXIT_SUCCESS;
}

void draw_lose(WINDOW *game){
    wclear(game);
    box(game, ACS_VLINE, ACS_HLINE);
    
    int center_y = HEIGHT / 2;
    int center_x = (WIDTH*3) / 2;
    
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

void title_screen(WINDOW *game){
    wclear(game);
    box(game, ACS_VLINE, ACS_HLINE);
    
    int center_y = HEIGHT / 2;
    int center_x = (WIDTH*3) / 2;

    mvwprintw(game, center_y - 5, center_x - 18, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    mvwprintw(game, center_y - 4, center_x - 18, "                                ");
    mvwprintw(game, center_y - 3, center_x - 18, "          W E L C O M E         ");
    mvwprintw(game, center_y - 2, center_x - 18, "           IN SNAKE C           ");
    mvwprintw(game, center_y - 1, center_x - 18, "                                ");
    mvwprintw(game, center_y,     center_x - 18, "         Rules are below        ");
    mvwprintw(game, center_y + 1, center_x - 18, "             Have fun !         ");
    mvwprintw(game, center_y + 2, center_x - 18, "                                ");
    mvwprintw(game, center_y + 3, center_x - 18, "    Press any key to start :    ");
    mvwprintw(game, center_y + 4, center_x - 18, "                                ");
    mvwprintw(game, center_y + 5, center_x - 18, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    
    wrefresh(game);
}