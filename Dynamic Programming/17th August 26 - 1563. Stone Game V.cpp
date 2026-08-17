// 1563. Stone Game V

class Solution {
public:
int n ; 
vector<int> pref; 
int dp[501][501];
int solve(vector<int> &stoneValue, int i , int j){
    if(i >= j ) {
        return 0 ; 
    }

    if(dp[i][j]!=-1) return dp[i][j];
     int result = 0 ; 
    for(int k = i; k < j ; k++){
        int l = pref[k] - (i > 0 ? pref[i - 1] : 0 );
        int r = pref[j] - pref[k];

        if( l < r){
              result = max(result, l + solve(stoneValue, i , k));
        }
        else if(r < l ){
             result = max(result, r  + solve(stoneValue, k + 1, j));
        }
        else {
             result = max(result, l + solve(stoneValue, i , k));
             result = max(result, r + solve(stoneValue, k + 1, j));
        }
    }
    return dp[i][j] =  result;
}
    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();
         pref.resize(n);
         pref[0] = stoneValue[0];
        
         for(int i = 1; i  < n; i++){
            pref[i] = pref[i - 1] + stoneValue[i];
         }

          memset(dp, -1, sizeof(dp));
        return solve(stoneValue, 0, n - 1 );
    }
};

