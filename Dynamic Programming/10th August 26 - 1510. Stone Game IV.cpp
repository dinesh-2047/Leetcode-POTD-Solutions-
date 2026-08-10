// 1510. Stone Game IV

class Solution {
public:
vector<int> dp; 
    bool solve(int n) {
        if (n == 0) {
           return false;
        }
        
        if(dp[n]!=-1) return dp[n];
            for (int x = 1; x * x <= n; x++) {
                if(!solve(n - x * x)) return dp[n] =  true; 
            }
          return dp[n] =  false;
    }
    bool winnerSquareGame(int n) { 
        dp.resize( n + 1, -1);
        return solve(n); 
        }
};