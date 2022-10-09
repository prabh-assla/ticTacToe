#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <termios.h>

#include "__cursor.h"

void clscrn(){

    printf("\e[1;1H\e[2J");
    gotoxy(1, 1);
}

#include "__getkey.h"

void fflush_Stdin(){
    int i;

    do{
    i = getkey();
    } while( i != '\n' && i != EOF );

}

#include "__box.h"

int main(){

    hide_cursor();

    clscrn();

    printf("let's play game (press any key to start)\t");
    getkey();

    clscrn();

    char player1[15];
    printf("player 'a' name (10 letters only) - ");
    scanf("%s", player1);

    char player2[15];
    printf("player 'b' name (10 letters only) - ");
    scanf("%s", player2);

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


    printf("                             ");



    purple();
    

    printf("\n\n\"THANKS FOR PLAYING\"");


    reset();

    gotoxy(1, 20);

return 0;

}
