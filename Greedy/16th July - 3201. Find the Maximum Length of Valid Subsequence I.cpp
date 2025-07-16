// 3201. Find the Maximum Length of Valid Subsequence I


// Approach 1 dp + memo  bekkaar approach 
class Solution {
public:
int n ; 

int solve(vector<int> &nums, int i , int &prev, vector<vector<int>> &dp){
    if(i>=n) return 0 ;

    if(dp[i][prev +1]!=-1) return dp[i][prev+1]; 

    int curr = nums[i]%2;
    int not_take = solve(nums, i+1 , prev, dp);
   
    int take = 0 ;

    if(curr != prev){
        take = 1 + solve(nums, i + 1, curr, dp);
    }

    return dp[i][prev+1] = max(take, not_take);
}
        
    int maximumLength(vector<int>& nums) {
        n = nums.size();
        int evens = 0 ; 
        int odds =  0  ; 

        for(auto &x : nums){
            if(x%2==1) odds++;
            else evens++;
        }


      int prev = -1;
      vector<vector<int>>dp;
      dp.resize(n+1, vector<int>(3, -1));

      int evenAndOdd = solve(nums, 0, prev, dp);
      return max({odds, evens , evenAndOdd});

    }
};






//Approach 2 greedy 
class Solution {
public:

    int maximumLength(vector<int>& nums) {
      int  n = nums.size();

       int oddCount = 0 ; 
       int evenCount = 0 ; 

       for(int &x : nums){
        if(x%2==0) evenCount++;
        else oddCount++;
       }

       int evenPlusOdd = 0 ; 
       int prev = -1 ; 

       for(int i = 0 ; i <n; i++){
           int curr = nums[i]%2;
           if(curr!=prev){
              evenPlusOdd++;
              prev = curr; 
           }
       }

     return max({evenCount, oddCount, evenPlusOdd});

    }
};