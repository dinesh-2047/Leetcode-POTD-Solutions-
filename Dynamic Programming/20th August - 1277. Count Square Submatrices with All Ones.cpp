// 1277. Count Square Submatrices with All Ones


// Approach 1 -> prefix sum
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n =  matrix[0].size();

        vector<vector<int>>prefixSum(m, vector<int>(n + 1, 0));

        for(int i = 0 ; i < m; i++){
              for(int j = 0; j < n; j++){
                 prefixSum[i][j] += matrix[i][j];
                 if(i - 1 >= 0 ) prefixSum[i][j] += prefixSum[i-1][j];
                 if(j - 1 >=0 ) prefixSum[i][j] += prefixSum[i][j-1];
                 if(i - 1>=0 && j-1>=0 ) prefixSum[i][j] -= prefixSum[i-1][j-1];
              }
        }
           int count = 0 ; 

         for(int k = 1; k <= min(n, m); k++){
            for(int i = 0 ; i  < m-k + 1; i++){
                for(int j = 0 ; j < n - k + 1; j++ ){
                    
                    int r1 = i ; 
                    int c1 = j ; 
                    int r2 = i + k -1; 
                    int c2 = j  + k -1; 

                    int sum = prefixSum[r2][c2];
                    if(r1 - 1 >= 0 ) sum -= prefixSum[r1-1][c2];
                    if(c1 - 1 >=0 ) sum-=prefixSum[r2][c1-1];
                    if(r1-1 >= 0&& c1 - 1 >=0 ) sum += prefixSum[r1-1][c1-1];
                    if(sum == (k * k )) count++;
                }
            }
         }
         return count; 
    }
};







//Approach 2 - rec + memo
class Solution {
public:
int m , n ; 
vector<vector<int>> dp;
int solve(int i , int j , vector<vector<int>> &matrix){
    if(i >= m  ||  j>=n ) return 0; 
    if(matrix[i][j] == 0 ) return 0; 

    if(dp[i][j]!=-1) return dp[i][j];

    int right = solve(i, j  +1, matrix);
    int down = solve(i + 1, j , matrix);
    int diag = solve(i + 1, j + 1, matrix);

    return dp[i][j]  = 1 + min({right , down , diag});
} 


    int countSquares(vector<vector<int>>& matrix) {
         m = matrix.size();
         n = matrix[0].size();

        int result = 0 ; 
        dp.assign(m+1, vector<int>(n+1, -1));
        for(int i = 0 ;i < m; i++){
            for(int j = 0 ; j < n; j++){
                if(matrix[i][j]==1)
                result += solve(i , j , matrix);
            }
        }
        return result; 
    }
};








//Approach 3 - bottom up 
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m , vector<int> (n + 1, 0));
        int result= 0 ; 
        for(int i = 0 ; i < m;i++){
            for(int j = 0 ; j < n; j++){
                if( i== 0 || j==0){
                    dp[i][j] = matrix[i][j];
                }
                else if(matrix[i][j] == 1){
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
                result += dp[i][j];
            }
        }
        return result;
    }
};