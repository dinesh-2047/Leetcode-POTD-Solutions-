// 1695. Maximum Erasure Value


class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        int i = 0;
        int j = 0;

        int maxSum = 0;
        int sum = 0;

        while (j < n) {
            mp[nums[j]]++;
            sum += nums[j];

            while (mp[nums[j]]!=1) {

                sum -= nums[i];
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            maxSum = max(maxSum, sum);

            j++;
        }

        return maxSum;
    }
};