// 2654. Minimum Number of Operations to Make All Array Elements Equal to 1


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int minOp = INT_MAX ; 
         int count1 = 0 ; 
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] == 1) count1++;
        }
        if(count1 > 0)
        return n - count1; 

        for(int i = 0 ; i  < n - 1; i++){
           int op = 0 ; 
           int GCD = nums[i];
           for(int j = i + 1 ; j < n; j++){
              GCD = gcd(GCD, nums[j]);
              op++;

              if(GCD == 1) minOp = min(op , minOp);

           }
        }
       if(minOp == INT_MAX) return -1; 

       return minOp + (n-1);
    }
};