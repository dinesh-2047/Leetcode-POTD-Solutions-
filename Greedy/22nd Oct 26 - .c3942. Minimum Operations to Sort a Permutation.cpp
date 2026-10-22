// 3942. Minimum Operations to Sort a Permutation

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int result = 1e9 ; 
        
        // if array is of ascending nature 
        bool valid1 = true; 
        for(int i = 1; i < n; i++){
            if(nums[i] != (nums[i-1] + 1)%n){
                valid1 = false; 
                break; 
            }
        }

        if(valid1){
            if(nums[0] == 0 ) return 0 ; 
            result = min({result, n - nums[0], nums.back() + 3});
        } 
        
        // if array is of descending nature 
        bool valid2 = true; 
        for(int i = 1; i  <  n  ; i++){
            if(nums[i-1] != (nums[i] + 1)%n){
                valid2 = false; 
                break; 
            }
        }

        if(valid2){
            result = min({result, n - nums.back() + 1, (nums[0] + 1)%n + 1});
        }
        return result == 1e9 ? -1 : result; 
        
    }
};