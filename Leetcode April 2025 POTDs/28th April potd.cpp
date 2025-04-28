// 2302. Count Subarrays With Score Less Than K 


class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            long long count = 0 ; 
            int n = nums.size();
    
            int i = 0 ; 
            int j  = 0 ;
            long long sum = 0 ; 
            
    
    
            while( j < n ){
               sum+= nums[j];
    
               while(i <= j && sum * (j - i  +1) >= k ){
                sum -= nums[i];
                i++;
               }
               count += (j - i  +1);
               j++;
            }
            return count ; 
        }
    };