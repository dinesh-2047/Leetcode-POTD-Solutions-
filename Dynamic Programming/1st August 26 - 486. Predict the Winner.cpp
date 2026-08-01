// 486. Predict the Winner


class Solution {
public:
int n ; 
using ll = long long ; 
map<tuple<int , int , ll, int>, bool> dp; 
bool solve(vector<int> &nums, int i , int j, ll score,  int turn ){
    if(i > j  ) {
          return score >= 0; 
    }

    tuple<int , int , ll, int> key = {i, j , score, turn};
    if(dp.count(key)) return dp[key];
    
    bool result = false; 
    if(turn==0){
        //player 1 turn 
        result = result || solve(nums, i + 1, j , score + nums[i], 1);
        result = result || solve(nums, i , j  - 1, score + nums[j], 1);
    }
    else {
        //player 2 turn 
         result = solve(nums, i  + 1, j , score - nums[i], 0) && solve(nums, i , j - 1, score - nums[j], 0);
    }
    return dp[key] =  result; 
}
    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        return solve(nums , 0, n-1, 0,0);
    }
};