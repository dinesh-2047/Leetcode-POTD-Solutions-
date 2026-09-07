// 940. Distinct Subsequences II

class Solution {
public:
int n ;
int mod = 1e9 + 7 ; 
vector<int> prev; 
int dp[2001];
int solve(int n){
    if(n == 0 ) {
         return 1; 
    }

   if(dp[n]!=-1) return dp[n];
    int result = (2 * solve(n - 1))%mod; 

    if(prev[n]!=0){
        int dup = solve(prev[n] - 1);
        result = (result - dup + mod )%mod;
    }
    return dp[n] =  result; 
}
    int distinctSubseqII(string s) {
         n = s.length() ;

         prev.assign(n + 1, 0);
           memset(dp, -1, sizeof(dp));
         vector<int> lastSeen(26, 0);
         for(int i = 1; i  <= n; i++){
            int idx = s[i -1]-'a';
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i ; 
         }
         return (solve(n)-1 +mod )%mod; 
    }
};