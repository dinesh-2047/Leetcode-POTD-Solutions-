// 2785. Sort Vowels in a String


/*
✨ LeetCode POTD: Sort Vowels in a String (2785) ✨

⁉️ Problem Statement:
🔸 You are given a string s.
🔸 The task is to sort all the vowels in the string while keeping the consonants in their original positions.
🔸 Both uppercase and lowercase vowels (a, e, i, o, u, A, E, I, O, U) must be considered.

🔎 My Approaches:

1️⃣ Approach 1: Extract + Sort + Replace
🔹 Traverse the string and extract all vowels into a separate string.
🔹 Sort this string of vowels.
🔹 Traverse s again and replace vowels in order from the sorted list.


2️⃣ Approach 2: Counting Sort (Frequency Arrays)
🔹 Instead of sorting directly, count the frequency of each vowel (uppercase and lowercase separately).
🔹 Traverse the string again, and whenever a vowel is found, place the smallest available vowel based on frequency.


3️⃣ Approach 3: Ordered Mapping with Predefined Vowel Order
🔹 Use a hash map to count occurrences of each vowel.
🔹 Maintain a predefined order "AEIOUaeiou".
🔹 Traverse the string and for each vowel, replace it with the next available vowel from the ordered map.



*/




// Approach 1
class Solution {
public:
    bool isVowel(char ch) {
        string vowel = "aeiouAEIOU";
        return vowel.find(ch) != string::npos;
    }

    string sortVowels(string s) {
        int n = s.length();

        string all_vowels = "";

        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                all_vowels.push_back(s[i]);
            }
        }

        sort(all_vowels.begin(), all_vowels.end());

        string result = s;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                result[i] = all_vowels[j++];
            }
        }

        return result;
    }
};







//Approach 2 
class Solution {
public:
    bool isVowel(char ch) {
        string vowel = "aeiouAEIOU";
        return vowel.find(ch) != string::npos;
    }

    bool is_lowercase(char ch) { 
        return ch >= 'a' && ch <= 'z'; 
        }

    string sortVowels(string s) {
        int n = s.length();

        vector<int> upper_vowel(26, 0);
        vector<int> lower_vowel(26, 0);

        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                if (is_lowercase(s[i])) {
                    lower_vowel[s[i] - 'a']++;
                    
                } else {
                    upper_vowel[s[i] - 'A']++;
                }
            }
        }

        string result = s;
        int newStart = 0;
        for (int i = 0; i < 26; i++) {

            if (upper_vowel[i] == 0)
                continue;

            for (int j = newStart ; j < n; j++) {
                if (isVowel(s[j])) {
                    result[j] = i + 'A';
                    upper_vowel[i]--;

                    if (upper_vowel[i] == 0) {
                        newStart = j+1;
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            if (lower_vowel[i] == 0)
                continue;

            for (int j = newStart ; j < n; j++) {
                if (isVowel(s[j])) {
                    result[j] = i + 'a';
                    lower_vowel[i]--;

                    if (lower_vowel[i] == 0) {
                        newStart = j+1;
                        break;
                    }
                }
            }
        }

        return result;
    }
};






//Approach 3 
class Solution {
public:
    bool isVowel(char ch) {
        string vowel = "aeiouAEIOU";
        return vowel.find(ch) != string::npos;
    }

    string sortVowels(string s) {
        int n = s.length();

        unordered_map<char, int>mp ; 
        for(int i = 0 ; i  < n; i++){
            if(isVowel(s[i])) mp[s[i]]++;
        }

        string vowel = "AEIOUaeiou";
        string result = s;  
        int j = 0 ;
        for(int i = 0 ; i < n; i++){
               if(isVowel(s[i])){
                  while(mp[vowel[j]] == 0 ) j++;
                  result[i] = vowel[j];
                  mp[vowel[j]]--;
               }

        } 

        return result;
    }
};