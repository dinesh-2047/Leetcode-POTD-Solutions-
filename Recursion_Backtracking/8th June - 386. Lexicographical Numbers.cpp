// 386. Lexicographical Numbers

/*
✨ LeetCode POTD: Lexicographical Numbers (386) 🔢🔤

⁉️ Problem Statement:
🔸 Given an integer n, return all the integers in the range [1, n] sorted lexicographically.
🔸 Return the result as a list of integers.

🔎 Approaches Used:

1️⃣ DFS (Depth-First Search) / Backtracking
🔹 Use DFS starting from digits 1 to 9 to build numbers in lex order.
🔹 At each step, multiply the current number by 10 and append digits 0 to 9 recursively, ensuring the number does not exceed n.
🔹 This efficiently generates lexicographical order without sorting.

2️⃣ Iterative Approach
🔹 Maintain a current number starting at 1.
🔹 At each iteration:
 • If current * 10 ≤ n, multiply current by 10 (go deeper in lex order).
 • Else if current + 1 ≤ n, increment current by 1 and remove trailing zeros (to skip invalid sequences).
 • Otherwise, backtrack by dividing current by 10 and incrementing, then remove trailing zeros again.
🔹 This simulates DFS traversal in an iterative way with O(n) time complexity.
*/



//Approach (Simple Recursion - DFS)
//T.C : O(n) - We visit each number (1 to n) only once.
//S.C : O(d) - where d is the number of digits in n i.e. log10(n)
class Solution {
public:

    void solve(int curr, int n, vector<int>& result) {
        if(curr > n)
            return;
        
        result.push_back(curr);

        for(int nextDigit = 0; nextDigit <= 9; nextDigit++) {
            int nextnum = curr*10 + nextDigit;
            
            if(nextnum > n)
                return;
            
            solve(nextnum, n, result);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> result;
        
        for(int num = 1; num <= 9; num++)
            solve(num, n, result);
        
        return result;
    }
};




// Approach 2 
class Solution {
public:
int removeZeros(int num){
    while(num%10==0){
          num/=10;
    }
    return num; 
}
    vector<int> lexicalOrder(int n) {
        vector<int>result; 
        int curr = 1; 
        result.push_back(curr);

        for(int i = 1 ;i  <n; i++){
            if(curr*10 <= n){
                curr*=10;
                result.push_back(curr);
            }
            else if(curr + 1<= n){
                curr += 1; 
                curr = removeZeros(curr);
                result.push_back(curr);
            }
            else if(curr + 1 >  n ){
                curr = curr/10 +1; 
                curr = removeZeros(curr );
                result.push_back(curr);
            }
        }
        return result; 
    }
};