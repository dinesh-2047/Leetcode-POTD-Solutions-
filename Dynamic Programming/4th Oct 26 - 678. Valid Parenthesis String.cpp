// 678. Valid Parenthesis String

class Solution {
public:
int dp[101][101];
int n; 
bool solve(string &s , int i , int bal){
    if(bal < 0 ) return false; 

    if(i >= n){
        return bal == 0 ; 
    }
    if(dp[i][bal] != -1 ) return dp[i][bal];
    bool result = false; 
    if(s[i] == '('){
        result = result || solve(s, i + 1, bal + 1);
    }
    else if(s[i] == ')') result = result || solve(s, i + 1, bal - 1);
    else {
        result = result ||  solve(s, i + 1, bal + 1);
        result = result || solve(s, i + 1, bal - 1);
        result = result || solve(s, i + 1, bal);
    }
    return dp[i][bal] = result; 
}
    bool checkValidString(string s) {
        n = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 0);
    }
};