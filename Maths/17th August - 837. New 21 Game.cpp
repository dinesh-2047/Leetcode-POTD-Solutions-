// 837. New 21 Game


class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double>dp(n+1, 0.0);
        dp[0] = 1; 

        double currProbSum = 1.0; 
        if(k == 0 ) currProbSum = 0.0 ; 

        for(int i = 1 ; i <= n ; i++){
            dp[i] = currProbSum/maxPts; 
            if(i  < k)
            currProbSum += dp[i];
            
            if(i - maxPts >= 0 && i - maxPts  < k )
            currProbSum -= dp[i-maxPts];
        }

        double result = 0.0; 

        for(int i = k ; i  <= n ;i++){
            result += dp[i];
        }
        return result; 
    }
};