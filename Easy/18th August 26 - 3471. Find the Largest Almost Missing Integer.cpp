// 3471. Find the Largest Almost Missing Integer


class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>  mp(51, 0) ; 
        for(auto &x : nums) mp[x]++;

        if( k== 1){
            int result = -1;

            for(int i = 0; i  < n; i++){
                if(mp[nums[i]] == 1){
                      result = max(result, nums[i]);
                }
            }
            return result; 
        }

        if(k == n ){
            return *max_element(begin(nums), end(nums));
        }


        if(mp[nums[0]] > 1 && mp[nums[n-1]] > 1) return -1; 

        if(mp[nums[0]] == 1 && mp[nums[n - 1]] == 1) return max(nums[0], nums[n- 1]);

        if(mp[nums[0]] == 1) return nums[0];
        if(mp[nums[n-1]]== 1) return nums[n-1];
        return -1; 
    }
};