// 1092. Shortest Common Supersequence 

// Bottom up dp approach 

class Solution {
    public:
    
        string shortestCommonSupersequence(string str1, string str2) {
           int n = str1.length();
        int m = str2.length();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
        // Base case: If one string is empty, we need to insert all characters from the other string
        for (int i = 0; i <= n; i++) dp[i][m] = n - i;
        for (int j = 0; j <= m; j++) dp[n][j] = m - j;
    
        // Fill DP table bottom-up
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (str1[i] == str2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
    
        // Construct the SCS string using the dp table
        int i = 0, j = 0;
        string scs = "";
        
        while (i < n && j < m) {
            if (str1[i] == str2[j]) {
                scs += str1[i];
                i++, j++;  // Move diagonally
            } else if (dp[i + 1][j] < dp[i][j + 1]) {
                scs += str1[i];
                i++;  // Move down
            } else {
                scs += str2[j];
                j++;  // Move right
            }
        }
    
        // Append remaining characters
        while (i < n) scs += str1[i++];
        while (j < m) scs += str2[j++];
    
        return scs;
    }
    
    };