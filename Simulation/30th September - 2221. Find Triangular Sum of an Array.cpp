// 2221. Find Triangular Sum of an Array


// Approach 1

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();

        vector<int>vec = nums; 

        for(int step = 0 ; step < n; step++){
            for(int i = 0 ; i  < vec.size()-1; i++){
              int sum = (vec[i] + vec[i + 1])%10;
              vec[i] = sum ;
            }
            vec.pop_back();
        }
        return vec[0];
    }
};






//approach  2
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for(int step = 0 ; step < n; step++){
            for(int i = 0 ; i  < nums.size()-1; i++){
              int sum = (nums[i] + nums[i + 1])%10;
              nums[i] = sum ;
            }
            nums.pop_back();
        }
        return nums[0];
    }
};