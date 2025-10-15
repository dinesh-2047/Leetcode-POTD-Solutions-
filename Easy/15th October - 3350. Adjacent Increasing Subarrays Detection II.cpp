// 3350. Adjacent Increasing Subarrays Detection II

// Approach 1 

class Solution {
public:
bool isPossible(vector<int> &nums , int k){
    int n = nums.size();
    int currLen = 1; 
    int prevLen = 0;

    for(int i = 1; i  < n; i++){
        if(nums[i] > nums[i - 1]){
                currLen++;
            }
            else{
                prevLen = currLen ; 
                currLen = 1; 

            }
        if(currLen >= 2* k  || min(currLen, prevLen) >= k) return true; 
    }
    return false; 
}

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

         int result = 0 ; 
         int l = 0 ;
         int r = n/2; 

         while(l <= r){
            int mid = l + (r-l)/2; 
            if(isPossible(nums , mid)){
                result = mid ; 
                l = mid + 1;
            }
            else r = mid -1 ; 
         }
         return result ;
    }
};


//Approach 2 
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int currLen = 1 ; 
        int prevLen = 0 ; 
        int result = 0 ; 

        for(int i = 1; i  < n; i++){
            if(nums[i] > nums[i - 1]){
                currLen++;
            }
            else {
                prevLen = currLen ; 
                currLen = 1 ; 
            }
         
           result = max(result , currLen / 2);
           result = max(result , min(currLen , prevLen));
                
            
        }
        return result; 
    }
};