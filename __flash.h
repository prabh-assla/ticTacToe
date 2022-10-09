
void flash(){

clscrn();

    int j = 10000;

    for(int i = 0; i <= j; ++i)
    printf("\e[107m ");

clscrn();

    for(int i = 0; i <= j; ++i)
    printf("\e[0m ");

clscrn();
                                                                            
}

void _flash_the_Screen(){

    for(int i = 0; i<=1; ++i)
    flash();

}
