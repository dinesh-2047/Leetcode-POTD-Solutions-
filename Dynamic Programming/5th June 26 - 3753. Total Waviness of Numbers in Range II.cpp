// 3753. Total Waviness of Numbers in Range II

class Solution {
public:
using ll = long long ; 
pair<ll, ll> dp[16][2][2][11][11];
pair<ll, ll> solve(string &s, int idx, int tight,  int started, int prev1 , int prev2 ){
    if(idx == 16) return {0, 1};

    if(dp[idx][tight][started][prev1][prev2].first!=-1)  return dp[idx][tight][started][prev1][prev2];

    int limit = (tight == 1) ? (s[idx] - '0') : 9 ; 
    
    ll wv = 0 ; 
    ll cnt = 0 ; 
    
    for(int i = 0 ; i  <= limit ; i++){
         int next_tight = tight &(i == (s[idx] - '0'));
         int next_started = (started && i == 0 );
         int next_prev2 = prev1; 
         int next_prev1 = next_started ? 10 : i;

         pair<ll , ll> next_pair = solve(s, idx + 1, next_tight , next_started, next_prev1, next_prev2);

         wv += next_pair.first; 
         cnt += next_pair.second; 

         if(prev2 != 10 && prev1 != 10){
             bool isPeak = prev1 > prev2 && prev1 > i;
             bool isValley = prev1 < prev2 && prev1 < i ; 

             if(isPeak || isValley) wv += next_pair.second; 
         }
    }
    return dp[idx][tight][started][prev1][prev2]  = {wv,cnt};
}

    long long totalWaviness(long long num1, long long num2) {
         string ri = to_string(num2);
         while(ri.length() < 16) ri = '0' + ri; 
         string le = to_string(num1 - 1);
         while(le.length() < 16 ) le = '0' + le; 

         memset(dp, -1, sizeof(dp));
         ll leftAns = solve(le, 0, 1, 1 , 10,10).first;
         memset(dp, -1, sizeof(dp));
         ll rightAns = solve(ri, 0 , 1, 1 , 10,10).first;

         return rightAns - leftAns; 
   
    }
};