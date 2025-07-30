// 2419. Longest Subarray With Maximum Bitwise AND


// approach 1
#define all(x) begin(x), end(x)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int andd = *max_element(all(nums));
        
         int result = 1 ; 
         int count = 1;
         for(int i = 0 ;i < n-1; i++){
            if(nums[i]==nums[i+1] && nums[i] == andd){
                count++;
                  result = max(result , count);
            }
            else {
              
                count = 1; 
            }
         }


        return result; 
    }
};



// Approach 2 similar as above 
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxVal =  0 ; 
        int result = 0 ; 
        int currCount = 0 ; 
        for(int i = 0 ; i < n; i++){
               if(maxVal < nums[i]){
                maxVal = nums[i];
                currCount = 0 ; 
                result = 0 ; 
                 
               }
               if(maxVal == nums[i]){
                  currCount++;
               }
               else {
                  currCount=0;
               }
               result = max(result , currCount);
        }
        return result; 
    }
};