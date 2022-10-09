
#include "__gotoxy.h"
#include "__colour.h"
#include "__flash.h"
#include "__gridchecker.h"
#include "__IF_filledchecker.h"
#include "__whoISthePLAYER.h"

#define CROSS 120
#define CIRCLE 111

int getcolumn( int y ){

    if( y == 6 )
    return 0;

    if( y == 11 )
    return 1;

    if( y == 16 )
    return 2;

}

int getrow( int x ){

    if( x == 3 )
    return 0;

    if( x == 6 )
    return 1;

    if( x == 9 )
    return 2;

}

void displayPATTERN( int indexY, int indexX, int grid[indexX][indexY] ){


for(int i=6; i<=16; i+=5){
for(int j=3; j<=9; j+=3){

    gotoxy(i-1, j);

    int indexY = getcolumn( i );
    int indexX = getrow( j );

    printf("%c", grid[indexX][indexY]);

}
}


}

void displayBox( int y, int x ){

    red();

    for(int i=3; i<=18; i+=5){

        for(int j=3; j<=9; j+=3){

            gotoxy(i, j);
            printf("%c", 124);
        }

    }

    reset();



    for(int i=6; i<=16; i+=5){

        for(int j=3; j<=9; j+=3){
            
            gotoxy(i, j);
            printf("%c", 32);}

    }

    cyan();

    gotoxy( y , x );
    printf("%c", 42);

    reset();

}

int boxProcess( char player1[], int size1, char player2[], int size2 ){

    int grid[3][3] = { 32, 32, 32, 32, 32, 32, 32, 32, 32 };

    fflush_Stdin();

    printf("\n\"%s\" please choose either of (x/o) as move ->\t", player1);
    int symbol = getkey();
    

        if( symbol == 88 )
        symbol = CROSS;

        if( symbol == 79 )
        symbol = CIRCLE;


    printf("\n%c (chosen by \"%s\")", symbol, player1 );

    int SYMBOL;

    if( symbol == CROSS )
    SYMBOL = CIRCLE;

    else
    SYMBOL = CROSS;

    printf("\n%c (of \"%s\")", SYMBOL, player2 );


    printf("\n\n\n\npress any key to continue\t");
    getkey();

    clscrn();
    

    int changeOFturns = symbol;

    int choicey = 16;
    int choicex = 9;

    displayBox( choicey, choicex );

    int key = 32;

    bool win = false;
    bool filled = false;
    bool insertionWASsuccessful = false;

    int const winner_HAD_symbol = symbol;

    whoISplaying( changeOFturns, winner_HAD_symbol, player1, 15, player2, 15 );

    while( win == false && filled == false ){

while( key != CROSS && key != CIRCLE ){

key = getkey();


    if( key == 88 )
    key = CROSS;

    if( key == 79 )
    key = CIRCLE;


switch( key ){

        case UP :   
        if( choicex <= 9 && choicex > 3 )
        choicex-=3;

        else
        _flash_the_Screen();

        break;

        case DOWN : 
        if( choicex < 9 && choicex >= 3 )
        choicex+=3;

        else
        _flash_the_Screen();

        break;

        case LEFT : 
        if( choicey <= 16 && choicey > 6 )
        choicey-=5;

        else
        _flash_the_Screen();

        break;

        case RIGHT : 
        if( choicey < 16 && choicey >= 6 )
        choicey+=5;

        else
        _flash_the_Screen();

        break;

}
    clscrn();

    displayBox( choicey, choicex );
    displayPATTERN( 3, 3, grid );
    whoISplaying( changeOFturns, winner_HAD_symbol, player1, 15, player2, 15 );

}



        if( key != changeOFturns ){
                _flash_the_Screen();

                displayBox( choicey, choicex );
                displayPATTERN( 3, 3, grid );
                whoISplaying( changeOFturns, winner_HAD_symbol, player1, 15, player2, 15 );


                key = 32;

                continue;
        }



        else{

            int indexY = getcolumn( choicey );
            int indexX = getrow( choicex );


            if( grid[indexX][indexY] == 32 ){

                grid[indexX][indexY] = key;

                insertionWASsuccessful = true;
                
    }

            else{
            _flash_the_Screen();
            displayBox( choicey, choicex );
        }
    
    }

            displayPATTERN( 3, 3, grid );

            whoISplaying( changeOFturns, winner_HAD_symbol, player1, 15, player2, 15 );



            win = checkPattern( 3, 3, grid );


            filled = checkIFfull( 3, 3, grid);



if( insertionWASsuccessful == true ){
    if( changeOFturns == CROSS )
    changeOFturns = CIRCLE;

    else
    changeOFturns = CROSS;

    insertionWASsuccessful = false;

}

key = 32;

}

if( win == true ){
    if( winner_HAD_symbol != changeOFturns ){

    return 1;
}

    if( winner_HAD_symbol == changeOFturns ){
    
    return 2;
}
}

if( filled == true ){
    
    return 0;
}


}