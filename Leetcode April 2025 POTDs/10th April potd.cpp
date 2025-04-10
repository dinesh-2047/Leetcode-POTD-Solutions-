// 2999. Count the Number of Powerful Integers


class Solution {
    public:
    long long solve(string &str, int limit , string &givenSuffix){
        int n = str.length();
         if(n < givenSuffix.length()) return 0 ; 
    
         long long ans = 0 ; 
    
         string strSuffix = str.substr(n - givenSuffix.length());
    
         int remainingLen = n - givenSuffix.length();
    
         for(int i = 0 ; i<remainingLen ; i++){
            int digit = str[i] - '0';
    
            if(digit <= limit ){
                ans += (digit * pow(limit+ 1 , remainingLen - i - 1));
            }
            else {
                 ans += pow(limit + 1, remainingLen - i);
                 return ans; 
            }
         }
         if(strSuffix >= givenSuffix){
             ans += 1;
         }
         return ans; 
    }  
    
        long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
          string  startstr = to_string(start - 1);
           string finishstr = to_string(finish);
    
            return solve(finishstr, limit, s) - solve(startstr, limit, s);
        }
    };