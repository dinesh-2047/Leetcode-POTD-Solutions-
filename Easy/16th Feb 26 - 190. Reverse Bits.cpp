// 190. Reverse Bits

class Solution {
public:
    int reverseBits(int n) {
        string binary = bitset<32>(n).to_string();
        reverse(begin(binary), end(binary));
         int result = 0 ; 
        for(int i = 0 ; i  < 32; i++){
           result = result * 2 + (binary[i] - '0');
        }
        return result; 
    }
};