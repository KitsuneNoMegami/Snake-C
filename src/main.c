#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#include "snake.h"
#include "grid.h"
#include "apple.h"

int main()
{
    srand(time(NULL));
    snake s;
    init_snake(&s);
    int *food = malloc(sizeof(int) * 2);
    create_apple(food);
    // Debug: Print snake info before ncurses
    // printf("Snake initialized: body=%d, length=%d\n", s.body, s.length);
    // printf("Snake head position: (%d, %d)\n", s.x[0], s.y[0]);
    // printf("Press Enter to continue...\n");
    // getchar();

    // printf("After adding positions: body=%d\n", s.body);
    // for(int i = 0; i < s.body; i++) {
    //     printf("Position %d: (%d, %d)\n", i, s.x[i], s.y[i]);
    // }
    // printf("Press Enter to start ncurses...\n");
    // getchar();
    add_position(&s, s.x[0] + 1, s.y[0]);
    initscr();
    noecho();             // Don't echo pressed keys
    keypad(stdscr, TRUE); // Enable arrow keys
    curs_set(0);
    clear();
    refresh();

    WINDOW *game, *log;

    // Utiliser WIDTH*3 pour avoir assez d'espace pour les symboles de 3 caractères
    game = newwin(HEIGHT, WIDTH*3, 0, 0);
    log = newwin(HEIGHT / 3, WIDTH*3, HEIGHT + 1, 0);

    if (game == NULL || log == NULL)
    {
        endwin();
        printf("Failed to create windows\n");
        return 1;
    }

    draw_grid(game, &s, food);
    draw_rules(log);
    
    int key, gameOver = 0;
    int last_direction = KEY_UP; // Default direction
    title_screen(game);
    getch();
    timeout(850); // Réduire le timeout pour un mouvement plus fluide
    while (!gameOver)
    {
        key = getch();
        
        if (key == 'q' || key == 'Q')
            break;
            
        // Update direction only if a valid key is pressed
        if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)
        {
            last_direction = key;
        }
        
        // Move snake in the last direction (or if no key was pressed due to timeout)
        if (key == ERR || key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)
        {
            gameOver = move_snake(last_direction, &s);
            eat_apple(&s, food);
            draw_grid(game, &s, food);

            if (gameOver)
            {
                draw_lose(game);
                nodelay(stdscr, FALSE); // Remove timeout for final key press
                getch();
                break;
            }
        }
    }

    free_snake(&s);
    free(food);
    delwin(game); /* Effacer la fenêtre de jeu et libérer la mémoire et les informations de la structure de données de la fenêtre */
    delwin(log);
    endwin(); // On attend que l'utilisateur appui sur une touche pour quitter
    return EXIT_SUCCESS;
}