// 3227. Vowels Game in a String




/*
✨ LeetCode POTD: Vowels Game in a String (3227) 🎮

⁉️ Problem Statement:
 🔸 You are given a string s.
 🔸 Alice and Bob play a game, and Alice goes first.
 🔸 On Alice’s turn: she must remove any non-empty substring of s that contains an odd number of vowels.
 🔸 On Bob’s turn: he must remove any non-empty substring that contains an even number of vowels.
 🔸 The first player who cannot make a valid move loses the game.
 🔸 Assume both players play optimally.
 🔸 Return true if Alice wins, otherwise return false.

🔎 My Approaches:
1️⃣ Approach 1: Count Vowels
 🔹 Traverse the string once and count how many vowels appear.
 🔹 If the count is 0, return false (Alice loses).
 🔹 Otherwise, return true (Alice wins).

2️⃣ Approach 2: Lambda + STL
 🔹 Instead of manually looping, define a lambda function to check if a character is a vowel.
 🔹 Use ranges::any_of (C++20) → directly checks if any character in the string satisfies the condition.
 🔹 If at least one vowel exists, Alice wins.


*/


// Appraoch 1 
class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch =='u';
    }

    bool doesAliceWin(string s) {
        int n = s.length();

        int vowelCount = 0;

        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                vowelCount++;
            }
        }

        if (vowelCount == 0)
            return false;
        else
            return true;
    }
};










//Approach 2 
class Solution {
public:
    
    bool doesAliceWin(string s) {
        int n = s.length();
       
       auto lambda = [&] (char ch ){
          return ch == 'a' || ch == 'e' || ch == 'i' | ch == 'o' || ch == 'u';
       };

        return ranges::any_of(begin(s), end(s), lambda);
        
    }
};