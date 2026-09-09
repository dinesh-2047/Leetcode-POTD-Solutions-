// 3871. Count Commas in Range II

class Solution {
public:
using ll = long long ; 
    long long countCommas(long long n) {
        if(n < 1000) return 0 ; 

        ll result = 0 ; 

        if(n < 1000000){
            result +=  (n-1000+1);
            return result; 
        }
        result += 1000000-1000; 

        if(n < 1000000000LL){
            result += 2 *(n - 1000000 + 1);
            return result; 
        }
        result += 2*(1000000000LL - 1000000);
        if(n < 1000000000000LL){
            result += 3 *(n - 1000000000LL + 1);
            return result; 
        }
        result += 3 *(1000000000000LL - 1000000000LL );

        if(n < 1000000000000000LL){
            result += 4 *(n - 1000000000000LL + 1);
            return result; 
        }
          result += 4 *(1000000000000000LL - 1000000000000LL );
          result += 5 * (n - 1000000000000000LL + 1);
          return result; 
    }
};