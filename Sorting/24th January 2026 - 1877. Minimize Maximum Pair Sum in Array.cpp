// 1877. Minimize Maximum Pair Sum in Array

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
       sort(begin(nums), end(nums));

       int i = 0 ; 
       int j = n- 1; 
       int result = 0 ; 
       while( i< j ){
          result = max(result , nums[i] + nums[j]);
          i++;
          j--;
       }
       return result; 
    }
};