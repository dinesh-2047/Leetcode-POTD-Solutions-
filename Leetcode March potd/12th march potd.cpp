// 2529. Maximum Count of Positive Integer and Negative Integer


// Approach 1 brute force 
class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int neg = 0 ; 
            int pos = 0 ; 
            int n  = nums.size();
    
            for(int i = 0 ;i<n; i++){
                if(nums[i] >0) pos++;
                if(nums[i] < 0 ) neg++;
            }
            return max(pos, neg);
        }
    };


    // Approach 2 using C++ stl count_if()

    class Solution {
        public:
        
            int maximumCount(vector<int>& nums) {
                auto lambdaP = [] (int num ){
            return num>0;
          };
          auto lambdaN = [](int num){
            return num<0;
          };
               int pos =  count_if(begin(nums) , end(nums), lambdaP);
               int neg =  count_if(begin(nums), end(nums) , lambdaN);
        
               return max(pos, neg);
                
            }
        };


        // Approach 3 - > using binary search 

        class Solution {
            public:
                int maximumCount(vector<int>& nums) {
                    int n = nums.size();
            
                    int firstP = lower_bound(begin(nums), end(nums), 1) - begin(nums);
                    int firstZero = lower_bound(begin(nums), end(nums), 0)  - begin(nums);
            
                    int positive = n - firstP;
                    
                    return max(firstZero, positive);
                }
            };