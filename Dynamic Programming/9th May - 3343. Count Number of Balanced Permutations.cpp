// 3343. Count Number of Balanced Permutations



/*
✨ Today's LeetCode POTD: Count Number of Balanced Permutations (3343) 🚀

⁉️ Problem Statement:
🔹 You are given a string num. A string of digits is called balanced if the sum of the digits at even indices is equal to the sum of the digits at odd indices.
🔹 Return the number of distinct permutations of num that are balanced. Since the answer may be very large, return it modulo 10⁹ + 7.

🔷 Approach I Used:

💎 Approach: Recursive DP + Combinatorics
🔹 Digit Frequency: Count the frequency of each digit in the input string.
🔹 Factorials & Modular Inverses: Precompute factorials and their modular inverses to handle permutations with duplicate digits efficiently.
🔹 Dynamic Programming:
  - Define a recursive function dfs(i, j, a, b) where:
    - i is the current digit being considered (0 to 9).
    - j is the remaining sum needed for digits at odd indices.
    - a is the number of positions left at odd indices.
    - b is the number of positions left at even indices.
  - At each step, distribute the available count of digit i between odd and even positions, ensuring the sum at odd indices reaches the required value.
  - Use memoization to store intermediate results and avoid redundant calculations.
🔹 Final Calculation: The answer is obtained by calling dfs(0, total_sum / 2, n / 2, (n + 1) / 2) where n is the length of num and total_sum is the sum of all digits in num.

📌 Key Concepts Used:
✔️ Digit Frequency Counting
✔️ Factorials and Modular Inverses
✔️ Recursive Dynamic Programming with Memoization
✔️ Combinatorics for Permutations with Duplicates
✔️ Modular Arithmetic




*/



class Solution {
public:
    int n;
    int totalDigitSum;
    int M = 1e9 + 7;
    long long totalPermPossible = 0;

    //Binary exponentian
    int findPower(long long a, long long b) {
        if(b == 0) {
            return 1;
        }

        long long half = findPower(a, b/2);
        long long result = (half * half) % M;
        if(b % 2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    int solve(int digit, int evenIndexDigitsCount, int currSum, 
            vector<int>& freq, vector<long long>& fermatFact, 
            vector<vector<vector<int>>> &t) {
        if(digit == 10) {
            if(currSum == totalDigitSum/2 && evenIndexDigitsCount == (n+1)/2) {
                return totalPermPossible;
            }
            return 0;
        }

        if(t[digit][evenIndexDigitsCount][currSum] != -1) {
            return t[digit][evenIndexDigitsCount][currSum];
        }
        long long ways = 0;

        for(int count = 0; count <= min(freq[digit], (n+1)/2 - evenIndexDigitsCount); count++) {
            int evenPosCount = count;
            int oddPosCount  = freq[digit] - count;

            long long div = (fermatFact[evenPosCount] * fermatFact[oddPosCount])% M;

            long long val = solve(digit+1, evenIndexDigitsCount + evenPosCount, currSum + digit*count, freq, fermatFact, t);

            ways = (ways + (val * div) % M) % M;
        }

        return t[digit][evenIndexDigitsCount][currSum] = ways;
    }

    int countBalancedPermutations(string num) {
        n   = num.length();
        totalDigitSum = 0;

        vector<int> freq(10, 0);
        for(int i = 0; i < n; i++) {
            totalDigitSum += num[i] - '0';
            freq[num[i] - '0']++;
        }

        if(totalDigitSum % 2 != 0) {
            return 0;
        }

        //Precomputing factorial
        vector<long long> fact(n+1, 1);
        fact[0] = 1;
        fact[1] = 1;
        for(int i = 2; i <= n; i++) {
            fact[i] = (fact[i-1] * i) % M;
        }

        //Precomputing FermatFactorial (inverse factorial --- (1/x)%M)
        vector<long long> fermatFact(n+1, 1);
        for(int i = 0; i <= n; i++) {
            fermatFact[i] = findPower(fact[i], M-2) % M;
        }

        totalPermPossible = (1LL * fact[(n+1)/2] * fact[n/2]) % M;

        int digit = 0;
        int evenIndexDigitsCount = 0;
        int currSum = 0;
        vector<vector<vector<int>>> t(10, vector<vector<int>>((n + 1) / 2 + 1, vector<int>(totalDigitSum + 1, -1)));
        return solve(digit, evenIndexDigitsCount, currSum, freq, fermatFact, t);

    }
};

