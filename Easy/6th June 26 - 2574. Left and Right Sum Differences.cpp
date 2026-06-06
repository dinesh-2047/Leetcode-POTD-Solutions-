// 2574. Left and Right Sum Differences

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n , 0);
        int total = accumulate(begin(nums), end(nums), 0);

        int leftSum = 0 ; 
        for(int i = 0 ; i  < n; i++){
            int rightSum = total - leftSum - nums[i]; 
            result[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }
        return result; 
    }
};