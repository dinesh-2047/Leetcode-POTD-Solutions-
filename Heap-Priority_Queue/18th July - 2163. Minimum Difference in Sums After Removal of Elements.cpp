// 2163. Minimum Difference in Sums After Removal of Elements

/*
✨ LeetCode POTD: Minimum Difference in Sums After Removal of Elements (2163) 🔢📊

⁉️ Problem Statement:
🔸 You are given a 0-indexed integer array nums consisting of 3 * n elements.
🔸 You must remove exactly n elements from the array.
🔸 The remaining 2 * n elements are split into two parts:
• The first part consists of the first n elements
• The second part consists of the last n elements
🔸 Return the minimum possible value of sum(first part) - sum(second part)

🔎 Approach I Used:

1️⃣ Heap-Based Prefix & Suffix Sum Construction

🔹 Traversed the first 2n elements from left to right
🔹 Maintained a max-heap to keep track of the smallest n elements
🔹 At each step:
• Added current element to a running sum
• If heap size exceeded n, popped the largest element and subtracted it from the sum
🔹 Stored the resulting sum in prefixSum[i]

🔹 Traversed the last 2n elements from right to left
🔹 Used a min-heap to maintain the largest n elements
🔹 At each step:
• Added current element to a running sum
• If heap size exceeded n, popped the smallest element and subtracted it from the sum
🔹 Stored the resulting sum in suffixSum[i]

🔹 Iterated over all possible split points i from n-1 to 2n-1
🔹 For each valid i, calculated:
• prefixSum[i] - suffixSum[i + 1]
🔹 Took the minimum of all such differences to get the final answer
*/

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size();

        int n = N / 3;

        vector<long long> prefixSum(N); // for first part min Sum
        vector<long long> suffixSum(N); // for second part maxSum

        priority_queue<int> maxHeap;

        long long sum = 0;
        for (int i = 0; i < 2 * n; i++) {
            sum += nums[i];
            maxHeap.push(nums[i]);

            if (maxHeap.size() > n) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }

            prefixSum[i] = sum;
        }

        sum = 0;
        priority_queue<int, vector<int>, greater<>> minHeap;
        for (int i = N - 1; i >= n; i--) {
            sum += nums[i];
            minHeap.push(nums[i]);

            if (minHeap.size() > n) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            suffixSum[i] = sum;
        }

        long long result = LLONG_MAX;
        for (int i = n - 1; i < N - n; i++) {
            result = min(result, prefixSum[i] - suffixSum[i + 1]);
        }

        return result;
    }
};