// 1979. Find Greatest Common Divisor of Array


class Solution {
public:
    int findGCD(vector<int>& nums) {
        return gcd(ranges::max(nums), ranges::min(nums));
    }
};