// 2787. Ways to Express an Integer as Sum of Powers


/*

✨ LeetCode POTD: Ways to Express an Integer as Sum of Powers (2787) 🧠

⁉️ Problem Statement:
🔸 Given two positive integers n and x, return the number of ways to express n as the sum of the x-th powers of unique positive integers.
🔸 Since the answer may be large, return it modulo 1e9 + 7.

🔎 My Approaches:

1️⃣ Top-Down DP (Memoized Recursion)
🔹 Use a recursive function solve(sum, i) to decide whether to take or skip the current number i (raised to power x).
🔹 Maintain a 2D dp table dp[sum][i] to avoid recomputation.
🔹 Base Cases:
  ✔ If sum == n → return 1 (valid way found).
  ✔ If i > n → return 0 (no numbers left).
🔹 Recursive choices:
  - Take: add i^x to the sum if it doesn’t exceed n.
  - Not Take: move to next number without adding it.

2️⃣ Bottom-Up DP (2D Table)
🔹 Create a 2D DP table dp[i][j] = ways to form sum j using numbers from 1 to i.
🔹 Transition:
  - Not taking i: dp[i-1][j]
  - Taking i: dp[i-1][j - i^x] (if valid)
🔹 Answer is dp[n][n].

3️⃣ Bottom-Up DP (Space Optimization with 2 Arrays)
🔹 Maintain only two 1D arrays: prev and curr.
🔹 For each i, compute curr[j] from prev using same take / not-take logic.
🔹 Swap arrays after each iteration to save memory.

4️⃣ Bottom-Up DP (1D Optimized)
🔹 Use only one array dp[j], updating from j = n downwards to avoid overwriting needed states.
🔹 Transition:
  dp[j] += dp[j - i^x] (mod 1e9 + 7).
🔹 Most memory-efficient solution with O(n) space.
*/


// Approach 1 
class Solution {
public:
    const int mod = 1e9 + 7;
  vector<vector<int>>dp;
    int solve(int n, int x, int sum, int i) {
        if (sum == n) {
            return 1;
        }
        if (i > n) {
            return 0;
        }
        if(dp[sum][i] !=-1) return dp[sum][i];

        int take = 0;
        int power = ((int)pow(i, x))%mod;
        if(power > n ) return 0; 
        int val = (sum + power )%mod;
        if (val <= n) {
            take = solve(n, x, val, i + 1)%mod;
        }
          int not_take = solve(n, x, sum, i + 1)%mod;
        return dp[sum][i] =  (take + not_take)%mod;
    }

    int numberOfWays(int n, int x) {
        dp.resize(301, vector<int>(301, -1));
        return solve(n, x, 0, 1);
    }
};



//Approach 2 
class Solution {
public:
const int mod = 1e9 + 7; 
    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        dp[0][0] = 1; 
        for(int i = 1; i <= n; i++){
             long long value = ((long long)pow(i, x))%mod;
            for(int j = 0 ; j <= n ; j++){
                dp[i][j] = (dp[i-1][j])%mod;
                if(j-value >= 0 ){
                    dp[i][j] = (dp[i][j] + dp[i-1][j-value])%mod;
                }
            }
        }
        return dp[n][n];
    }
};





//Approach 3 
class Solution {
public:
const int mod = 1e9 + 7; 
    int numberOfWays(int n, int x) {
     
        vector<int>curr(n+1, 0);
        vector<int>prev(n+1, 0);

       
        prev[0] = 1; 
        for(int i = 1; i <= n; i++){
             long long value = ((long long)pow(i, x))%mod;
            for(int j = 0 ; j <= n ; j++){
                curr[j] = (prev[j])%mod;
                if(j-value >= 0 ){
                    curr[j] = (curr[j] + prev[j-value])%mod;
                }
            }
            prev = curr;
        }
        return curr[n];
    }
};




//Approach 4]
class Solution {
public:
const int mod = 1e9 + 7; 
    int numberOfWays(int n, int x) {
        vector<int>dp(n+1, 0);

         dp[0] = 1; 
        for(int i = 1; i <= n; i++){
             long long value = ((long long)pow(i, x))%mod;
            for(int j = n ; j >=value ; j--){
                    dp[j] = (dp[j] + dp[j-value])%mod;
            }
            
        }
        return dp[n];
    }
};