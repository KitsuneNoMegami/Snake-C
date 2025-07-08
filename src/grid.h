#pragma once
#include "snake.h"
#include <ncurses.h>

#define HEIGHT 30
#define WIDTH 70
#define SNAKE_BODY "#"
#define SNAKE_HEAD "o"
#define FOOD "@"
/**
 * @param game Window where we draw
 * @param s the snake to draw
 * Draw the grid of the game
 */
int draw_grid(WINDOW *game, snake *s);

/**
 * @param log Window where we draw
 * Draw the rules of the game 
 */
int draw_rules(WINDOW *log);