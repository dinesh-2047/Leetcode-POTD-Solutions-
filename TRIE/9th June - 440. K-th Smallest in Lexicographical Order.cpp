// 440. K-th Smallest in Lexicographical Order

/*
✨ LeetCode POTD: K-th Smallest in Lexicographical Order (440) 🔢📘

⁉️ Problem Statement:
🔸 Given two integers n and k, return the k-th smallest integer in the range [1, n] when sorted lexicographically.

🔎 Approach Used:

1️⃣ Prefix Counting with Lexicographical Tree Traversal (Trie Simulation)
🔹 Consider the range [1, n] as a lexicographical tree (similar to a prefix tree), where each node represents a number and its children are formed by appending digits 0–9.
🔹 Start from the current prefix curr = 1 and simulate moving through the tree:

Calculate how many numbers (nodes) exist between the current prefix and its next prefix using a helper countNum(curr, curr+1, n).

If the count is ≤ k, skip the entire subtree by moving to the next sibling (curr++).

If the count > k, go deeper into the subtree by appending a 0 (curr *= 10) and reduce k accordingly.
🔹 Repeat until you reach the k-th position.

tc - (log(n))^2

*/

class Solution {
public:
long long countNum(long long  curr, long long next , int n){
    long long count = 0 ; 

    while(curr <= n){
        count += (next - curr); 
        curr *= 10;
        next *= 10; 
        next = min(next, (long long)(n + 1));
    }
    return count; 
}

    int findKthNumber(int n, int k) {
        long long curr = 1; 
        k--;
        long long next = curr + 1; 

        while(k > 0 ){
           long long count = countNum(curr, next , n);

            if(count <= k){
                curr++;
                k-=count;  
            }
            else {
                curr *= 10;
                k-=1;
            }
            next = curr + 1;
        }
        return curr; 
    }
};