// 868. Binary Gap

class Solution {
public:
    int binaryGap(int n) {
        string binary = bitset<32>(n).to_string();

        int prev = -1; 
        int result = 0;
        for(int i = 0 ; i< 32; i++){
            if(binary[i] == '1'){
                if(prev == -1){
                    prev = i ; 
                    continue; 
                }
                else{
                   result = max(result, i - prev);
                   prev = i; 
                }
            }
           
        }
        return result;
    }
};