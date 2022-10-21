#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <termios.h>

#include "./__utilities.h"
#include "./__box.h"

int main(){
    printf("\e[1m");
    clscrn();

    yellow();
        printf("let's play game (press any key to start)\t");
    reset();

    getkey();

    clscrn();

    char player1[25];
    blue();
        printf("player 'a' name (20 letters only) - ");
    reset();

    red();
        scanf("%s", player1);
    reset();

    char player2[25];
    blue();
        printf("player 'b' name (20 letters only) - ");
    reset();

    red();
        scanf("%s", player2);
    reset();

    int i = boxProcess( player1, 15, player2, 15 );

        gotoxy(1, 14);

        yellow();

            if( i==0 )
            printf("draw is declared \a");

            if( i==1 )
            printf("%s is the winner \a", player1);

            if( i==2 )
            printf("%s is the winner \a", player2);

        reset();

        printf("                                \n");

    purple();
        printf("\n\n\"THANKS FOR PLAYING\"\n\n");
    reset();

    printf(COLOR_OFF);
return 0;
}