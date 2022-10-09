void whoISplaying(int thisTIME, int firstlyCHOSEN, char player1[], int size1, char player2[], int size2){

    blue();

    if( thisTIME == firstlyCHOSEN ){
        gotoxy( 1, 14 );
        printf("%s's turn [symbol - %c] :)", player1, thisTIME );
    }

    else{
        gotoxy( 1, 14 );
        printf("%s's turn  [symbol - %c] :)", player2, thisTIME );
    }

    reset();
    
}