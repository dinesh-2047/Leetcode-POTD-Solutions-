// 3689. Maximum Total Subarray Value I

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        int mini = *min_element(begin(nums), end(nums));
        int maxi = *max_element(begin(nums), end(nums));

        return 1LL * k * (maxi - mini);
    }
};