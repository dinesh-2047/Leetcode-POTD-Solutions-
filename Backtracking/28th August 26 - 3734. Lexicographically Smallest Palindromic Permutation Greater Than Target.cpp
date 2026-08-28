// 3734. Lexicographically Smallest Palindromic Permutation Greater Than Target

class Solution {
public:
    vector<int> freq;
    string result = "";
    int count_odd = 0;
    char odd_char;
    int n;
    bool solve(string& target, string curr, int i, bool greater) {
        if (i == n / 2) {
            string temp = curr;
            string rev = temp;
            reverse(rev.begin(), rev.end());
            if (count_odd) {
                temp += odd_char;
            }
            temp += rev;
            if (temp > target) {
                result = temp;
                return true;
            }
            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (freq[ch - 'a'] < 2)
                continue;
            if (!greater && ch < target[i])
                continue;

            curr += ch;
            freq[ch - 'a'] -= 2;
            bool isGreater = greater || ch > target[i];
            if (solve(target, curr, i + 1, isGreater)) {
                return true;
            }

            curr.pop_back();
            freq[ch - 'a'] += 2;
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        n = s.length();
        odd_char = ' ';
        freq.resize(26, 0);
        for (auto& ch : s)
            freq[ch - 'a']++;

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (freq[ch - 'a'] % 2 == 1) {
                count_odd++;
                odd_char = ch;
            }
        }

        if (count_odd > 1)
            return "";

        string curr = "";
        solve(target, curr, 0, false);
        return result;
    }
};