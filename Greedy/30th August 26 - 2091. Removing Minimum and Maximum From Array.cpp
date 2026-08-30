// 2091. Removing Minimum and Maximum From Array

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int result = n; 
        int mxi = max_element(begin(nums), end(nums)) - begin(nums);
        int mni = min_element(begin(nums), end(nums)) - begin(nums);
        //left
        result = min(result, max(mxi, mni)+1);

        //right
        result = min(result, n-min(mxi, mni));

        // one left and one right

        result = min(result, n - max(mxi, mni) + min(mxi, mni)+1);

        return result; 

    }
};