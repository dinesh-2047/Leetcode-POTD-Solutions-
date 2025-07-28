// 2044. Count Number of Maximum Bitwise-OR Subsets



// Approach 1 using map and backtracking

class Solution {
public:
int n ; 
unordered_map<int, int>mp ; 
int solve(int i , int currXor,  vector<int> &nums){
    if(i>=n){
      mp[currXor]++;
      return currXor; 
    }

    int take =solve(i + 1, currXor | nums[i],  nums);
    int not_take = solve(i + 1,currXor,  nums);
  
  return max(take, not_take);
}
    int countMaxOrSubsets(vector<int>& nums) {
         n = nums.size();

        int maxXor =   solve(0,0,  nums);
       
        return  mp[maxXor];
    }
};











//Approach 2 using without map 
class Solution {
public:
    int n;
    int solve(int i, int currXor, int& maxXor, vector<int>& nums) {
        if (i >= n) {
            if (currXor == maxXor) {
                return 1;
            } else
                return 0;
        }

        int take = solve(i + 1, currXor | nums[i], maxXor, nums);
        int not_take = solve(i + 1, currXor, maxXor, nums);

        return take + not_take;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();

        int maxXor = 0;
        for (auto& num : nums) {
            maxXor |= num;
        }

        return solve(0, 0, maxXor, nums);
    }
};