// 898. Bitwise ORs of Subarrays

/*

✨ LeetCode POTD: Bitwise ORs of Subarrays (898) 🧠

⁉️ Problem Statement:
🔸 You are given an integer array arr.
🔸 For every non-empty contiguous subarray, compute the bitwise OR of its elements.
🔸 Return the number of distinct OR results obtained across all subarrays.
A “subarray” is a contiguous slice of the original array, and duplicates of OR results are counted once.


🔎 My Approach:
1️⃣ Set-Based Dynamic Propagation ⠀
🔹 Maintain two sets:
• prev – stores OR results of subarrays ending at the previous index
• curr – stores OR results of subarrays ending at the current index (i)
🔹 For each arr[i]:
• For each x in prev, compute x | arr[i] and insert into both curr and result sets
• Also insert arr[i] itself into both sets to account for subarrays starting at i
🔹 At the end of iteration, set prev = curr to continue the flow

🕒 Why the time complexity is O(n × 32):
🔹 Although we use nested iteration, each OR result can only set new bits, never unset them. With 32-bit integers, each number creates at most 32 new OR values.
🔹 Hence across n elements, total work ≈ O(n × 32), which is effectively O(n) in practice.

💡 Time Complexity: O(n × 32)
📌 Space Complexity: O(n) 
*/



class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        
        unordered_set<int>result; 
        unordered_set<int>prev ; 

        for(int i = 0 ; i < n; i++){
            unordered_set<int>curr;
            for(auto &x : prev){
                curr.insert(x | arr[i]);
                result.insert(x | arr[i]);
            }
            curr.insert(arr[i]);
            result.insert(arr[i]);
            prev = curr; 
        }
       return result.size();
    }
};