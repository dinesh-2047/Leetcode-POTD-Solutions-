// 3020. Find the Maximum Number of Elements in Subset 


class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int , int> mp ; 
        for(auto &num : nums){
            mp[num]++;
        }
        
        int result = 0 ;
        if(mp[1]%2 == 0) result = mp[1] - 1; 
        else result = mp[1] ;
        mp.erase(1);

        for(auto &num : nums){
            long long x = 1LL * num; 
            int len = 0;
            while(x <= INT_MAX && mp.count(x) && mp[x] > 1 ){
                len += 2; 
                x *= x;
            }

            if(mp.count(x)){
                len++;
            }
            else len--;
            result = max(result, len);

        }
        return result; 
    } 
};