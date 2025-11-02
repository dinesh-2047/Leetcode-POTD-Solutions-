// 2257. Count Unguarded Cells in the Grid/


class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m , vector<int>(n , 0));
       
   
        for(auto &wall : walls){
           grid[wall[0]][wall[1]] = -1; 
        }
        for(auto &guard : guards){
            grid[guard[0]][guard[1]] = -2;
        }

        for(auto &guard : guards){
            int i = guard[0];
            int j = guard[1];


            //down
            for(int row = i + 1 ; row < m ; row++){
                    if(grid[row][j] != -1 && grid[row][j] != -2){
                        grid[row][j] = 1; 
                    }
                    else{
                        break; 
                    }
            }

            //up
            for(int row = i-1; row >= 0; row--){
                if(grid[row][j] != -1&& grid[row][j] != -2){
                        grid[row][j] = 1; 
                    }
                    else{
                        break; 
                    }
            }


            //left 
            for(int col = j-1; col >= 0; col--){
                if(grid[i][col]!=-1&& grid[i][col] != -2){
                        grid[i][col] = 1; 
                    }
                    else{
                        break; 
                    }
            }

            //right
            for(int col =  j + 1; col < n; col++){
                     if(grid[i][col]!=-1&& grid[i][col] != -2){
                        grid[i][col] = 1; 
                    }
                    else{
                        break; 
                    }
            }
        }


    

        int result = 0 ; 
        for(int i = 0 ; i  < m; i++){
            for(int j = 0 ; j  < n; j++){
                if(grid[i][j] == 0 ){
                    result++;
                }
            }
        }




        return result; 

    }
};