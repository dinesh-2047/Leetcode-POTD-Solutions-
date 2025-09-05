// 2749. Minimum Operations to Make the Integer Zero

/*
✨ LeetCode POTD: Minimum Operations to Make the Integer Zero (2749) 
📰

⁉️ Problem Statement:
 🔸 You are given two integers num1 and num2.
 🔸 In one operation, you can choose an integer i (0 ≤ i ≤ 60) and subtract 2^i + num2 from num1.
 🔸 The task is to find the minimum number of operations required to make num1 equal to 0.
 🔸 If it is impossible, return -1.

🔎 My Approach:
 👉 Observation
 🔹 Each operation decreases num1 by num2 and adds a power of 2.
 🔹 This can be restructured as: after k operations → num1 - k * num2 must equal the sum of k powers of 2.
 🔹 Let target = num1 - k * num2.
 🔹 For a solution to exist → target >= k (since the smallest sum of k powers of 2 is k).
 🔹 The sum of k powers of 2 can represent target if and only if popcount(target) ≤ k ≤ target.
 🔹 Here, popcount(target) is the number of set bits in the binary representation of target.

1️⃣Approach 1 : 
 🔹 Iterate over possible k from 1 .
 🔹 For each, check if target >= k and popcount(target) ≤ k.
 🔹 The smallest valid k is the answer.

🔹 Since num1 decreases with k * num2, iterating up to ~35 steps is enough (as larger k will exceed limits).



*/



// Approach 1 
class Solution {
public:

    int makeTheIntegerZero(int num1, int num2) {
        if(num1 <=  num2) return  -1;

        for(int k = 1 ; k <= 35; k++){
            long long target =  1LL * num1 - 1LL * k *num2;
            if(target >= k && __builtin_popcountll(target) <= k ) return k; 
        }
        return -1;

    }
};











//Approach 2 
class Solution {
public:

    int makeTheIntegerZero(int num1, int num2) {
        if(num1 <=  num2) return  -1;

     int k = 1; 
       while(1){
          long long target = 1LL * num1 - 1LL * k *num2; 
          if(target < 0) return -1; 
          if(target >=k && __builtin_popcountll(target) <= k){
             return k ;
          }
          k++;
       }
       return  -1; 

    }
};