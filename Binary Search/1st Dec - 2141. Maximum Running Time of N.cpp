// 2141. Maximum Running Time of N

class Solution {
public:
    bool isPossible(vector<int>& batteries, int& n, long long mid) {
        long long minutes = 0;
        for (int i = 0; i < batteries.size(); i++) {
            minutes += min(1LL * batteries[i], mid);
            if (minutes >= 1LL *n * mid)
                return true;
        }
        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long l = *min_element(begin(batteries), end(batteries))*1LL;
        long long r =  accumulate(begin(batteries), end(batteries), 0LL) / n;
        long long result = 0;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (isPossible(batteries, n, mid)) {
                result = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return result;
    }
};