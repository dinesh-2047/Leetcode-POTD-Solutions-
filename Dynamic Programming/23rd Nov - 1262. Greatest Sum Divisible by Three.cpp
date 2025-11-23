// 1262. Greatest Sum Divisible by Three


// Approach 1 
class Solution {
public:
int n ; 
vector<vector<int>>dp ; 
int solve(vector<int> &nums , int i, int rem){
    if(i >=  n ){
        if(rem == 0 ){
            return 0 ; 
        }
        else return -1e5; 
    }
    if(dp[i][rem]!=-1) return dp[i][rem];

    int take = nums[i] + solve(nums, i + 1, (rem + nums[i])%3);
    int not_take = solve(nums , i + 1, rem);
 
    return dp[i][rem] = max(take , not_take);

  
}
    int maxSumDivThree(vector<int>& nums) {
        n = nums.size();
        dp.assign(n + 1, vector<int>(3, -1));
        return solve(nums , 0, 0);
    }
};




//Approach 2 
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>dp(n  + 1, vector<int>(3, INT_MIN));

        dp[n][0] = 0; 
        
        for(int i = n-1; i >= 0 ;i--){
            for(int rem = 0 ; rem < 3; rem++){
                int new_rem = (nums[i] + rem)%3; 

                int take = (dp[i + 1][new_rem] != INT_MIN) ? nums[i] + dp[i + 1][new_rem] : INT_MIN;
                int not_take = dp[i + 1][rem];

                dp[i][rem]= max(take, not_take);
            }
        }
        return dp[0][0];
    }
};




//Approach3 
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();

        vector<int>rem1, rem2 ; 

        for(auto &x : nums){
            if(x%3 == 1){
                rem1.push_back(x);
            }
            else if(x%3 == 2){
                rem2.push_back(x);
            }
        }

        sort(begin(rem1), end(rem1));
        sort(begin(rem2), end(rem2));

        int sum = accumulate(begin(nums), end(nums), 0);
        int rem = sum%3 ; 
        if(rem == 0 ) return sum ;

        if(rem == 1){
            int r1 = (rem1.size() > 0 ) ? rem1[0] : INT_MAX; 
            int r2 = (rem2.size() > 1) ? rem2[0] + rem2[1] : INT_MAX;
            return sum - min(r1, r2);
        }
        if(rem == 2){
            int r1 = (rem2.size() > 0 ) ? rem2[0] : INT_MAX;
            int r2 = (rem1.size() > 1) ? rem1[0] + rem1[1] : INT_MAX ;
            return sum - min(r1, r2);
        }
        return sum ;
    }
};