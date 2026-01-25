// 1984. Minimum Difference Between Highest and Lowest of K Scores

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));
         
         int result = INT_MAX; 
        for(int i = 0; i + k  <= n; i++){
            result = min(result , nums[i+k-1] - nums[i]);
        }
        return result; 

    }
};