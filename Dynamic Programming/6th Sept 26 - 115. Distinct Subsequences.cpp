// 115. Distinct Subsequences

class Solution {
public:
int n , m ;
vector<vector<int>> dp;
int solve(string &s, string &t, int i , int j){
    if(j >= m ) return 1; 
    if(i >= n ){
         return 0; 
    }

    if(dp[i][j]!=-1) return dp[i][j];

    int not_take = solve(s, t, i+1, j);
    int take = 0 ;
    if(s[i] == t[j]){
        take = solve(s, t, i + 1, j + 1);
    }
    return dp[i][j] = take + not_take; 
}
    int numDistinct(string s, string t) {
         n = s.length();
        m = t.length();
        dp.resize(n , vector<int>(m , -1));
       return solve(s, t , 0, 0);
        
    }
};