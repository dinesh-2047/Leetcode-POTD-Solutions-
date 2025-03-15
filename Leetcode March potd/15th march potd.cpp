// 2560. House Robber IV]


// using binary search on answer
class Solution {
    public:
    bool isPossible(vector<int> &nums, int k , int mid ){
        int n = nums.size();
           int house = 0; 
    
           for(int i = 0 ; i<n; i++){
               if(nums[i] <= mid){
                house++;
                i++;
               }
                 if(house >= k) return true; 
           }
          
           return false; 
    }
    
    
        int minCapability(vector<int>& nums, int k) {
              int n = nums.size();
    
              int l = *min_element(begin(nums) , end(nums)); 
              int r = *max_element(begin(nums) , end(nums)); 
    
    
              int result = r ; 
              while(l<=r){
                int mid = l + (r-l)/2; // mid -> capability
                if(isPossible(nums, k , mid)){
                    result  =  mid ; 
                    r = mid - 1;
                }
                else l = mid  + 1;
              }
              return result;
        }
    };