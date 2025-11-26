// 2435. Paths in Matrix Whose Sum Is Divisible by K 


// Approach 1 
class Solution {
public:
int m , n ; 
vector<vector<vector<int >>>dp ;
int mod = 1e9 + 7 ; 
int solve(vector<vector<int>> &grid ,int i , int j , int sum, int &k ){
    if( i>= m || j>= n ){
        return 0 ; 
    }

    if( i  == m - 1 && j == n-1 ){
        sum = ((sum + grid[i][j])%k)%mod;
        if(sum == 0){
            return 1; 
        }
        else return 0 ; 
    }

    if(dp[i][j][sum]!=-1) return dp[i][j][sum];

    int down = solve(grid, i + 1 , j,(sum+ grid[i][j])%k, k)%mod;
    int right = solve(grid ,i , j + 1, (sum + grid[i][j])%k, k )%mod;

    return dp[i][j][sum] = (down + right )%mod; 
}

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m + 1, vector<vector<int>> (n + 1,vector<int>(k+1, -1)));

        return solve(grid,  0 , 0, 0, k);
    }
};


//approach 2 
class Solution {
public:
int mod = 1e9 + 7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>>dp(m + 1, vector<vector<int>>(n + 1, vector<int>(k +1, 0)));

        for(int rem = 0 ;  rem < k ; rem++){
            int val = (rem + grid[m - 1][n-1])%k; 
            dp[m-1][n-1][rem] = (val == 0) ? 1 : 0;
        }

        for(int i = m-1; i >= 0 ; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                for(int rem = 0 ; rem  < k ; rem++){
                    if(i == m-1 && j == n-1) continue; 

                    int new_rem = ((rem + grid[i][j])%k); 

                    int down = dp[i + 1][j][new_rem];
                    int right = dp[i][j + 1][new_rem];

                    dp[i][j][rem] = (down + right)%mod; 
                }
            }
        }

        return dp[0][0][0];
    }
};