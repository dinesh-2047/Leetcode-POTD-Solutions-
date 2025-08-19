// 2348. Number of Zero-Filled Subarrays


// Approach 1 

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();

        long long cnt = 0 ; 
        long long result = 0 ; 

        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0 ) cnt++;
            else{
                cnt = 0 ; 
            }
             result += cnt ; 
        }

        
        return result; 
    }
};




//Approach 2
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();

        long long result = 0;

        int i = 0;
        int j = 0;

        while (j < n) {
            if (nums[j] == 0) {
                i = j;

                while (j < n && nums[j] == 0) {
                    result += (j - i + 1);
                    j++;
                }
            }

            j++;
        }
        return result;
    }
};