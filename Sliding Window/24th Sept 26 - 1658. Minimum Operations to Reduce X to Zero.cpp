// 1658. Minimum Operations to Reduce X to Zero


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int sum = accumulate(begin(nums), end(nums), 0);

        if(sum < x) return -1; 
        int mid_sum = sum - x; 
        int i = 0 ; 
        int j = 0 ; 
        sum = 0 ; 

        int result = -1e9 ; 

        while(j < n ){
            sum += nums[j];
            while(i <= j && sum > mid_sum){
                sum -= nums[i];
                i++;
            }
            if(sum == mid_sum){
                result = max(result, j - i + 1);
            }
            j++;
        }
        return result == -1e9 ? -1 : n - result; 
    }
};