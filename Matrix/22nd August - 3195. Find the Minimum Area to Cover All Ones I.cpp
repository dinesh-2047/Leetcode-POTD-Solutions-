// 3195. Find the Minimum Area to Cover All Ones I

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int miniRow = m; 
        int maxiRow = 0 ; 
        int miniCol = n ;
        int maxiCol = 0 ; 


        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j  < n;j++){
                if(grid[i][j] == 1){
                    miniRow = min(miniRow , i);
                    maxiRow = max(maxiRow , i);
                    miniCol = min(miniCol , j);
                    maxiCol = max(maxiCol , j);
                }
            }
        }

        int l = maxiRow - miniRow + 1; 
        int b = maxiCol - miniCol + 1; 

        return l * b;  

    }
};