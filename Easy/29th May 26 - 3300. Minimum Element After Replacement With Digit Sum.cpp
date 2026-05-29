// 3300. Minimum Element After Replacement With Digit Sum


class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int result = 1e9; 
        for(int i = 0 ; i < n; i++){
             int sum = 0 ; 
             int num = nums[i];

             while(num){
                sum += (num%10);
                num/=10; 
             }
             result = min(result, sum);
        }
        return result; 
    }
};