// 693. Binary Number with Alternating Bits

class Solution {
public:
    bool hasAlternatingBits(int n) {
        string binary = bitset<32>(n).to_string();
        int i = 0 ; 
        while(binary[i] == '0') i++;
             
        while(i < 32){ 
          if(binary[i] == binary[i -1]){
             return false; 
          }
          i++;
        }
        return true; 


    }
};