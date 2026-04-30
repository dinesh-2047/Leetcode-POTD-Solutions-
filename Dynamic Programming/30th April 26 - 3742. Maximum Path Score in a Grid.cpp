// 3742. Maximum Path Score in a Grid


class Solution {
public:
int m , n ; 
vector<vector<vector<int>>>dp; 
int solve(vector<vector<int>> &grid, int k , int i , int j ){
    if(i >= m || j >= n || k < 0  ) return -1e9; 
    if(i == m - 1 && j == n- 1){
        if(grid[i][j] != 0) k--;
        if(k >= 0 ){
            return grid[i][j];
        }
        return -1e9; 
    }

    if(dp[k][i][j] != -1) return dp[k][i][j];

    int right = grid[i][j] + solve(grid, (grid[i][j] != 0 ? k -1 : k ), i, j + 1);
    int down  = grid[i][j] + solve(grid, (grid[i][j] != 0 ? k -1 : k ), i  + 1, j);

    return dp[k][i][j] =  max(right , down);


}
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(k + 1 , vector<vector<int>> ( m + 1, vector<int>(n + 1, -1)));
        int result = solve(grid, k , 0 , 0); 

        return result < 0  ? -1 : result ;
    }
};