// 2962. Count Subarrays Where Max Element Appears at Least K Times



// Approach 1 using sliding window 

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int n = nums.size();
    
            long long count = 0  ;
    
            int i = 0 ; 
            int j = 0 ; 
            int maxElement = *max_element(begin(nums), end(nums));
            int maxElementCount = 0 ; 
    
            while(j < n ){
                if(nums[j] == maxElement) maxElementCount++;
    
                while(i <= j && maxElementCount == k ){
                    count+= n-j ;
                    if(nums[i] == maxElement) maxElementCount--; 
                    i++;
                }
               
                j++;
            }
            return count; 
        }
    };



    // Approach 2 sliding window 
    class Solution {
        public:
            long long countSubarrays(vector<int>& nums, int k) {
                int n = nums.size();
                long long count = 0 ; 
        
                int maxElement = *max_element(begin(nums), end(nums));
                  vector<int> indices;
                for(int i = 0 ; i < n ; i++){
                    if(nums[i] == maxElement) indices.push_back(i);
        
                    if(indices.size() >= k ){
                        int last_i = indices[indices.size()-  k];
                        count += last_i  + 1;
                    }
                }
                return count ; 
            }
        };