#pragma once
#include "snake.h"
#include <ncurses.h>

#define HEIGHT 30
#define WIDTH 35
#define SNAKE_BODY " o "
#define SNAKE_HEAD " 0 "
#define FOOD " @ "
/**
 * @param game Window where we draw
 * @param s the snake to draw
 * @param apple the food
 * Draw the grid of the game
 */
int draw_grid(WINDOW *game, snake *s, int* apple);

/**
 * @param log Window where we draw
 * Draw the rules of the game 
 */
int draw_rules(WINDOW *log);

void draw_lose(WINDOW *game);

void title_screen(WINDOW *title);