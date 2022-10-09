
void hide_cursor(){

    printf("\e[?25l");
}

void re_ENABLE(){

    printf("\e[?25h");
}
