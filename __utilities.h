
// ---------------------gotoxy--------------------
void gotoxy(int a, int b)
{

    printf("%c[%d;%df", 0X1B, b, a);
}

// to hide the cursor
void hide_cursor()
{

    printf("\e[?25l");
}

// to re-enable the cursor
void re_ENABLE()
{

    printf("\e[?25h");
}

// to clear the screen
void clscrn()
{

    printf("\e[1;1H\e[2J");
    gotoxy(1, 1);
}

// --------------reading keys--------------------

#define UP 65
#define DOWN 66
#define LEFT 68
#define RIGHT 67

int getch()
{

    struct termios oldt, newt;

    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

int getkey()
{
    char ch;

    ch = getch();

    if (ch == 27)
    {
        ch = getch();

        if (ch == 91)
        {
            ch = getch();

            if (ch == 65 || ch == 66 || ch == 67 || ch == 68)
                return ch;
        }
    }
}

// to flush the output buffer
void fflush_Stdin()
{
    int i;

    do
    {
        i = getkey();
    } while (i != '\n' && i != EOF);
}

//-------------------------------------------colors------------------------------------

void red()
{
    printf("\033[0;31m");
}

void cyan()
{
    printf("\033[0;36m");
}

void yellow()
{
    printf("\033[0;33m");
}

void purple()
{
    printf("\033[0;35m");
}

void green()
{
    printf("\033[0;32m");
}

void blue()
{
    printf("\033[0;34m");
}

void reset()
{
    printf("\033[0;37m");
}

//--------------------------------------flash-------------------------------------
void flash()
{

    clscrn();

    int j = 3000;

    for (int i = 0; i <= j; ++i)
        printf("\e[107m ");

    clscrn();

    // for(int i = 0; i <= j; ++i)
    printf("\e[0m ");
    reset();

    clscrn();
}

void _flash_the_Screen()
{

    for (int i = 0; i <= 1; ++i)
        flash();
}

//bold text
#define COLOR_BOLD "\e[1m"
#define COLOR_OFF "\e[m"