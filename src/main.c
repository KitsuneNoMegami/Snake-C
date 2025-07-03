#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <ncurses.h>

#include "snake.h"
#include "grid.h"

int main(){
    snake s;
    //WINDOW *win;
    init_snake(&s);
    //## Test Adding positions ##//
    add_position(&s,1,1);
    add_position(&s,2,1);
    add_position(&s,3,1);
    add_position(&s,4,1);
    printf("Taille :%d Capacité: %d",s.body,s.length);
    for (int i=0;i<s.body;i++){
        printf ("\nx: %d y: %d",s.x[i],s.y[i]);
    }
    printf("\n");
    draw_grid(&s);
    getch();               // On attend que l'utilisateur appui sur une touche pour quitter
    endwin();
    return EXIT_SUCCESS;
}