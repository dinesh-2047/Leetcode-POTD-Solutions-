// 1018. Binary Prefix Divisible By 5

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {

        int n = nums.size();
        vector<bool> result(n, false);

      
        int num = 0;
        for (int i = 0; i < n; i++) {
            num = (num * 2 + nums[i])%5;
            if (num == 0) {
                result[i] = true;
            }
           
        }
        return result;
    }
};