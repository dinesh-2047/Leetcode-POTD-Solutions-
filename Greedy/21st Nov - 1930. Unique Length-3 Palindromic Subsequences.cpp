// 1930. Unique Length-3 Palindromic Subsequences


class Solution {
public:
    int countPalindromicSubsequence(string s) {

        vector<pair<int, int>> pos(26, {0, 0});

        int n = s.length();

        int result = 0;

        for (int i = 0; i < n; i++) {
            pos[s[i] - 'a'].second = i;
        }

        for (int i = n - 1; i >= 0; i--) {
            pos[s[i] - 'a'].first = i;
        }

        for (int i = 0; i < 26; i++) {
            unordered_set<char> st;
            int f_idx = pos[i].first;
            int l_idx = pos[i].second;

            for (int j = f_idx + 1; j < l_idx; j++) {
                st.insert(s[j]);
            }

            result += st.size();
        }

        return result;
    }
};