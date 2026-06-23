// Rat Maze With Multiple Jumps


class Solution {
public:
    bool solve(int i, int j, vector<vector<int>>& mat,
               vector<vector<int>>& ans,
               vector<vector<int>>& dp) {
        int n = mat.size();

        if (i == n - 1 && j == n - 1) {
            ans[i][j] = 1;
            return true;
        }

        if (mat[i][j] == 0)
            return false;

        if (dp[i][j] != -1)
            return dp[i][j] == 1;

        ans[i][j] = 1;
        int jump = mat[i][j];

        for (int step = 1; step <= jump; step++) {
            if (j + step < n && solve(i, j + step, mat, ans, dp)) {
                dp[i][j] = 1;
                return true;
            }

            if (i + step < n && solve(i + step, j, mat, ans, dp)) {
                dp[i][j] = 1;
                return true;
            }
        }

        ans[i][j] = 0;
        dp[i][j] = 0;
        return false;
    }

    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<vector<int>> ans(n, vector<int>(n, 0));

        if (n == 1) {
            ans[0][0] = 1;
            return ans;
        }

        if (mat[0][0] == 0)
            return {{-1}};

        vector<vector<int>> dp(n, vector<int>(n, -1));

        if (!solve(0, 0, mat, ans, dp))
            return {{-1}};

        return ans;
    }
};