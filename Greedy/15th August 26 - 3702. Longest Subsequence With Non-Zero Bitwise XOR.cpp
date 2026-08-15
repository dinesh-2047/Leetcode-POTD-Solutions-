// 3702. Longest Subsequence With Non-Zero Bitwise XOR

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int xorr = 0 ;
        int count0 = 0 ; 
        for(int i = 0 ; i < n; i++){
            xorr ^= nums[i];
            if(nums[i] == 0 )
                count0++;
        }  
        if(count0 == n ) return 0;
        if(xorr == 0 ) return n - 1; 
        return n; 
    }
};