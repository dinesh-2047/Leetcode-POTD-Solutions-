// 1733. Minimum Number of People to Teach




class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {

        unordered_map<int, unordered_set<int>> mp;

        for (int i = 0; i < languages.size(); i++) {
            for (auto& l : languages[i]) {
                mp[i + 1].insert(l);
            }
        }

        unordered_set<int> not_common;

        for (auto& f : friendships) {
            int user1 = f[0];
            int user2 = f[1];

            unordered_set<int> st = mp[user1];
            bool valid = true;
            for (auto& s : st) {
                if (mp[user2].count(s)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                not_common.insert(user1);
                not_common.insert(user2);
            }
        }

        unordered_map<int, int> mp2;
        for (auto& s : not_common) {
            for (auto& f : mp[s]) {
                mp2[f]++;
            }
        }

        int maxFreq = 0;
        for (auto& [_, freq] : mp2) {
            maxFreq = max(maxFreq, freq);
        }

        return not_common.size() - maxFreq;
    }
};