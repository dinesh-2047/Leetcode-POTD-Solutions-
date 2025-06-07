// 3170. Lexicographically Minimum String After Removing Stars

/*
✨ LeetCode POTD: Lexicographically Minimum String After Removing Stars (3170) 🌟🔤

⁉️ Problem Statement:
🔸 Given a string s containing lowercase English letters and stars '*'.
🔸 Each star deletes the closest non-star character to its left, along with itself.
🔸 Return the lexicographically smallest string possible after removing all stars and their corresponding characters.

🔎 Approaches Used:
// Intuition :
To always remove the smallest character to the left of a *, we maintain a min-heap (priority queue) that stores characters along with their negative indices to track position (and prioritize earlier characters in case of ties).

1️⃣ Priority Queue and Index Tracking
🔹 Iterate over the string from left to right.
🔹 If the character is not '', push it into a min-heap (priority queue) with its negative index to prioritize earlier characters.
🔹 If the character is '', pop the top of the heap — the smallest character so far — and mark its index for deletion.
🔹 After processing the entire string, rebuild the result by skipping characters that were marked for deletion.
*/




class Solution {
public:
    string clearStars(string s) {
        int n = s.length();

        priority_queue<pair<char ,int> , vector<pair<char , int>>, greater<>>pq; 

        for(int i = 0 ; i <n; i++){
            if(s[i] == '*'){
                if(!pq.empty()){
                    auto curr = pq.top();
                    char ch = curr.first ; 
                    int idx = curr.second*-1; 
                    pq.pop();a

                    s[idx] = '*';
                }
            }
            else pq.push({s[i],i*-1});
        }
           
           string result = "";
        for(int i = 0 ; i <n; i++){
            if(s[i]!='*') result.push_back(s[i]);
        }
        return result; 
    }
};