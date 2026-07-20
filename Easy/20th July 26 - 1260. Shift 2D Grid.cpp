// 1260. Shift 2D Grid

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int shift = 0; shift < k ; shift++){
            int last = grid[m-1][n-1];
            for(int i = m -1; i >= 0 ; i --){
                int prev_end = -1; 
                if(i - 1 >= 0 ) prev_end = grid[i - 1][n-1];
                for(int j = n - 2; j >=0 ; j--){
                     grid[i][j + 1] = grid[i][j];
                }
                grid[i][0] = prev_end; 
            }
            grid[0][0] = last; 
        }
        return grid; 
    }
};