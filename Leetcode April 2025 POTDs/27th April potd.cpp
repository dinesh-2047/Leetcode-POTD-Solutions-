// 3392. Count Subarrays of Length Three With a Condition


class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int n = nums.size();
            int count = 0 ; 
    
            for(int i = 0 ; i<n-2; i++){
                int first = nums[i];
                int second = nums[i+1];
                int third = nums[i + 2];
    
                if((first + third)*2==  second) count++;
               
            }
            return count ; 
        }
    };