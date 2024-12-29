class Solution {
public:
    int helper(vector<int>& subarray, int count, int i, int k, vector<vector<int>>& dp) {
        // Base case: if count reaches 0, we are done, return 0
        if (count == 0) return 0;

        // If index exceeds bounds, return INT_MIN (invalid state)
        if (i >= subarray.size()) {
            return INT_MIN;
        }

        // Memoization check
        if (dp[i][count] != -1) return dp[i][count];

        // Recursive calls: take or not take the current subarray
        int take = subarray[i] + helper(subarray, count - 1, i + k, k, dp);
        int nottake = helper(subarray, count, i + 1, k, dp);

        return dp[i][count] = max(take, nottake);
    }
    
    void solve(vector<int>& subarray, int count, int i, int k, vector<int>& result, vector<vector<int>>& dp) {
        // Base case: if count reaches 0, return
        if (count == 0) return;

        // If index exceeds bounds, return
        if (i >= subarray.size()) {
            return;
        }

        // Determine whether to take the current subarray
        int take_i = subarray[i] + helper(subarray, count - 1, i + k, k, dp);
        int not_take_i = helper(subarray, count, i + 1, k, dp);

        if (take_i >= not_take_i) {
            result.push_back(i); // Include the current index
            solve(subarray, count - 1, i + k, k, result, dp); // Move to the next valid position
        } else {
            solve(subarray, count, i + 1, k, result, dp); // Skip current index
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> subarray;
        int i = 0; 
        int j = 0;
        int windowSum = 0;

        // Sliding window to calculate sums of subarrays of size k
        while (j < nums.size()) {
            windowSum += nums[j];

            if (j - i + 1 == k) { // If window size is k
                subarray.push_back(windowSum); // Store the sum
                windowSum -= nums[i]; // Slide the window
                i++;
            }
            j++;
        }

        // Initialize dp table for memoization
        vector<vector<int>> dp(20001, vector<int>(4, -1));
        vector<int> result;

        // Solve the problem
        solve(subarray, 3, 0, k, result, dp);
        return result;
    }
};

/*
Time Complexity:
1. helper function:
   - Each state (i, count) is computed once and takes O(1) for recursive operations.
   - Total states = O(n * 3) = O(n).
   - Time for helper = O(n).

2. solve function:
   - Traverses the indices recursively. Each state uses helper function which takes O(1) after memoization.
   - Total calls = O(n).
   - Time for solve = O(n).

3. Sliding window for subarray sums:
   - Takes O(n) to calculate sums for all k-sized subarrays.

Overall Time Complexity: O(n) + O(n) + O(n) = O(n).

Space Complexity:
1. dp array:
   - Size = O(n * 4) = O(n).

2. Recursion stack:
   - Maximum depth = O(n) for solve.

Overall Space Complexity: O(n).
*/
