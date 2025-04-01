// 2140. Solving Questions With Brainpower

// Rec + memo 
class Solution {
    public:
    int n ; 
    long long solve(vector<vector<int>> &questions , int i, vector<long long > &dp ){
        if(i>=n) return 0;
    
        if(dp[i]!=-1) return dp[i]; 
    
        long long  take = questions[i][0]  + solve(questions , i + questions[i][1]+1,dp);
        long long not_take = solve(questions , i + 1,dp);
        return dp[i] =  max(take , not_take);
    }
        long long mostPoints(vector<vector<int>>& questions) {
             n = questions.size();
             vector<long long >dp(n+1, -1);
            return solve(questions , 0,dp);
        }
    };


    // Tabulation 
    class Solution {
        public:
        int n ; 
        
            long long mostPoints(vector<vector<int>>& questions) {
                 n = questions.size();
                 vector<long long >dp(n+1, 0);
                
        
        
                for(int i= n-1; i>=0; i--){
                    long long take = questions[i][0]  ; 
                    if(i+questions[i][1] + 1 <n )
                    take += dp[i + questions[i][1]+1];
                    long long not_take = dp[i+1];
                     dp[i] =  max(take , not_take);
                }
                return dp[0];
            }
        };