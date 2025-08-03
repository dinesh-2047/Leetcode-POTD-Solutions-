// 2106. Maximum Fruits Harvested After at Most K Steps
/*
⁉️ Problem Statement:
 🔸Given a 2D list fruits, where fruits[i] = [positionᵢ, amountᵢ] indicates amountᵢ fruits at positionᵢ.
 🔸 Also given a starting position startPos and an integer k representing the maximum number of steps you can take (left or right).
 🔸 The goal is to collect the maximum number of fruits within at most k steps.

🔎 My Approaches:
1️⃣ Sliding Window + Prefix Array (Range Scan)
 🔹 First, I created a prefix array (not prefixSum array ) to simulate fruit presence at each coordinate, since the maximum position constraint is small (~2e4).
 🔹 The valid search space is limited to [startPos - k, startPos + k] — because these are the only positions we can reach within k steps.
 🔹 I applied a sliding window from left to right across this range. At each step, I calculated the steps required to either:
 • go left first, then right, or
 • go right first, then left.
 🔹 If the total steps exceeded k, I moved the left pointer forward to shrink the window.
 🔹 I kept track of the maximum total fruits collected in a valid window.


2️⃣ Binary Search + Prefix Sum on Compressed Positions
 🔹 I extracted all fruit positions and sorted them. This helped in compressing the problem space and enabled efficient lookup.
 🔹 I built a prefix sum array on fruit quantities to quickly query total fruits between any two indices.
 🔹 For each possible left and right movement combination, I calculated the range of positions reachable in at most k steps.
 🔹 Then I used binary search (lower_bound and upper_bound) to find the indices corresponding to valid positions.
 🔹 Finally, using the prefix sum, I calculated the total number of fruits that could be collected for that valid window.

*/
// Approach 1 
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {

        int n = INT_MIN;

        for (auto& f : fruits) {
            int pos = f[0];
            n = max(n, pos);
        }

        vector<int> pa(n + 2, 0);

        for (auto& f : fruits) {
            int pos = f[0];
            int amount = f[1];

            pa[pos] = amount;
        }
       

        int i = max(0, startPos - k);
        int j = i;
        int range = min(n, startPos + k);

        int sum = 0;
        int result = 0;
        while (j <= range) {
            sum += pa[j];
            while (i <= j) {
                int leftFirst = abs(startPos - i) + (j - i);
                int rightFirst = abs(startPos - j) + (j - i);
                int minSteps = min(leftFirst, rightFirst);
                if (minSteps <= k)
                    break;
                sum -= pa[i];
                i++;
            }
            result = max(result, sum);
            j++;
        }
        return result; 
    }
};











//Approach 2 
#define all(x) begin(x), end(x)
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
         vector<int>pos;
         int n = fruits.size();
         for(auto &f : fruits){
            int p = f[0];
            pos.push_back(p);
         }

        vector<int>prefixSum(n);
        
        for(int i = 0 ; i < fruits.size();i++){
            prefixSum[i] = fruits[i][1] + (i-1 >= 0 ? prefixSum[i-1] : 0);
        }

        int result = 0 ; 

        for(int x = 0 ; x <= k/2; x++){
             int i = startPos - x ; 
             int j = startPos + (k - 2 * x);

             int left  = lower_bound(all(pos), i) - begin(pos);
             int right = upper_bound(all(pos), j) - begin(pos) - 1;
            
            if(left <= right){
             int sum = prefixSum[right] -( left - 1 >= 0 ?  prefixSum[left - 1] :0 ) ;
             result = max(result , sum);
            }

         
              j = startPos + x ; 
              i = startPos - (k - 2*x);

               left  = lower_bound(all(pos), i) - begin(pos);
             right = upper_bound(all(pos), j) - begin(pos) - 1;
            
            if(left <= right){
             int sum = prefixSum[right] -( left - 1 >= 0 ?  prefixSum[left - 1] :0 ) ;
             result = max(result , sum);
            }

        }
        return result; 
    }
};