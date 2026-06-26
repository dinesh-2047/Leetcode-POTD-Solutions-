// 3739. Count Subarrays With Majority Element II


class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        long long cumSum = 0 ; 

        unordered_map<int , long long> mp ; 

        mp[0] = 1; 
        long long result = 0 ; 
        long long valid_left = 0 ; 

        for(int i =0 ; i  < n; i++){
            
            if(nums[i] == target) {
                 valid_left += mp[cumSum]; 
                 cumSum++;
            }
            else{
                cumSum--;
                valid_left -= mp[cumSum];
            }
           result += valid_left ;
            mp[cumSum]++;
        }
        return result; 
    }
};