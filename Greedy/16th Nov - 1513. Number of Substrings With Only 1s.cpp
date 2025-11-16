// 1513. Number of Substrings With Only 1s

class Solution {
public:
int mod = 1e9 + 7; 

    int numSub(string s) {
        int n = s.length();

        long long result = 0 ; 
        long long count0 = 0 ; 


        for(int i = 0 ; i  < n; i++){
            if(s[i] == '1'){
                count0 = count0 + 1 ;
            }
            else{
            
               result +=  ((count0 * (count0 + 1)%mod)/2)%mod;
               count0 = 0 ; 
            }
        }
        result +=  ((count0 * (count0 + 1)%mod)/2)%mod;


        return result; 
    }
};