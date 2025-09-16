// 2197. Replace Non-Coprime Numbers in Array




/*

✨ LeetCode POTD: Replace Non-Coprime Numbers in Array (2197) 🔢

⁉️ Problem Statement:
🔸 You are given an integer array nums.
🔸 Replace adjacent non-coprime numbers (GCD > 1) with their LCM and continue this process until no more replacements are possible.
🔸 Return the final array after performing all replacements.

🔎 My Approaches:

1️⃣ Simplified Continuous Merge
🔹 Directly push elements into the result vector.
🔹 After each insertion, check the last two elements.
🔹 If they share a GCD > 1, merge them into their LCM, pop both, and push back the merged result.
🔹 Repeat until stable.

2️⃣ Stack-Based Merge
🔹 Use a stack to store numbers while traversing the array.
🔹 For each new number, push into the stack and check the top two elements.
🔹 If GCD > 1, pop both and push their LCM.
🔹 At the end, reverse the stack to get the final array.




*/




// Approach 1 

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();

        vector<int> result;

        for (int i = 0; i < n; i++) {
                 result.push_back(nums[i]);
             while (result.size() > 1 && gcd(result[result.size() - 1], result[result.size() - 2]) > 1) {
                int newLcm = lcm(result.back(), result[result.size() - 2]);
                result.pop_back();
                result.pop_back();
                result.push_back(newLcm);
            }
           
        }
        return result;
    }
};















//Approach 2 
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();

        vector<int> result;
        stack<int> st;

        for (int i = 0; i < n; i++) {
             st.push(nums[i]);
            while (st.size() > 1) {
                int first = st.top();
                st.pop();

                int second = st.top();
                st.pop();
                if (gcd(first, second) > 1) {
                    int newLcm = lcm(first, second);
                    st.push(newLcm);
                } else {
                    st.push(second);
                    st.push(first);
                  
                    break;
                }
            }

           
        }

     
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
         reverse(begin(result), end(result));
         return result; 
    }
};