// Partition Equal Subset Sum  416 


class Solution {
    public:
        int n;
        int target;
    
        // Approach 1: Recursive + Memoization (Top-Down DP)
        bool solve(vector<int> &nums, int i, int sum, vector<vector<int>> &dp) {
            if(i == n) return false;           // Base case: no elements left
            if(sum > target) return false;     // Sum exceeds target
            if(sum == target) return true;     // Found a valid subset
            
            if(dp[i][sum] != -1) return dp[i][sum];  // Return memoized result
            
            bool take = solve(nums, i+1, sum + nums[i], dp);    // Include current element
            bool not_take = solve(nums, i+1, sum, dp);         // Exclude current element
            
            return dp[i][sum] = take or not_take;    // Store and return result
        }
        
        // Time Complexity: O(n * target) - Each state is computed once
        // Space Complexity: O(n * target) - For the dp table + recursion stack
        bool canPartition1(vector<int>& nums) {
            n = nums.size();
            int cumSum = accumulate(nums.begin(), nums.end(), 0);
            if(cumSum % 2 == 1) return false;    // If sum is odd, can't be partitioned
            target = cumSum/2;
            vector<vector<int>> dp(n+1, vector<int>(target + 1, -1));
            return solve(nums, 0, 0, dp);
        }
    
        // Approach 2: Bottom-Up DP (Tabulation)
        // Time Complexity: O(n * target) - Two nested loops
        // Space Complexity: O(n * target) - For the 2D dp table
        bool canPartition2(vector<int>& nums) {
            n = nums.size();
            int cumSum = accumulate(nums.begin(), nums.end(), 0);
            if(cumSum % 2 == 1) return false;
            target = cumSum/2;
            vector<vector<int>> dp(n+1, vector<int>(target + 1, false));
            
            for(int i = 1; i <= n; i++) {
                for(int j = 0; j <= target; j++) {
                    if(j == 0) dp[i][j] = true;    // Empty subset gives sum 0
                    else if(j >= nums[i-1]) {
                        dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];  // Take or not take
                    }
                    else dp[i][j] = dp[i-1][j];    // Can't take current element
                }
            }
            return dp[n][target];
        }
    
        // Approach 3: Space Optimized DP (Using 2 1D arrays)
        // Time Complexity: O(n * target) - Two nested loops
        // Space Complexity: O(target) - Only two 1D arrays used
        bool canPartition3(vector<int>& nums) {
            n = nums.size();
            int cumSum = accumulate(nums.begin(), nums.end(), 0);
            if(cumSum % 2 == 1) return false;
            target = cumSum/2;
            vector<bool> curr(target+1, false);
            vector<bool> prev(target+1, false);
            
            for(int i = 1; i <= n; i++) {
                for(int j = 0; j <= target; j++) {
                    if(j == 0) curr[j] = true;    // Empty subset gives sum 0
                    else if(j >= nums[i-1]) {
                        curr[j] = prev[j-nums[i-1]] || prev[j];    // Take or not take
                    }
                    else curr[j] = prev[j];    // Can't take current element
                }
                prev = curr;    // Update prev for next iteration
            }
            return prev[target];
        }
    
        // Approach 4: Most Optimized DP (Single 1D array)
        // Time Complexity: O(n * target) - Two nested loops
        // Space Complexity: O(target) - Single 1D array
        bool canPartition(vector<int>& nums) {
            n = nums.size();
            int cumSum = accumulate(nums.begin(), nums.end(), 0);
            if(cumSum % 2 == 1) return false;
            target = cumSum/2;
            vector<int> dp(target+1, false);
            dp[0] = true;    // Base case: sum 0 is always possible
            
            for(int i = n-1; i >= 0; i--) {
                for(int j = target; j >= nums[i]; j--) {
                    dp[j] = dp[j-nums[i]] || dp[j];    // Update if current element can contribute
                }
            }
            return dp[target];
        }
    };
    