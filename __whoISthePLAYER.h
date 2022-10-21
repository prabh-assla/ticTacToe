void whoISplaying(int thisTIME, int firstlyCHOSEN, char player1[], int size1, char player2[], int size2){

    purple();

    if( thisTIME == firstlyCHOSEN ){
        gotoxy( 1, 14 );
        printf( COLOR_BOLD "\x1b[40m %s's turn (symbol -  \x1b[46m" " \x1b[46m%c " "\x1b[40m) ", player1, thisTIME );
        printf( COLOR_OFF );
    }

    else{
        gotoxy( 1, 14 );
        printf( COLOR_BOLD "\x1b[40m %s's turn  (symbol -  \x1b[46m" " \x1b[46m%c " "\x1b[40m) ", player2, thisTIME );
        printf( COLOR_OFF );
    }

    reset();
}