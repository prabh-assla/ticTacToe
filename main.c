#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <termios.h>

#include "./__utilities.h"
#include "./__box.h"

int main(){
    clscrn();

    yellow();
        printf( COLOR_BOLD "let's play game (press any key to start)\t" COLOR_OFF );
        
    reset();

    getkey();

    clscrn();

    char player1[25];
    blue();
        printf( COLOR_BOLD "player 'a' name (20 letters only) - " COLOR_OFF );

    reset();

    red();
        scanf("%s", player1);

    reset();

    char player2[25];
    blue();
        printf( COLOR_BOLD "player 'b' name (20 letters only) - " COLOR_OFF );

    reset();

    red();
        scanf("%s", player2);

    reset();

    int i = boxProcess( player1, 15, player2, 15 );

        gotoxy(1, 14);

        black();

            if( i==0 )
            printf( COLOR_BOLD " \x1b[42m draw is declared " COLOR_OFF );

            else if( i==1 ){

                printf( COLOR_BOLD " \x1b[42m %s is the winner ", player1);
                printf( COLOR_OFF );
            }

            else if( i==2 ){

                printf( COLOR_BOLD " \x1b[42m %s is the winner ", player2);
                printf( COLOR_OFF );
            }

        reset();

        printf("                                \n");

    purple();
        printf( COLOR_BOLD "\x1b[40m\n THANKS FOR PLAYING... \t" COLOR_OFF );

    reset(); 
    re_ENABLE();
    
    getkey();


return 0;
}