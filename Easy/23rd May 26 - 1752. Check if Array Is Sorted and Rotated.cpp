// 1752. Check if Array Is Sorted and Rotated

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size() ; 

        int peak = 0 ; 

        for(int i = 0 ; i < n; i++){
            if(nums[i] >  nums[(i + 1)%n]) peak++;
        }
        if(peak > 1) return false; 
        return true; 
    }
};