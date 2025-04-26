// 2444. Count Subarrays With Fixed Bounds

// sliding window 

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            long long count = 0 ; 
            int n = nums.size();
    
            int minKindex = -1;
            int maxKindex = -1 ; 
            int badIndex = -1 ; 
    
            for(int i = 0 ; i<n; i++){
                if(nums[i] < minK || nums[i] > maxK){
                    badIndex = i; 
                }
    
                if(nums[i] == minK) minKindex = i; 
                if(nums[i] == maxK) maxKindex = i ;
    
                long long smallerIndex = min(minKindex , maxKindex);
                long long  valid = smallerIndex - badIndex;
                if(valid <= 0) count += 0;
                else count += valid ;  
            }
    
            return count; 
        }
    };