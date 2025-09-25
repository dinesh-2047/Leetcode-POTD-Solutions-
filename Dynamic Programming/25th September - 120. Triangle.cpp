// 120. Triangle



// Approach 1
class Solution {
public:
int n ; 
vector<vector<int>>dp;
int solve(vector<vector<int>> &triangle, int i , int j ){
    if(i>=n ) return 0 ; 

    if(dp[i][j]!=INT_MAX) return dp[i][j];

    int same = triangle[i][j] + solve(triangle, i + 1, j);
    int next = triangle[i][j] + solve(triangle , i + 1, j + 1);

    return dp[i][j] =  min(same, next);
}

    int minimumTotal(vector<vector<int>>& triangle) {
         n = triangle.size();
         dp.assign(n + 1, vector<int>(n + 1, INT_MAX));
        return solve(triangle, 0 , 0);
    }
};








//Approach 2 
class Solution {
public:
int n ; 
vector<vector<int>>dp;
    int minimumTotal(vector<vector<int>>& triangle) {
         n = triangle.size();
        dp = triangle; 
       

       for(int i = n-2; i>=0; i--){
          for(int j = 0 ; j <= i ; j++){
              dp[i][j] = dp[i][j] + min(dp[i+1][j], dp[i + 1][j + 1]);
          }
       }
       return dp[0][0];
    }
};





//Approach 3
class Solution {
public:
int n ; 
    int minimumTotal(vector<vector<int>>& triangle) {
         n = triangle.size();
     
       vector<int>dp = triangle[n-1];
       for(int i = n-2; i>=0; i--){
          for(int j = 0 ; j <= i ; j++){
              dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
          }
       }
       return dp[0];
    }
};