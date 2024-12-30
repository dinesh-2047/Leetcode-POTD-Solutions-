// All approaches of DP 

class Solution {
public:
    const int MOD = 1e9 + 7;

    // Recursive function with memoization to count good strings
    int solve(int low, int high, int zero, int one, int length, vector<int>& dp) {
        // If length exceeds high, return 0
        if (length > high) return 0;

        // If length is between low and high, add 1 to the result
        bool addOne = false;
        if (length >= low && length <= high) addOne = true;

        // If the result for this length is already computed, return it
        if (dp[length] != -1) return dp[length];

        // Recursively compute the result by appending either 0 or 1
        int append_one = solve(low, high, zero, one, length + one, dp) % MOD;
        int append_zero = solve(low, high, zero, one, length + zero, dp) % MOD;

        // Store the result in dp and return it
        return dp[length] = (addOne + append_one + append_zero) % MOD;
    }

    // Bottom-up dynamic programming approach for counting good strings
    int solve2(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);

        // Base case: There's one way to form a string of length 0 (the empty string)
        dp[0] = 1;

        // Iterate over all lengths from 1 to high and calculate the number of ways to form them
        for (int i = 1; i <= high; i++) {
            if (i - zero >= 0) dp[i] = (dp[i] + dp[i - zero]) % MOD;
            if (i - one >= 0) dp[i] = (dp[i] + dp[i - one]) % MOD;
        }

        // Sum the results for lengths in the range [low, high]
        int ans = 0;
        for (int l = low; l <= high; l++) {
            ans = (ans + dp[l]) % MOD;
        }

        return ans;
    }

    // Optimized bottom-up dynamic programming approach for counting good strings
    int solve3(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);

        // Base case: There's one way to create an empty string (length 0)
        dp[0] = 1;

        // Iterate over all lengths from 0 to high
        for (int i = 0; i <= high; i++) {
            if (dp[i] > 0) {
                // If current length is i, we can add either zero or one to extend it
                if (i + zero <= high) {
                    dp[i + zero] = (dp[i + zero] + dp[i]) % MOD;
                }
                if (i + one <= high) {
                    dp[i + one] = (dp[i + one] + dp[i]) % MOD;
                }
            }
        }

        // Sum the results for lengths in the range [low, high]
        int result = 0;
        for (int i = low; i <= high; i++) {
            result = (result + dp[i]) % MOD;
        }

        return result;
    }

    // Main function to count good strings using one of the above methods
    int countGoodStrings(int low, int high, int zero, int one) {
        // Option 1: Recursive solution with memoization
        // vector<int> dp(high + 1, -1);
        // return solve(low, high, zero, one, 0, dp);

        // Option 2: Bottom-up DP approach (solve2)
        // return solve2(low, high, zero, one);

        // Option 3: Optimized Bottom-up DP approach (solve3)
        return solve3(low, high, zero, one);
    }
};

// Time Complexity:
//
// 1. For `solve` (recursive approach with memoization), the time complexity is O(high) since each length is computed once and cached in the `dp` array. However, the recursive calls ensure each state is calculated at most once.
//
// 2. For `solve2` (bottom-up DP), the time complexity is O(high) as we iterate through all lengths from `1` to `high` and perform constant-time operations for each length.
//
// 3. For `solve3` (optimized bottom-up DP), the time complexity is O(high) as we iterate through all lengths from `0` to `high` and perform constant-time operations for each length.
//
// Overall, the time complexity for each solution is O(high).
//
// Space Complexity:
// - For `solve` and `solve2`, the space complexity is O(high) due to the `dp` array used to store the results for each length.
// - For `solve3`, the space complexity is O(high) for the same reason.
