// 3397. Maximum Number of Distinct Elements After Operations


// Approach 1
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));
         int result = 0 ; 
         int prev = -1e9 ; 
        for(int i = 0 ; i < n; i++){
              if((nums[i] + k) <= prev ){
                   continue; 
              }
              prev = max(prev + 1, nums[i] - k );
              result++;
        }
        return result; 
    }
};


//approach 2
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int result = 0 ; 
        int prev = -1e9; 

        for(int i = 0 ; i < n ;i++){
            int value = nums[i] - k ; 
            if(prev < value){
                prev = value; 
                 result++;
            }
            else if(prev < (nums[i] + k) ){
                prev = prev + 1; 
                result++;
            }
        }
        return result; 
    }
};