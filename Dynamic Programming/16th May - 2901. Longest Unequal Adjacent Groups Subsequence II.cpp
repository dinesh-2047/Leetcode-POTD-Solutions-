// 2901. Longest Unequal Adjacent Groups Subsequence II

/*
✨ Today's LeetCode POTD: Longest Unequal Adjacent Groups Subsequence II (2901) 🚀

⁉️ Problem Statement:
You're given:

A list of strings words

A list of integers groups, where groups[i] is the group that words[i] belongs to.

Your task is to find the longest subsequence of words such that:

No two adjacent words in the subsequence belong to the same group, and

Each pair of adjacent words has a Hamming distance exactly equal to 1 (i.e., differ by exactly one character).

Return the actual subsequence, preserving the original order of appearance in the list.

🔷 Approach I Used:

💎 Dynamic Programming + Longest Increasing Subsequence (LIS) Variant

🔹 Core Idea:
Treat each word as a potential end of a valid subsequence. For each word, look back at all previous words. If:

Their groups are different,

Their lengths are equal, and

Their Hamming distance is exactly 1,

Then we can try to extend the chain from the previous word to the current word.

🔹 DP and Parent Arrays:

dp[i]: Length of longest valid subsequence ending at index i.

parent[i]: Used to trace the actual path of the subsequence.

🔹 Final Subsequence Construction:
Start from the index with the maximum dp[i] value and follow the parent[] chain backward to collect all words. Finally, reverse the collected list to get the answer in order.

*/



class Solution {
public:
bool hammingDistance(string str1 , string str2){
    int d = 0 ; 
    for(int i = 0 ; i< str1.length(); i++){
        if(str1[i]!=str2[i]) d++;
    }
    if(d > 1) return false; 
    return d==1;
}

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        vector<string>result; 
        vector<int>parent(n, -1);
        vector<int>dp(n + 1, 1 );
        int longestSubsequence = 1; 
        int longestSubsequenceIdx = 0;

        for(int i = 0 ; i<n; i++){
            for(int j = 0 ; j<i; j++){
                if(groups[j]  != groups[i ] && words[i].length() == words[j].length() && hammingDistance(words[i], words[j]) ){
                     if(dp[j ] + 1 > dp[i] ){
                        dp[i] = dp[j] +1;
                        parent[i] = j;

                        if(longestSubsequence < dp[i]){
                              longestSubsequence = dp[i];
                              longestSubsequenceIdx = i; 
                        }
                     }
                }
            }
        }

        while(longestSubsequenceIdx!=-1){
            result.push_back(words[longestSubsequenceIdx]);
            longestSubsequenceIdx = parent[longestSubsequenceIdx];
        }

        reverse(result.begin(), result.end());
        return result; 
    }
};