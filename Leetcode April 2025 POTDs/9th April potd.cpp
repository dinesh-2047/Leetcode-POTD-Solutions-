// 3375. Minimum Operations to Make Array Values Equal to K


class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            unordered_set<int>st(begin(nums), end(nums));
             
             int ans = 0 ;  //unique elements 
            for(auto &s : st){
                if(s<k) return -1;
                if(s>k) ans++;
            }
            return ans; 
        }
    };