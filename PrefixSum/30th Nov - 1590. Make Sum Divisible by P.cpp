// 1590. Make Sum Divisible by P


class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        unordered_map<int , int>mp ; 
        mp[0] = -1; 

        int sum = 0 ;
        for(auto &num : nums) sum = (sum + num)%p; 

        int target = sum%p; 

        if(target == 0 ) return 0; 

        int pref = 0 ; 
        int result = n;

        for(int i = 0 ; i  < n; i++){
            pref = (pref + nums[i])%p;
            int req = (pref - target + p)%p; 
            if(mp.count(req)){
                result = min(result , i - mp[req]);
            }
            mp[pref] = i; 
        }
        return (result == n) ? -1 : result; 
    }
};