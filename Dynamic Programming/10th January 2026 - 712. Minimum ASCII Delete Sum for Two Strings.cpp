// 712. Minimum ASCII Delete Sum for Two Strings

class Solution {
public:
int n , m ; 
vector<vector<int>>dp ; 
int solve(string &s1, string &s2, int i , int j){
    if(i >= n && j >= m ) return 0; 

    if(i >= n ){
        return s2[j] + solve(s1, s2, i , j + 1);
    }
    if(j >= m ) {
        return s1[i] + solve(s1, s2, i + 1 ,j);
    }

    if(dp[i][j]!=-1) return dp[i][j];

    if(s1[i] == s2[j]){
        return dp[i][j] = solve(s1, s2, i + 1, j + 1);
    }

        int delete_i = s1[i] + solve(s1, s2, i + 1, j );
        int delete_j = s2[j] + solve(s1 , s2, i, j + 1);

        return dp[i][j] =  min(delete_i, delete_j);
    
    
}

    int minimumDeleteSum(string s1, string s2) {
         n = s1.length();
         m = s2.length();

       dp.assign(n + 1, vector<int> (m  + 1, -1));
         return solve(s1, s2, 0 , 0);
    }
};