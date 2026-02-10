// 3719. Longest Balanced Subarray I

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();

        int result = 0 ; 

        for(int i = 0 ; i  < n ; i++){
             unordered_set<int>evens, odds;  
            for(int j = i ; j  < n; j++){
                if(nums[j]%2 == 0 ) evens.insert(nums[j]);
                else odds.insert(nums[j]);

                if(evens.size() == odds.size()) result = max(result, j- i + 1);
            }
        }
        return result; 
    }
};