
#define UP 65
#define DOWN 66
#define LEFT 68
#define RIGHT 67

int getch(){

        struct termios oldt, newt;

        int ch;
        tcgetattr( STDIN_FILENO, &oldt );
        newt = oldt;

        newt.c_lflag &= ~(ICANON | ECHO);

        tcsetattr( STDIN_FILENO, TCSANOW, &newt );
        ch = getchar();
        tcsetattr( STDIN_FILENO, TCSANOW, &oldt );

return ch;
}

int getkey()
{
	char ch;

	ch = getch();

	if ( ch == 27 ){
    ch = getch();

    if ( ch == 91 ){     
    ch = getch();

    if ( ch == 65|| ch == 66|| ch == 67|| ch == 68 )
	return ch;

}
}
}