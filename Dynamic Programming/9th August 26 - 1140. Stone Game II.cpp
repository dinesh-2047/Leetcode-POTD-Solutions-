// 1140. Stone Game II

class Solution {
public:
    int n;
    int dp[101][101][2];
    int solve(vector<int>& piles, int i, int m, int turn) {
        if (i >= n) {
            return 0;
        }
        if(dp[i][m][turn] !=-1) return dp[i][m][turn];
        int result = (!turn ? -1 : 1e9);
        int stones = 0 ;
        for (int x = 1; x <= 2 * m; x++) {
            if (i + x - 1 >= n)
                break;
            stones += piles[i + x - 1];
            if (!turn) {
                result = max(result, stones + solve(piles, i + x, max(m, x), 1));
            } else {
                result = min(result, solve(piles, i + x, max(m, x), 0));
            }
        }

        return dp[i][m][turn] =  result;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp, -1, sizeof(dp));
        return solve(piles, 0, 1, 0);
    }
};