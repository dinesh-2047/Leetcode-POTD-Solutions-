class Solution {
public:
    const int MOD = 1e9 + 7;  // Modulo value to prevent overflow and ensure correct results

    // Recursive function to calculate the number of ways to form the target string
    int solve(vector<string>& words, string &target, int i, int j, vector<vector<long long>>& freq, vector<vector<int>>& dp) {

        if (i == target.length()) return 1;  // If we've matched the entire target string, return 1

        if (j >= words[0].length()) return 0;  // If we've exhausted the columns in the words without matching the target, return 0

        if (dp[i][j] != -1) return dp[i][j];  // If the result is already computed for this state, return it

        // Calculate the number of ways by taking or not taking the character at position j in the words
        int take = freq[target[i] - 'a'][j] * solve(words, target, i + 1, j + 1, freq, dp) % MOD;

        int not_take = solve(words, target, i, j + 1, freq, dp) % MOD;

        // Store the result in dp table to avoid recomputation and return the result
        return dp[i][j] = (take + not_take) % MOD;
    }

    // Main function to compute the number of ways to form the target string using words
    int numWays(vector<string>& words, string &target) {
        int m = words[0].length();  // Number of columns in each word
        int k = target.length();    // Length of the target string
        
        // Frequency matrix: freq[c][j] = number of times character 'c' appears at column j in words
        vector<vector<long long>> freq(26, vector<long long>(m, 0));

        // Populate the frequency matrix for each character in words
        for (int col = 0; col < m; col++) {
            for (string &word : words) {
                char ch = word[col];
                freq[ch - 'a'][col]++;  // Increment the frequency of character 'ch' at column 'col'
            }
        }

        // DP table to store the number of ways to match the target string starting from target[i] and word[j]
        vector<vector<int>> dp(1001, vector<int>(1001, -1));  // dp[i][j] represents the number of ways to form target[i:] using words[j:]

        // Start the recursion from the beginning of the target and words
        return solve(words, target, 0, 0, freq, dp);
    }
};

/*
Time Complexity:
- The function `solve` is called with parameters (i, j) representing the index in the target and the index in the word. 
- There are at most `k` (length of target) recursive calls for `i`, and at most `m` (length of words) recursive calls for `j`, making the time complexity O(k * m).
- Each state is computed once due to memoization in the dp table, so the time complexity is O(k * m).

Space Complexity:
- We store the `freq` matrix, which is of size 26 x m (26 for each character of the alphabet, and m for the columns in the words), giving a space complexity of O(26 * m) ≈ O(m).
- The `dp` table is of size k x m, giving a space complexity of O(k * m).
- Thus, the total space complexity is O(k * m).
*/
