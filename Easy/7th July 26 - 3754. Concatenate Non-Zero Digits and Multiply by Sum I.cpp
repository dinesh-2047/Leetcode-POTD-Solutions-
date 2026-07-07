// 3754. Concatenate Non-Zero Digits and Multiply by Sum I

class Solution {
public:
using ll = long long ; 
    long long sumAndMultiply(int n) {
        ll x = 0 ; 
        string s = to_string(n);
        for(auto &ch : s){
            if(ch != '0') x = x * 10 + (ch - '0');
        }
        ll sum = 0 ; 
        while(n){
            sum += (n%10);
            n/=10; 
        }

        return x * sum ; 
    }
};