// goto particular col and row
static inline void gotoxy(int a, int b){
    printf("%c[%d;%df", 0X1B, b, a);

}


// hide cursor & re-enable cursor
static inline void hide_cursor(){
    printf("\e[?25l");

}

static inline void re_ENABLE(){
    printf("\e[?25h");

}


// clear screen
static inline void clscrn(){
    printf("\e[1;1H\e[2J");
    gotoxy(1, 1);

}


// read keys
    #define UP 65
    #define DOWN 66
    #define LEFT 68
    #define RIGHT 67

int getch(){
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

int getkey(){
    char ch = getch();

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


// flushing output buffer
void fflush_Stdin(){
    int i;

    do{
        i = getkey();

    } while (i != '\n' && i != EOF);
}


// color setting...
static inline void red(){
    printf("\033[0;31m");

}

static inline void cyan(){
    printf("\033[0;36m");

}

static inline void yellow(){
    printf("\033[0;33m");

}

static inline void purple(){
    printf("\033[0;35m");

}

static inline void green(){
    printf("\033[0;32m");

}

static inline void blue(){
    printf("\033[0;34m");

}

static inline void black(){
    printf("\x1b[30m");

}

static inline void reset(){
    printf("\033[0;37m");

}


// flash functionality...
void flash(){
    clscrn();

        int j = 3000;

        for (int i = 0; i <= j; ++i)
            printf("\e[107m");

    clscrn();

        printf("\e[0m");
        reset();

    clscrn();

}

void _flash_the_Screen(){

    for (int i = 0; i <= 1; ++i)
        flash();
}

//bold text utility

#define COLOR_BOLD "\e[1m"
#define COLOR_OFF "\e[m"