// 3085. Minimum Deletions to Make String K-Special

/*
✨ LeetCode POTD: Minimum Deletions to Make String K‑Special (3085) 🧩✂️

⁉️ Problem Statement :

 🔸 You’re given a string word and an integer k.

 🔸 A string is k‑special if for any two characters in it, the difference between their frequencies is at most k (i.e., |freq(a) - freq(b)| ≤ k for all a, b).

 🔸 Return the minimum number of deletions needed to make word k‑special.



🔎 Approach I Used:

1️⃣. Brute Force Frequency Comparison

 🔹 Count frequencies of all characters.

 🔹 For each character frequency freq[i], try to make all other character frequencies fall in the range [freq[i], freq[i] + k].

 🔹 If another character’s frequency freq[j] is less than freq[i], delete all of freq[j].

 🔹 If freq[j] > freq[i] + k, calculate the number of deletions needed using:

 deletions += diff - k

 where diff = |freq[i] - freq[j]|

 🔹 Track the minimum deletions required for all such base frequencies.



2️⃣ Optimized Greedy + Sorting

 🔹 Count and sort all non-zero frequencies.

 🔹 For each index i (treated as the base frequency to preserve):

 • Delete all characters with frequency less than freq[i] using a prefix sum (cumDel).

 • For any character frequency freq[j] where j > i and freq[j] > freq[i] + k, apply:

 deletions += freq[j] - freq[i] - k

 🔹 Keep track of the minimum deletions across all such choices.

*/



//Approach 1
class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.length();

        vector<int> freq(26, 0);
        int count = INT_MAX;

        for (auto& ch : word) {
            freq[ch - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0)
                continue;
            int deleted = 0;
            for (int j = 0; j < 26; j++) {
                if (freq[j] == 0 || i == j)
                    continue;
                int diff = abs(freq[i] - freq[j]);

                if (freq[j] < freq[i]) {
                    deleted += freq[j];
                }

                else if (diff > k) {

                    deleted += abs(diff - k);
                }
            }

            count = min(deleted, count);
        }
        return count;
    }
};














//Approach 2 

class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.length();

        vector<int> freq(26, 0);
        for (auto& ch : word) {
            freq[ch - 'a']++;
        }

        sort(freq.begin(), freq.end());
        int result = INT_MAX;

        int c = 0;
        while (c < 26 && freq[c] == 0)
            c++;

        int cumDel = 0;
        for (int i = c; i < 26; i++) {
            int deleted = cumDel;

            for (int j = 25; j > i; j--) {
                if (freq[j] - freq[i] <= k)
                    break;

                else {
                    deleted += freq[j] - freq[i] - k;
                }
            }

            result = min(result, deleted);
            cumDel += freq[i];
        }

        return result;
    }
};