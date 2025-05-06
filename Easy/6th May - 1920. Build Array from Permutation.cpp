// 1920. Build Array from Permutation

// Approach 1 using extra array 
class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            int n = nums.size();
             vector<int>ans(n);
    
             for(int i = 0 ; i<n; i++){
                ans[i] = nums[nums[i]];
             }
             return ans; 
        }
    };



    // Approach 2 in place 

    class Solution {
        public:
            vector<int> buildArray(vector<int>& nums) {
                int n = nums.size();
                
        
                 for(int i = 0 ; i<n; i++){
                    nums[i] = nums[i]  +(n * (nums[nums[i]]%n));
        
                 }
        
                 for(int i = 0 ; i<n; i++){
                    nums[i] = nums[i]/n;
                 }
                 return nums; 
            }
        };