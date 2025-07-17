// 3202. Find the Maximum Length of Valid Subsequence II




// approach 1 : rec + memo (MLE )
class Solution {
public:
    int n;

    int solve(vector<int>& nums, int k, int i, int prev, int prevResult, vector<vector<vector<int>>> &dp) {
        if (i >= n) return 0;

        if(dp[i][prev + 1][prevResult + 1] != -1) return dp[i][prev + 1][prevResult + 1];

        int not_take = solve(nums, k, i + 1, prev, prevResult, dp);
        int take = 0;

        if (prev == -1) {
            take = 1 + solve(nums, k, i + 1, i, prevResult, dp);
        } else {
            int val = (nums[prev] + nums[i]) % k;
            if (prevResult == -1) {
                take = 1 + solve(nums, k, i + 1, i, val, dp);
            } else if (val == prevResult) {
                take = 1 + solve(nums, k, i + 1, i, prevResult, dp);
            }
        }

        return dp[i][prev + 1][prevResult + 1] =  max(take, not_take);
    }

    int maximumLength(vector<int>& nums, int k) {
        n = nums.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(n+1, vector<int>(k+1, -1)));
        return solve(nums, k, 0, -1, -1, dp);
    }
};





// Approach 2 : LIS- >tabulation 
class Solution {
public:
    int n;


    int maximumLength(vector<int>& nums, int k) {
        n = nums.size();
        
        vector<vector<int>>dp(k , vector<int>(n, 1) );
        int result = 0 ; 

        for(int i = 1 ; i < n; i++ ){
            for(int j = 0 ; j < i; j++){
                int modValue = (nums[i] + nums[j])%k;

                dp[modValue][i] = max(dp[modValue][i], dp[modValue][j] + 1);
                result = max(dp[modValue][i], result);
            }
        }
        return result; 
    }
};
