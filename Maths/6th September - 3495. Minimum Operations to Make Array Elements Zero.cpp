// 3495. Minimum Operations to Make Array Elements Zero

/*
✨ LeetCode POTD: Minimum Operations to Make Array Elements Zero (3495) 📰

⁉️ Problem Statement:
🔸 You are given queries of the form [l, r].
🔸 For each query, you repeatedly perform operations on the range until all numbers become zero.
🔸 Task → Find the minimum number of operations required for all elements in the given ranges.

🔎 My Approach:
1️⃣ Range Partitioning into Segments
🔹 The solution relies on breaking down the range [l, r] into intervals of the form [L, R] where

L = 4^k and

R = 4^(k+1) - 1.
🔹 These intervals follow a pattern based on powers of 4.

🔹 For each segment that overlaps with [l, r], compute how many numbers it contributes.
🔹 Multiply this count by the current step S, which increases as we move deeper into the partition.
🔹 Accumulate steps for the entire range.

🔹 After calculating steps for a query, the answer is (steps + 1) / 2.
🔹 Sum across all queries to get the final result.

*/



class Solution {
public:
long long solve(int l , int r){
    long long L = 1; 
    long long steps = 0 ; 
    int S = 1; 

    while(L <= r){
        long long R = 4*L-1; 

        long long start = max(L,1LL * l);
        long long end = min(R,1LL * r);

        if(start <= end){
            steps += S *(end - start + 1); 
        } 
        S++;
        L*=4;
    }
    return steps ;

}

    long long minOperations(vector<vector<int>>& queries) {
        int n = queries.size();
        long long result = 0 ; 
        for(auto &query : queries){
            int l = query[0];
            int r = query[1];

            result += ((solve(l , r) +1)/2);
        }
        return result; 
    }
};