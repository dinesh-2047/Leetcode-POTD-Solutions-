// 3727. Maximum Alternating Sum of Square

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n; i++) nums[i] = abs(nums[i]);
        sort(begin(nums), end(nums));

        int i = 0 ; 
        int j = n -1 ; 

        long long result = 0 ; 

        while(i < j ){
            result += (1LL  * nums[j] * nums[j]);
            result -= (1LL  * nums[i] * nums[i]);
            i++;
            j--;
        }
        if(n%2 == 1) result += (nums[n/2] * nums[n/2]);

        return result; 
    }
};