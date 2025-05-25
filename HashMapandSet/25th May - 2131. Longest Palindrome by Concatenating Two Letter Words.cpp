// 2131. Longest Palindrome by Concatenating Two Letter Words


/*

✨ LeetCode POTD: Longest Palindrome by Concatenating Two Letter Words (2131) 🚀

⁉️ Problem Statement:
🔸 You are given an array of strings words, where each string consists of two lowercase English letters.
🔸 Your task is to select and concatenate some of these words in any order to form the longest possible palindrome. Each word can be used at most once.
🔸 Return the length of the longest palindrome that can be created. If it is impossible to create any palindrome, return 0.

🔎 Approach Used:

1️⃣ Greedy Pairing with Hash Map
🔹 Iterate through each word in the list.
🔹 For each word, check if its reverse exists in the hash map with a count greater than zero.
  - If such a reverse word is found, it forms a palindrome pair. Increment the result by 4 (since each word is 2 letters) and decrement the count of the reverse word in the map.
  - If not, increment the count of the current word in the map for future pairing.

2️⃣ Handling Center Palindromic Word
🔹 After processing all words, iterate through the hash map to find any word with identical characters (e.g., "aa") that has a count greater than zero.
🔹 If such a word is found, it can be placed in the center of the palindrome. Increment the result by 2 and break the loop, as only one such word can be used in the center.


*/
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;

        int result = 0;

        for(string &word : words) {
            string reversedWord = word;
            swap(reversedWord[0], reversedWord[1]);

            if(mp[reversedWord] > 0) {
                result += 4;
                mp[reversedWord]--;
            } else {
                mp[word]++;
            }
        }

        //Check equal character words. Use only one
        for(auto &it : mp) {
            string word = it.first;
            int count = it.second;

            if(word[0] == word[1] && count > 0) {
                result += 2;
                break;
            }
        }

        return result;
    }
};