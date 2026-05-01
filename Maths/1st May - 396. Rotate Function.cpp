// 396. Rotate Function

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

      int sum = accumulate(begin(nums), end(nums), 0);
      int fk = 0 ; 
      for(int i = 0 ; i< n; i++){
         fk += (i * nums[i]);
      }
     
      int result = fk; 
      for(int i = 0 ; i < n-1; i++){
         fk = fk + sum - (n * nums[n - i-1]);
         result = max(result, fk);
      }
      return result; 

    }
};