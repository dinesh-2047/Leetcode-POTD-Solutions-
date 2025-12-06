// 3578. Count Partitions With Max-Min Difference at Most K

class Solution {
public:
    int mod = 1e9 + 7;
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        vector<int> pref(n + 1, 0);

        dp[0] = 1;
        pref[0] = 1;

        deque<int> minDq;
        deque<int> maxDq;

        int i = 0;
        int j = 0;

        while (j < n) {
            while (!maxDq.empty() && nums[j] > nums[maxDq.back()]) {
                maxDq.pop_back();
            }

            maxDq.push_back(j);
            while (!minDq.empty() && nums[j] < nums[minDq.back()]) {
                minDq.pop_back();
            }

            minDq.push_back(j);

            while (i <= j && nums[maxDq.front()] - nums[minDq.front()] > k) {
                i++;

                if (!maxDq.empty() && maxDq.front() < i)
                    maxDq.pop_front();
                if (!minDq.empty() && minDq.front() < i)
                    minDq.pop_front();
            }

            dp[j + 1] = (pref[j] - (i > 0 ? pref[i - 1] : 0) + mod) % mod;
            pref[j + 1] = (pref[j] + dp[j + 1]) % mod;
            j++;
        }

        return dp[n];
    }
};