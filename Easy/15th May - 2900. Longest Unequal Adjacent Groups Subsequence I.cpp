// 2900. Longest Unequal Adjacent Groups Subsequence I


class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        vector<string>result;
        result.push_back(words[0]);

        for(int i = 1 ; i<n; i++){
            if(groups[i] != groups[i-1]) result.push_back(words[i]);
        }
        return result; 
    }
};