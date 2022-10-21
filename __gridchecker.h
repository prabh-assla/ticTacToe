
bool checkIFfull( int i, int j, int grid[i][j] ){

    for(int x=0; x<j; ++x){

        for(int y=0; y<i; ++y){

            if(grid[x][y] == 32)
            return false;
            
        }
    }

return true;
}

bool checkPattern( int i, int j, int grid[i][j] ){

    char symbol = grid[0][0];

            if( symbol != 32 ){

            if(grid[0][1] == symbol && grid[0][2] == symbol)
            return true;

            if(grid[1][0] == symbol && grid[2][0] == symbol)
            return true;

            if(grid[1][1] == symbol && grid[2][2] == symbol)
            return true;

            }


            symbol = grid[0][2];

            if( symbol != 32 ){

            if(grid[1][1] == symbol && grid[2][0] == symbol)
            return true;

            if(grid[1][2] == symbol && grid[2][2] == symbol)
            return true;

            }


            symbol = grid[0][1];

            if( symbol != 32 ){

            if(grid[1][1] == symbol && grid[2][1] == symbol)
            return true;

            }


            symbol = grid[2][0];

            if( symbol != 32 ){

            if(grid[2][1] == symbol && grid[2][2] == symbol)
            return true;

            }


            symbol = grid[1][0];

            if( symbol != 32 ){
            
            if(grid[1][1] == symbol && grid[1][2] == symbol)
            return true;

            }

return false;
}