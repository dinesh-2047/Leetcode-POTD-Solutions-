// 3432. Count Partitions with Even Sum Difference


class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);

        if(sum%2 == 1) return 0 ; 
        else return n-1; 
    }
};