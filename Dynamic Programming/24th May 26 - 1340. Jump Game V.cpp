// 1340. Jump Game V

class Solution {
public:
    int n;
    vector<int> dp; 
    int solve(vector<int>& arr, int d, int i) {
        if (i >= n) {
            return 0;
        }
       if(dp[i]!=-1) return dp[i];
        int f = 0;
        int b = 0;
        for (int x = 1; x <= d; x++) {
            if (i + x >= n)
                break;
            int j = i + x;
            if (arr[i] <= arr[j])
                break;
            f = max(f, solve(arr, d, j));
        }

        for (int x = 1; x <= d; x++) {
            if (i - x < 0)
                break;
            int j = i - x;
            if (arr[i] <= arr[j])
                break;
            b = max(b, solve(arr, d, j));
        }

        return dp[i] = 1 + max(f, b);
    }
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        dp.assign(n + 1, -1);
        int result = 0;
        for (int i = 0; i < n; i++) {
            result = max(result, solve(arr, d, i));
        }
        return result;
    }
};