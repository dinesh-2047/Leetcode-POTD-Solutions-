// 1039. Minimum Score Triangulation of Polygon



// Approach 1 

class Solution {
public:
vector<vector<int>>dp; 
int solve(int i , int j , vector<int> &values){
    if(i + 1 == j ) return 0 ; 
    if(dp[i][j]!=-1) return dp[i][j];
    int result = INT_MAX;
    for(int k = i+ 1; k < j; k++){
        result = min(result , (values[i] * values[j] * values[k]) + solve(i, k , values) + solve(k , j , values));
    }
    return dp[i][j] =  result; 
}

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        dp.assign(n + 1, vector<int> (n + 1, -1));
        return solve(0, n-1, values);
    }
};










//Approach 2 
class Solution {
public:
    vector<vector<int>> dp;
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        dp.assign(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                int result = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    result = min(result, values[i] * values[j] * values[k] + dp[i][k] + dp[k][j]);
                }

                dp[i][j] = result;
            }
        }
    

    return dp[0][n - 1];
}
};
