// 3640. Trionic Array II


class Solution {
public:
using ll = long long ; 
int n;
vector<vector<ll>>dp; 
ll solve(vector<int> &nums, int i , int trend){

    if(i >= n ) {
        if(trend == 3) return 0; 
        else return LLONG_MIN/2; 
    }

    if(dp[i][trend] != -1) return dp[i][trend];
     
     ll take = LLONG_MIN/2; 
     ll not_take = LLONG_MIN/2;

     if(trend == 0 ){
        not_take = solve(nums , i + 1, 0);
     }

        if(trend == 3){
        take = nums[i];
     }

     if(i + 1 < n ){
         
     ll curr = nums[i];
     ll next = nums[i  + 1];

      if(trend == 0 && next > curr){
        take = max(take , curr +solve(nums, i + 1, 1));
      }

      else if(trend == 1 ){
        if(next > curr){
            take = max(take, curr + solve(nums, i + 1, 1));
        }
        else if(next < curr){
            take = max(take , curr + solve(nums, i + 1 ,2));
        }
      }
      else if(trend == 2 ){
        if(next < curr){
            take = max(take, curr + solve(nums, i + 1, 2));
        }
        else if(next > curr){
            take = max(take , curr + solve(nums, i + 1 ,3));
        }
      }

      else if(trend == 3 && next > curr){
        take = max(take, curr + solve(nums, i + 1, 3));
      }


     }

  

     return dp[i][trend] =  max(take, not_take);
}
    long long maxSumTrionic(vector<int>& nums) {
         n = nums.size();
          dp.assign(n + 1, vector<ll>(4, -1));
        return solve(nums, 0, 0);
    }
};