#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <ncurses.h>

#define HEIGHT 20
#define WIDTH 20

/**
 * Draw the grid of the game
 */
int draw_grid(){
    for (int c=0;c<WIDTH+1;c++){
        printf("---");
    }
    printf("\n");
    for (int i=0;i<HEIGHT;i++){
        for (int j=0;j<WIDTH+1;j++){
            if (j==0||j==WIDTH){
                printf(" | ");
            }
            else{printf(" . ");}
        }
        printf("\n");
    }
    for (int c=0;c<WIDTH+1;c++){
        printf("---");
    }
    printf("\n");
    return EXIT_SUCCESS;
}

int main(){
    draw_grid();
    return EXIT_SUCCESS;
}