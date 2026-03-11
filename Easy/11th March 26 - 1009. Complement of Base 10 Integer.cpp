// 1009. Complement of Base 10 Integer

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0 ) return 1; 
        int temp = n ; 
        int bits = floor(log2(n)) + 1; 
        int k = (1 << bits) - 1; 
        return n^k; 


    }
};