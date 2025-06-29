// 1498. Number of Subsequences That Satisfy the Given Sum Condition





/*
✨ LeetCode POTD: Number of Subsequences That Satisfy the Given Sum Condition (1498) 🔢📊

⁉️ Problem Statement (LeetCode):
🔸 You are given an integer array nums and an integer target.
🔸 Count the number of non-empty subsequences such that the sum of the minimum and maximum elements in the subsequence is less than or equal to target.
🔸 Return the result modulo 10⁹ + 7.

🔎 Approach I Used (C++):

▶️ Two Efficient Methods Using Sorting, Binary Search, and Fast Power

🔹 Approach 1: Two-Pointer Technique + Fast Exponentiation
• First, sort the array to bring structure for min/max comparisons.
• Initialize two pointers i = 0 and j = n - 1.
• While i <= j, check if nums[i] + nums[j] ≤ target:
 – If yes, then all elements between i and j can form valid subsequences with nums[i] as min and nums[j] as max.
 – Count these as 2^(j - i) and add to result.
 – Move the left pointer i++.
• Else, decrease j to reduce the max element.
• Use a custom findPower() function to compute powers modulo 1e9+7 efficiently using fast binary exponentiation.

🔹 Approach 2: Binary Search (upper_bound) + Sliding Window
• Sort the array.
• For each index i, find the first index j where nums[i] + nums[j] > target using upper_bound.
• If j > i, then all subsequences formed by nums[i] and elements between i and j - 1 are valid.
• The count is 2^(j - i - 1).
• Accumulate this in the result using the same fast power function.


*/










// Approach 1 Two pointer 

class Solution {
public:
int mod = 1e9 + 7;
int findPower(long long a , long long b){
    if(b == 0) return 1; 

    long long half = findPower(a , b/2)%mod;
    long long result = (half * half)%mod; 

     if(b%2==1){
        result = (result * a)%mod; 
     }
     return result%mod; 
}


    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();

        int i = 0 ; 
        int j = n-1 ; 
        sort(begin(nums), end(nums));
        int result = 0 ; 

       

        while(i<=j){

            if(nums[i] + nums[j] <= target ){
                result =( result +  findPower(2, j-i)%mod)%mod;
                i++;
            }
           else j--;
            
            
           
        }
        return result; 
    }
};










// Approach 2 Binary Search  + Two pointer 
class Solution {
public:
int mod = 1e9 + 7;
int findPower(long long a , long long b){
    if(b == 0) return 1; 

    long long half = findPower(a , b/2)%mod;
    long long result = (half * half)%mod; 

     if(b%2==1){
        result = (result * a)%mod; 
     }
     return result%mod; 
}


    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();

        int i = 0 ; 
        int j = n-1 ; 
        sort(begin(nums), end(nums));
        int result = 0 ; 

       

       for(int i = 0 ;i <n; i++){
          int j = upper_bound(begin(nums), end(nums), target-nums[i]) - begin(nums);
          if(j<=i)break; 

          result = (result + findPower(2, j-i-1)%mod)%mod;
       }
           
        
        return result; 
    }
};