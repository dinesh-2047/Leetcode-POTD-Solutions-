// 3928. Minimum Cost to Buy Apples II

class Solution {
public:
int n ; 
vector<int> dp; 
int solve(vector<int> &nums, int target, int i ){
    if(i == n - 1) return 0;
    if(i >= n ) return INT_MIN; 
      if(dp[i] !=-1) return dp[i];
    int result = INT_MIN; 
    for(int j = i + 1; j  < n; j++){
        if(nums[j] - nums[i] <= target && nums[j] - nums[i] >= -target){
            result = max(result, 1 + solve(nums, target, j));
        }
    }
    return dp[i] = result; 
}
    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        dp.assign(n + 1, -1);
        int result =  solve(nums, target, 0);
        return result <  0? -1 : result; 
    }
};