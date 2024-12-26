// RECURSION CODE 

int solveRecursive(vector<int>& nums, int index, int currentSum, int target) {
    // Base Case: When we've processed all the elements
    if (index == nums.size()) {
        if (currentSum == target) return 1; // Valid way found
        else return 0; // Not a valid way
    }

    // Recursive Step:
    // Option 1: Add the current element to the sum
    int plus = solveRecursive(nums, index + 1, currentSum + nums[index], target);
    // Option 2: Subtract the current element from the sum
    int minus = solveRecursive(nums, index + 1, currentSum - nums[index], target);

    // Return the total number of ways
    return plus + minus;
}

// Main function to find the number of ways to achieve the target sum
int findTargetSumWays(vector<int>& nums, int target) {
    return solveRecursive(nums, 0, 0, target);
}





//RECURSION + MEMORIZATION CODE 
int solveMem2(vector<int>& nums, int index, int currentSum, int target, vector<vector<int>>& dp, int sum) {
    // Base Case: When we've processed all the elements
    if (index == nums.size()) {
        // If the current sum equals the target, we found a valid way
        if (currentSum == target) return 1;
        else return 0; // Otherwise, it's not a valid way
    }
    
    // Check if the result is already computed (Memoization)
    // Use (currentSum + sum) to map the sum into a valid index range [0, 2*sum]
    if (dp[index][currentSum + sum] != -1) 
        return dp[index][currentSum + sum];

    // Recursive Step:
    // Option 1: Add the current element to the sum
    int plus = solveMem2(nums, index + 1, currentSum + nums[index], target, dp, sum);
    // Option 2: Subtract the current element from the sum
    int minus = solveMem2(nums, index + 1, currentSum - nums[index], target, dp, sum);

    // Store the result in dp table and return it
    return dp[index][currentSum + sum] = (plus + minus);
}

// Main function to find the number of ways to achieve the target sum
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();

    // Calculate the sum of all elements in the array
    int sum = accumulate(begin(nums), end(nums), 0);

    // Edge Case: If target is not reachable within the range [-sum, sum]
    if (abs(target) > sum) return 0;

    // Create a dp table with dimensions [n][2*sum + 1], initialized to -1
    // The range of valid currentSum values is [-sum, sum], so we need to shift indices by 'sum'
    vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, -1));

    // Call the helper function with initial parameters
    return solveMem2(nums, 0, 0, target, dp, sum);
}