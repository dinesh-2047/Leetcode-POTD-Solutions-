// 3333. Find the Original Typed String II
/*


✨ LeetCode POTD: Find the Original Typed String II (3333) 🔠🧠

⁉️ Problem Statement (LeetCode):
🔸 Alice types a string, but due to accidental long-pressing of some keys, certain characters may be repeated.
🔸 However, this time long-pressing may have occurred multiple times in the string.
🔸 Given the final typed string and an integer k, return the number of possible original strings of length k that could lead to the given string via long-pressing.
🔸 Return the answer modulo 10⁹ + 7.

🔎 Approach I Used (C++):

▶️ Recursive + Memoization Approach:
• Break the string into segments of consecutive repeated characters and store their lengths in a frequency vector.
• Calculate total possible ways to select one or more characters from each group as the product of all frequencies.
• Then, recursively explore all group combinations where selected characters form a string of length < k.
• Memoize intermediate states with (i, count) to avoid redundant calculations.
• Final result = total combinations − invalid combinations.

▶️ Bottom-Up Dynamic Programming Approach:
• Convert the recursive logic into a DP table dp[i][count], which stores the number of invalid ways from index i onward having already selected count characters.
• Iterate from the last group to the first, and for each count, try taking 1 to freq[i] characters.
• Accumulate invalid results iteratively.
• Subtract invalid from total to get the final answer.

▶️ Dynamic Programming + Group Frequency Multiplication
• First, break the typed string into groups of consecutive characters and store their lengths in a vector freq.
• The total number of ways to reduce the repeated characters is calculated as the product of all group sizes.
 — This represents the total ways to choose one character from each long-press group (no constraints).
• However, we must subtract the number of invalid reductions that would make the final string length less than k.

• For that, we use DP + prefix sums:
 🔹 Let dp[i][count] represent the number of ways to reduce groups starting from index i with count characters already chosen.
 🔹 We build dp bottom-up from the end of the group list, tracking prefix sums to speed up the range sum calculation for valid reduction scenarios.
• Finally, subtract all invalid combinations from the total to get the result.
*/



//Approach-1 (Recursion + Memoization) - TLE
//T.C : O(n*k*maxFreq), n = total unique characters, maxFreq = maximumFrequency of a character
//S.C : O(n*k)
class Solution {
public:
    int M = 1e9+7;
    vector<vector<int>> t;

    int solve(int i, int count, vector<int>& freq, int k) {
        if(i >= freq.size()) {
            if(count < k)
                return 1; //found invalid string
            return 0;
        }

        if(t[i][count] != -1) {
            return t[i][count];
        }

        long long result = 0;

        for(int take = 1; take <= freq[i]; take++) {
            if(count + take < k) {
                result = (result + solve(i+1, count+take, freq, k)) % M;
            } else {
                break;
            }
        }

        return t[i][count] = result;
    }

    int possibleStringCount(string word, int k) {
        if(k > word.length())
            return 0;
        
        vector<int> freq;
        int count = 1;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1]) {
                count++;
            } else {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long P = 1; //total possible strings
        for(int &f : freq) {
            P = (P * f) % M;
        }
        
        if(freq.size() >= k) {
            return P;
        }
        int n = freq.size();
        t.assign(n+1, vector<int>(k+1, -1)); //invalid krne k lie count should be less than k < k
        //We have to now find count of invalid strings 
        long long invalidCount = solve(0, 0, freq, k);

        return (P - invalidCount + M) % M;


    }
};


//Approach-2 (Bottom Up) - TLE
//T.C : O(n*k*maxFreq), n = total unique characters, maxFreq = maximumFrequency of a character
//S.C : O(n*k)
class Solution {
public:
    int M = 1e9+7;

    int possibleStringCount(string word, int k) {
        if(k > word.length())
            return 0;
        
        vector<int> freq;
        int count = 1;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1]) {
                count++;
            } else {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long P = 1; //total possible strings
        for(int &f : freq) {
            P = (P * f) % M;
        }
        
        if(freq.size() >= k) {
            return P;
        }
        int n = freq.size();
        
        vector<vector<int>> t(n+1, vector<int>(k+1, 0));

        for(int count = k-1; count >= 0; count--) {
            t[n][count] = 1;
        }

        for(int i = n-1; i >= 0; i--) {
            for(int count = k-1; count >= 0; count--) {

                long long result = 0;

                for(int take = 1; take <= freq[i]; take++) {
                    if(count + take < k) {
                        result = (result + t[i+1][count+take]) % M;
                    } else {
                        break;
                    }
                }

                t[i][count] = result;
            }
        }

        long long invalidCount = t[0][0];

        return (P - invalidCount + M) % M;


    }
};



//Approach-3 (Bottom Up) - Optimized
//T.C : O(n*k)
//S.C : O(n*k)
class Solution {
public:
    int M = 1e9+7;

    int possibleStringCount(string word, int k) {
        if(k > word.length())
            return 0;
        
        vector<int> freq;
        int count = 1;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1]) {
                count++;
            } else {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long P = 1; //total possible strings
        for(int &f : freq) {
            P = (P * f) % M;
        }
        
        if(freq.size() >= k) {
            return P;
        }
        int n = freq.size();
        
        vector<vector<int>> t(n+1, vector<int>(k+1, 0));

        for(int count = k-1; count >= 0; count--) {
            t[n][count] = 1;
        }

        for(int i = n-1; i >= 0; i--) {

            vector<int> prefix(k+1, 0);
            for(int h = 1; h <= k; h++) {
                prefix[h] = (prefix[h-1] + t[i+1][h-1]) % M;
            }

            for(int count = k-1; count >= 0; count--) {
                
                int l = count + 1;
                int r = count + freq[i];

                if(r+1 > k) {
                    r = k-1;
                }

                if(l <= r) {
                    t[i][count] = (prefix[r+1] - prefix[l] + M) % M;
                }
                
            }
        }

        long long invalidCount = t[0][0];

        return (P - invalidCount + M) % M;
    }
};