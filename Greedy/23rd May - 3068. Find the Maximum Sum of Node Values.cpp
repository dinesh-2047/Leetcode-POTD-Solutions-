// 3068. Find the Maximum Sum of Node Values/



/*
✨ LeetCode POTD: Find the Maximum Sum of Node Values (3068) 🚀

⁉️ Problem Statement:
🔸 Given an undirected tree with n nodes and an array nums representing node values, and a positive integer k.
🔸 Any number of operations can be performed where, for any edge [u, v], both nums[u] and nums[v] can be updated as:
  nums[u] = nums[u] ^ k
  nums[v] = nums[v] ^ k
🔸 Return the maximum possible sum of node values after applying any number of such operations.

🔎 Approaches Used:

1️⃣ Greedy XOR Evaluation with Odd-Even Count Logic
🔹 For each node, check if applying XOR with k increases its value.
🔹 If yes, include the XORed value in the sum and increment a counter.
🔹 If not, include the original value.
🔹 Track the minimum loss when choosing between original and XORed values.
🔹 If the count of XOR-used values is even, return the sum directly.
🔹 If it's odd, subtract the minimum loss to balance it out — ensuring the overall change involves an even number of XOR operations.

2️⃣ Profit-Based Greedy Pairing Approach
🔹 Calculate profit for each node: profit[i] = (nums[i] ^ k) - nums[i].
🔹 Sort profits in descending order to prioritize higher gains.
🔹 Iterate in pairs — only apply XOR to pairs where the combined profit is positive.
🔹 This ensures operations are applied in valid pairs (due to tree properties) and the sum is maximized.

*/






// Approach 1
#define ll long long 
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
   
        ll sum = 0 ; 
        ll count = 0 ; 
        ll miniNuksaan  = INT_MAX ; 
        for(int i = 0 ; i < n; i++){
            ll xorr = nums[i]^k;
          
            if(xorr > nums[i]){
                count++;
                sum += xorr; 
            }
            else {
                sum+=nums[i];
               
            }
               miniNuksaan = min(miniNuksaan , abs(nums[i]-xorr));
        }


        if(count%2==0) return sum; 

        else{
               return sum - miniNuksaan ; 
        }
    }
};




//Approach 2 
#define ll long long 
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
   
        ll sum = 0 ; 
        for(auto &num : nums) sum+= num; 

        vector<int>new_nums(n);
        vector<int>profit(n);

        for(int i = 0 ; i <n; i++){
            int xorr = nums[i]^k;
            new_nums[i] = xorr; 
            profit[i] = new_nums[i] - nums[i];
        }
        sort(profit.rbegin(), profit.rend());
        for(int i = 0 ; i<n-1; i+=2){
           int currProfit = profit[i] + profit[i+1];
           if(currProfit > 0) sum += currProfit; 
        }
        return sum; 
    }
};