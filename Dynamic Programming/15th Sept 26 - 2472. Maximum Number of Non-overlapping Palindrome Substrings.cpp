// 2472. Maximum Number of Non-overlapping Palindrome Substrings





class Solution {
public:
    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    int solve(const string& s, int k, int i, int j, vector<vector<int>>& dp) {
        int n = s.size();
        if (i >= n || j >= n) 
            return 0;
            
        if (dp[i][j] != -1) 
            return dp[i][j];

        if (isPalindrome(s, i, j)) {
            int growWindow  = solve(s, k, i, j + 1, dp);
            int takeIt      = 1 + solve(s, k, j + 1, j + k, dp);
            int slideWindow = solve(s, k, i + 1, j + 1, dp);

            return dp[i][j] = max({growWindow, takeIt, slideWindow});
        }

        int slideWindow = solve(s, k, i + 1, j + 1, dp);
        int growWindow  = solve(s, k, i, j + 1, dp);

        return dp[i][j] = max(slideWindow, growWindow);
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (k == 1)
            return n; 

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(s, k, 0, k - 1, dp);
    }
};
