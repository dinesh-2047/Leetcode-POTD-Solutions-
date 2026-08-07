// 3348. Smallest Divisible Digit Product II

class Solution {
public:
using ll = long long ; 
string solve(ll req , int len){
    string s; 
    for(int digit  = 9; digit >= 2; digit--){
        while(req%digit == 0){
            s.push_back(digit + '0');
            req/=digit; 
        }
    }
    while(s.length() < len){
        s.push_back('1');
    }
    reverse(begin(s), end(s));
    return s ; 
}
    string smallestNumber(string num, long long t) {
        int n = num.length();

        ll temp = t; 

        for(int primeFact : {2, 3, 5, 7}){
            while(temp%primeFact == 0 ){
                temp /= primeFact;
            }
        }
        if(temp!=1) return "-1";

        vector<ll> remFact(n + 1, t);
        for(int i = 0 ; i < n; i++){
            int digit = num[i] - '0';
            if(digit == 0 ) break; 
            remFact[i + 1] = remFact[i]/gcd(remFact[i], (ll)digit);
        }

        if(remFact[n] == 1) return num; 

        int zeroPos = num.find('0');
        int zeroIdx = n - 1; 
        if(zeroPos != -1){
            zeroIdx = zeroPos; 
        }

        for(int i = zeroIdx; i >= 0 ; i--){
            ll req = remFact[i];
            int freeSlots = n - 1 - i ; 

            for(int digit = (num[i] - '0')+1; digit <= 9; digit++){
                ll furtherReq = req/gcd(req, digit);
                string reqNum = solve(furtherReq, freeSlots);

                if(reqNum.length() == freeSlots){
                    return num.substr(0, i) + to_string(digit) + reqNum; 
                }
            }
        }
        return solve(t, n + 1);
    }
};