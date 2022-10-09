
void gotoxy(int a, int b){

    printf("%c[%d;%df", 0X1B, b, a);
}