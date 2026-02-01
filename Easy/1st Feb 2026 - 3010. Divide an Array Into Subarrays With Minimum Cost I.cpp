// 3010. Divide an Array Into Subarrays With Minimum Cost I


class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int mini = nums[1];
        int result = INT_MAX; 

        for(int i = 1; i < n-1; i++){
            mini = min(mini, nums[i]);
            result = min(result ,  nums[0] + mini + nums[i + 1]);
        }
        return result; 
    }
};