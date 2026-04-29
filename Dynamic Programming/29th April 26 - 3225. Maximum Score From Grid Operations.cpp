// 3225. Maximum Score From Grid Operations


class Solution {
public:
    using ll = long long;
    int n;
    vector<vector<ll>> pref;
    vector<vector<vector<ll>>> dp; 
    ll solve(vector<vector<int>>& grid,  int col, int prevTaken , int prevH) {
       if(col == n ) return 0 ; 

       ll result = 0 ; 
       if(dp[col][prevTaken][prevH]!=-1) return dp[col][prevTaken][prevH];

       for(int height = 0 ; height <= n; height++){
        ll prevColScore = 0; 
        ll currColScore = 0 ; 

        if(!prevTaken && height > prevH){
            prevColScore  += pref[height][col] - pref[prevH][col];
        }

        if(prevH > height){
           currColScore  += pref[prevH][col + 1] - pref[height][col + 1];
        }

        ll currColScoreTaken = currColScore + prevColScore + solve(grid, col + 1, true, height);
        ll currColScoreNotTaken  = prevColScore + solve(grid, col + 1, false, height);

        result = max({result, currColScoreTaken , currColScoreNotTaken});
       }
       return dp[col][prevTaken][prevH] =  result; 
    }
    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();
        pref.assign(n + 1, vector<ll>(n + 1));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i][j] = pref[i - 1][j] + grid[i - 1][j - 1];
            }
        }
        dp.assign(n+1, vector<vector<ll>> ( 2, vector<ll> (n + 1, -1)));
       return solve(grid,0,0,0);
    }
};