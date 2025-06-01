// 2929. Distribute Candies Among Children II


/*
✨ LeetCode POTD: Distribute Candies Among Children II (2929) 🍬👧👦
⁉️ Problem Statement
🔸 You are given two integers: n (total candies) and limit (max candies a child can receive).
🔸 Distribute n indistinguishable candies among 3 children such that no child gets more than limit candies.
🔸 Return the total number of valid distributions.

🔎 Approaches Used:

1️⃣ Recursive Approach (❌ Gives TLE)
🔹 Try assigning all possible values (0 to limit) to each child recursively.
🔹 Base case: when all 3 children are assigned and candies are exhausted, count as a valid way.
🔹 Time complexity is high due to exponential branching.

2️⃣ Brute Force Using 3 Loops (❌ Gives TLE)
🔹 Iterate all combinations of ch1, ch2, ch3 from 0 to limit.
🔹 If their sum is exactly n, count as one valid way.
🔹 Simple and readable but inefficient.

3️⃣ Optimized 2 Loops (❌ Still TLE on edge cases)
🔹 Loop over ch1 and ch2, and calculate ch3 = n - ch1 - ch2.
🔹 Check if ch3 is within [0, limit].
🔹 Reduces complexity but still not efficient enough.

4️⃣ Final Efficient Approach ✅
🔹 Fix ch1 from max(0, n - 2*limit) to min(n, limit).
🔹 Remaining candies = n - ch1 → must split between ch2 and ch3 within the limit.
🔹 For this range, count valid pairs (ch2, ch3) using simple bounds.
🔹 This reduces complexity drastically and passes all test cases.

🔹 This progression shows the importance of moving from brute-force → optimized → combinatorial reasoning.
*/




// Approach 1 /
class Solution {
public:
long long solve(int children , int n , int limit){
    if(children == 3){
        if(n==0) return 1; 
        else return 0 ; 
    }

    int ways = 0 ; 
    for(int assign = 0 ; assign <= limit ; assign++){
        ways += solve(children+1, n-assign, limit);
    }
    return ways;
}

    long long distributeCandies(int n, int limit) {
        return solve(0, n , limit);
    }
};




//Approach 2 
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0 ; 

        for(int ch1 = 0 ; ch1 <= min(n, limit); ch1++){
            for(int ch2 = 0 ; ch2 <= min(n, limit); ch2++){
                for(int ch3 = 0 ; ch3<=min(n, limit); ch3++){
                    if(ch1 + ch2 + ch3  == n ) ways++;
                }
            }
        }
        return ways; 
    }
};






//Approach3 
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0 ; 

        for(int ch1 = 0 ; ch1 <= min(n, limit); ch1++){
            for(int ch2 = 0 ; ch2 <= min(n, limit); ch2++){
                int ch3 = n- ch1 - ch2;
                if (ch3 >= 0 && ch3 <= limit) {
                    ways++;
                }
            }
        }
        return ways; 
    }
};






//Approach 4 

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0 ; 

        for(int ch1 =max(0, n - 2 * limit) ; ch1 <= min(n, limit); ch1++){ //assign candies to first children 

          //2 children case 
            int leftCandies = n - ch1; 

            int low = max(0,leftCandies - limit); 
            int high = min(leftCandies, limit); 
           
          
            ways += (high - low+1);
        }
        return ways; 
    }
};