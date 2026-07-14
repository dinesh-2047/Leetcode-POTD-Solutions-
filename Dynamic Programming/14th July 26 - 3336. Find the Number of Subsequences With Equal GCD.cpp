// 3336. Find the Number of Subsequences With Equal GCD



class Solution {
public:
int n ; 
int mod = 1e9+ 7; 
int dp[201][201][201];
int solve(vector<int> &nums, int i , int GCD1, int GCD2){
    if(i >= n  ){
        return GCD1 == GCD2 && GCD1 != 0 ; 
    }
   
   if(dp[i][GCD1][GCD2]!=-1) return dp[i][GCD1][GCD2];
 
    int not_take = solve(nums, i + 1, GCD1, GCD2);
    int take1 = solve(nums, i + 1 , gcd(GCD1, nums[i]), GCD2);
    int take2 = solve(nums , i + 1, GCD1, gcd(GCD2, nums[i]));
    return dp[i][GCD1][GCD2] = ((not_take + take1)%mod + take2 )%mod; 
}
    int subsequencePairCount(vector<int>& nums) {
        n  = nums.size();
        memset(dp, -1, sizeof(dp));
        return  solve(nums ,0,0,0);
    }
};