// 2784. Check if Array is Good

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();

        vector<int> freq(200);
        int count = 0 ; 
        
        for(auto &x : nums){
            if(x > n -1) return false; 
            freq[x]++;
            count++;
            if(freq[x] == 2 && x != n-1) return false; 
            if(freq[x] > 2) return false; 
        }
        if(count == n) return true; 
        return false; 
        
    }
};