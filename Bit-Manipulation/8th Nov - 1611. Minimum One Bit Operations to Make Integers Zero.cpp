// 1611. Minimum One Bit Operations to Make Integers Zero//



// Approach 1 
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if( n == 0 ) return 0; 
        unordered_map<int , long long>mp ; 
        mp[0] = 1;
        int bit = 1 ; 
        while(bit <= 31){
            mp[bit] = mp[bit - 1]  + pow(2, bit);
            bit++;
        }

        string binary = "";
        bitset<32>b(n); 
        for(int i = 0 ; i  < 32 ; i++){
            if(b[i]){
                binary.push_back('1');
            }
            else binary.push_back('0');
        }

       
        char sign = '+';
        int result = 0 ; 
        for(int i = 0 ; i  < 32; i++){
            if(binary[i] == '1'){
                if(sign == '+'){
                    result += mp[i];
                    sign = '-';
                }
                else {
                    result -= mp[i];
                    sign = '+';
                }
            }
        }

        return abs(result);


         


    }
};



//approach 2 
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0)
            return 0;
        vector<long long > mp(32, 0);
        mp[0] = 1;
        // if only one set bit
        int bit = 1;
        while (bit <= 31) {
            mp[bit] = mp[bit - 1] + (1<<bit);
            bit++;
        }

       

        char sign = '+';
        int result = 0;
        for (int i = 31; i >= 0; i--) {
            int current_bit = ((1 << i)&n);
            if(current_bit == 0 ) continue; 
            
                if (sign == '+') {
                    result += mp[i];
                    sign = '-';
                } else {
                    result -= mp[i];
                    sign = '+';
                }
            
        }

        return abs(result);
    }
};