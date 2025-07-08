#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <ncurses.h>

#include "snake.h"
#include "grid.h"

int main()
{
    snake s;
    init_snake(&s);

    // Debug: Print snake info before ncurses
    // printf("Snake initialized: body=%d, length=%d\n", s.body, s.length);
    // printf("Snake head position: (%d, %d)\n", s.x[0], s.y[0]);
    // printf("Press Enter to continue...\n");
    // getchar();

    add_position(&s, 5, 5);
    add_position(&s, 6, 5);
    add_position(&s, 7, 5);

    // printf("After adding positions: body=%d\n", s.body);
    // for(int i = 0; i < s.body; i++) {
    //     printf("Position %d: (%d, %d)\n", i, s.x[i], s.y[i]);
    // }
    // printf("Press Enter to start ncurses...\n");
    // getchar();

    initscr();
    clear();
    refresh();

    WINDOW *game, *log;

    game = newwin(HEIGHT, WIDTH, 0, 0);
    log = newwin(HEIGHT / 2, WIDTH, HEIGHT + 1, 0);

    if (game == NULL)
    {
        endwin();
        printf("Failed to create game window\n");
        return 1;
    }

    if (log == NULL)
    {
        endwin();
        printf("Failed to create log window\n");
        return 1;
    }

    draw_grid(game, &s);
    draw_rules(log);

    int move=getch();
    mvwprintw(log,5,1,"Key pressed: %c",move);
    free_snake(&s);
    delwin(game); /* Effacer la fenêtre de jeu et libérer la mémoire et les informations de la structure de données de la fenêtre */
    delwin(log);
    endwin(); // On attend que l'utilisateur appui sur une touche pour quitter
    return EXIT_SUCCESS;

}