// 2311. Longest Binary Subsequence Less Than or Equal to K

/*
✨ LeetCode POTD: Longest Binary Subsequence Less Than or Equal to K (2311) 🧮🔢

⁉️ Problem Statement :
 🔸 You’re given a binary string s and a positive integer k.
 🔸 You need to find the length of the longest subsequence of s that, when interpreted as a binary number, is less than or equal to k.
 🔸 Return the length of this subsequence.

🔎 Approach I Used :
▶️1. Backtracking (TLE ❌)

▶️ 1. Recursive Dynamic Programming (Top‑Down with Memoization)
 🔹 Use a recursive function solve(i, size, k) to decide whether to include or skip s[i].
 🔹 Base case: if index i < 0, return 0.
 🔹 If s[i] == '0': always safe to include → increase length by 1 without affecting value.
 🔹 If s[i] == '1': check if including it (i.e., 1 << size) keeps total ≤ k.
 🔹 Memoize results using a dp[i][size] table to avoid recomputation.


▶️ 2.Greedy
 🔹 Traverse s from right to left (least to most significant bit).
 🔹 Always include '0' since they don’t affect numeric value.
 🔹 Include '1' only if the value added (1 << power) keeps total ≤ k.
 🔹 Stop if the position exceeds 30 bits (to stay within 1e9).
 🔹 Efficiently builds longest valid subsequence within constraints.

*/

// Approach 1 (DP) 

class Solution {
public:
    int solve(int i, int size, int k, const string &s, vector<vector<int>>& dp) {
        if (i < 0) return 0;
        if (dp[i][size] != -1) return dp[i][size];

        int notTake = solve(i - 1, size, k, s, dp);

        int take = 0;
        if (s[i] == '0') {
            take = 1 + solve(i - 1, size + 1, k, s, dp);
        } else {
            if (size < 31) { 
                long long val = 1LL << size;
                if (val <= k) {
                    take = 1 + solve(i - 1, size + 1, k - val, s, dp);
                }
            }
        }

        return dp[i][size] = max(take, notTake);
    }

    int longestSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(n - 1, 0, k, s, dp);
    }
};








//Approach 2 Greedy 
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();

        int len = 0 ; 
        long long  currValue = 0 ; 
        int power = 0 ; 


        for(int i = n-1; i>=0 ; i--){
            if(s[i]=='0') len++;
            else if(power < 31){
              
                currValue += (1 *  pow(2,power));
                if(currValue <= k ) len++;
                
            }
            power++;
            
        }
        return len ;
    }
};