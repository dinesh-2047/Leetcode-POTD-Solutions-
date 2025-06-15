// 1432. Max Difference You Can Get From Changing an Integer

/*
✨ LeetCode POTD: Max Difference You Can Get From Changing an Integer (1432) 🔢📈

⁉️ Problem Statement:
🔸 You are given a positive integer num.
🔸 You must apply the following operation exactly two times (independently):
 • Choose a digit x (0–9) and another digit y (0–9), then replace all occurrences of x in num with y.
 • None of the resulting numbers may have leading zeros or be equal to zero.
🔸 Let the two resulting numbers be a and b.
🔸 Return the maximum possible value of a – b. 


🔎 Approaches Used:

1️⃣ Brute-force All Digit Replacements
🔹 Convert num to string s.
🔹 Loop through all 100 combinations of (x, y) digits.
🔹 For each pair, replace all occurrences of x in s with y, skip if it causes leading zeros, convert back to integer.
🔹 Track the maximum and minimum transformed numbers found → answer = maxi – mini.
🔹 Complexity: O(100 × d) — fast enough since d (number of digits) ≤ 10.

2️⃣ Greedy Optimal Replacement (Your Code)
🔹 To maximize a: find the first non‑‘9’ digit (from left) and replace all its occurrences with ‘9’.
🔹 To minimize b:
 • If the first digit isn’t ‘1’, replace all its occurrences with ‘1’.
 • Otherwise, find the first digit beyond the first that isn’t ‘0’ or ‘1’, and replace all its occurrences with ‘0’.
🔹 Convert both results and compute a – b.
🔹 Complexity: O(d), very optimal and straightforward.

3️⃣ Using C++ STL replace for Conciseness
🔹 Convert num to strings s1 and s2 for a and b.
🔹 Use std::replace(...) to perform character replacements succinctly.
🔹 The logic mirrors the greedy approach, using STL for cleaner code.

*/

// Approach 1 
class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        int mini = num; 
        int maxi = num; 
        

        for(char x = '0' ; x <= '9'; x++){
            for(char y = '0'; y <= '9'; y++){
                string s1 = s; 
                for(char &c : s1){
                    if(c == x) c = y;
                }
                if(s1[0]=='0') continue; 
                maxi = max(maxi , stoi(s1));
                mini = min(mini , stoi(s1));
              
            }
        }

       
        return maxi - mini;
    }
};




//Approach 2 
class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int n = s.length();

        char x = '0';
        char y = '0';

        // For maximum number: replace first non-9 with 9
        for (int i = 0; i < n; i++) {
            if (s[i] != '9') {
                x = s[i];
                break;
            }
        }

        // For minimum number
        if (s[0] != '1') {
            y = s[0];  // Replace first digit with 1
        } else {
            for (int i = 1; i < n; i++) {
                if (s[i] != '0' && s[i] != s[0]) {
                    y = s[i];
                    break;
                }
            }
        }

        string s1 = s; 
        string s2 = s; 

        for (int i = 0; i < n; i++) {
            if (s1[i] == x) s1[i] = '9';
            if (s2[i] == y) {
             
                s2[i] = (y == s[0]) ? '1' : '0';
            }
        }

        return stoi(s1) - stoi(s2);
    }
};




//Approach 3 
class Solution {
public:
    int maxDiff(int num) {
        string s1 = to_string(num);
        string s2 = to_string(num);

        int n = s1.length();

        for(int i = 0 ;i <n; i++){
            if(s1[i]!='9'){
                char ch = s1[i];
                replace(s1.begin(), s1.end(), ch, '9');
                break;
            }
        }
             
         if (s2[0] != '1') {
            char ch = s2[0];
            replace(s2.begin(), s2.end(), ch, '1');
        } else {
            for (int i = 1; i < n; i++) {
                if (s2[i] != '0' && s2[i] != s2[0]) {
                    char ch  = s2[i];
                    replace(s2.begin(), s2.end(), ch, '0');
                    break;
                }
            }
        }

        return stoi(s1) - stoi(s2);
    }
};