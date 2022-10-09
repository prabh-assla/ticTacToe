
bool checkIFfull( int i, int j, int grid[i][j] ){

    for(int x=0; x<j; ++x){

        for(int y=0; y<i; ++y){

            if(grid[x][y] == 32)
            return false;
            
        }
    }

return true;
}