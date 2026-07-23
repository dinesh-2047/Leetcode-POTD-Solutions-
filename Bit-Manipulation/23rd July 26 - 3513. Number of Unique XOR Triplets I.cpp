// 3513. Number of Unique XOR Triplets I

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n; 
        int msb = 32 - __builtin_clz(n);
        return 1<< msb; 
    }
};