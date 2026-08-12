// 2958. Length of Longest Subarray With at Most K Frequency

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0 ; 
        int j = 0 ; 

        int result = 0 ; 

        unordered_map<int , int> mp ; 

        while(j < n ){
            mp[nums[j]]++;
            while(i < j && mp[nums[j]] > k ){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0 ){
                    mp.erase(nums[i]);
                }
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }
        return result; 
    }
};