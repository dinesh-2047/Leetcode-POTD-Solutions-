// 966. Vowel Spellchecker


class Solution {
public:
    bool isVowel(char ch) {
        string vowels = "aeiou";
        return vowels.find(ch) != string::npos;
    }

    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {

        int n = queries.size();

        unordered_map<string, int> mp;
        for (int i = 0; i < wordlist.size(); i++) {
            mp[wordlist[i]] = i;
        }

        unordered_map<string, int> mp2;
        for (int i = 0; i < wordlist.size(); i++) {
            string word = wordlist[i];
            for (int j = 0; j < word.length(); j++) {
                char ch = tolower(word[j]);
                word[j] = ch;
            }
            if (!mp2.count(word))
                mp2[word] = i;
        }

        unordered_map<string, int> mp3;
        for (int i = 0; i < wordlist.size(); i++) {
            string word = wordlist[i];
            string vowel_position_wordlist;
            for (int k = 0; k < word.length(); k++) {
                char ch = tolower(word[k]);
                if (isVowel(ch)) {
                    vowel_position_wordlist.push_back('*');
                } else
                    vowel_position_wordlist.push_back(ch);
            }
            if (!mp3.count(vowel_position_wordlist))
                mp3[vowel_position_wordlist] = i;
        }

        vector<string> result(n);

        for (int i = 0; i < n; i++) {
            string query = queries[i];

            if (mp.count(query)) {
                result[i] = wordlist[mp[query]];
                continue;
            }

            for (int j = 0; j < query.length(); j++) {
                char ch = tolower(query[j]);
                query[j] = ch;
            }

            // wordlist check for capatilization

            if (mp2.count(query)) {
                result[i] = wordlist[mp2[query]];
                continue;
            }

            // vowel error check

            string vowel_position_query;
            for (int j = 0; j < query.length(); j++) {
                if (isVowel(query[j])) {
                    vowel_position_query.push_back('*');
                } else
                    vowel_position_query.push_back(tolower(query[j]));
            }

            if (mp3.count(vowel_position_query)) {
                result[i] = wordlist[mp3[vowel_position_query]];
                continue;
            }

            result[i] = "";
        }
        return result;
    }
};