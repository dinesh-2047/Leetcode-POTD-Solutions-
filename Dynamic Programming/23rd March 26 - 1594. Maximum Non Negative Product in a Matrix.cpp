// 1594. Maximum Non Negative Product in a Matrix


// Approach 1  rec + memo 
class Solution {
public:
    int m, n;
    using ll = long long;
    int mod = 1e9 + 7 ; 
    map<pair<ll , ll>, pair<ll , ll>>dp; 
    pair<ll, ll> solve(vector<vector<int>>& grid, int i, int j) {
        if (i == m - 1 && j == n - 1) {
            return {grid[i][j], grid[i][j]};
        }

        pair<ll, ll>key = {i, j};
        if(dp.count(key)) return dp[key];

        ll maxi = -1e18;
        ll mini = 1e18;
        if (j + 1 < n) {
            pair<ll, ll> right = solve(grid, i, j + 1);
            maxi = max({maxi, grid[i][j] * right.first, grid[i][j] * right.second});
            mini = min({mini, grid[i][j] * right.first, grid[i][j] * right.second});
        }

        if (i + 1 < m) {
            pair<ll, ll> down = solve(grid, i + 1, j);
            maxi = max({maxi, grid[i][j] * down.first, grid[i][j] * down.second});
            mini = min({mini, grid[i][j] * down.first, grid[i][j] * down.second});
        }

        return dp[key] =  {maxi, mini};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        ll result = solve(grid, 0, 0).first%mod ;

        return result< 0 ? -1 : result%mod;
    }
};




//Approach 2 bottom up 
class Solution {
public:
    int m, n;
    using ll = long long;
    int mod = 1e9 + 7 ; 
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
      
        vector<vector<pair<ll, ll>>> dp(m+ 1, vector<pair<ll , ll>>(n + 1, {0, 0}));
         dp[0][0] = {grid[0][0], grid[0][0]};

         for(int i = 1 ; i  < m; i++){
             dp[i][0].first = dp[i - 1][0].first * grid[i][0];
             dp[i][0].second = dp[i - 1][0].second * grid[i][0];
         }

         for(int j = 1; j  < n ;j++ ){
            dp[0][j].first = dp[0][j-1].first * grid[0][j];
            dp[0][j].second = dp[0][j - 1].second * grid[0][j];
         }

         for(int i = 1 ; i  < m; i++){
            for(int j = 1; j  < n; j++){
                ll upMax = dp[i - 1][j].first; 
                ll upMin = dp[i - 1][j].second ; 

                ll leftMax = dp[i][j-1].first; 
                ll leftMin = dp[i][j-1].second; 

                dp[i][j].first = max({upMax * grid[i][j] , upMin * grid[i][j], leftMax * grid[i][j], leftMin * grid[i][j]});
                dp[i][j].second = min({upMax * grid[i][j] , upMin * grid[i][j], leftMax * grid[i][j], leftMin * grid[i][j]});
            }
         }

         return dp[m-1][n-1].first  < 0 ? -1 : dp[m -1][n-1].first%mod;
    }
};