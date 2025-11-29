// 3512. Minimum Operations to Make Array Sum Divisible by K


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
      return  accumulate(begin(nums), end(nums), 0)%k;
    
    }
};