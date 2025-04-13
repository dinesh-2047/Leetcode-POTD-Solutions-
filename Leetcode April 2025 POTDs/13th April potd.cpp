// 1922. Count Good Numbers

class Solution {
    public:
    const int mod = 1e9 + 7;
    long long power(long long a , long long b){
        if(b==0) return 1; 
        long long half = power(a, b/2)%mod;
        long long result = (half * half )%mod; 
    
        if(b%2==1){
            result = (result * a)%mod;
        }
        return result; 
    }
    
        int countGoodNumbers(long long n) {
            long long evens = (n+1)/2;
            long long odds = (n/2);
    
            return (power(5,evens) * power(4,odds))%mod;
    
        }
    };