// 3459. Length of Longest V-Shaped Diagonal Segment

// Approach 1 
// Rec
class Solution {
public:
int m , n ; 
vector<vector<int>>dir = {{1, 1}, {1, -1}, {-1, -1}, {-1 , 1}};
int solve(int i , int j , int d , bool canTurn , int value, vector<vector<int>> &grid){
    int newi =  i + dir[d][0];
    int newj = j  + dir[d][1];

    if(newi < 0 || newj < 0 || newi >=m || newj >=n || grid[newi][newj]!=value ) return 0; 

    int length = 0 ; 
    int move = 1 + solve(newi , newj , d, canTurn , value==2 ? 0 : 2, grid );
    length = max(length , move);
    if(canTurn){
        length = max(length, 1 + solve(newi , newj , (d+1)%4, false ,  value==2 ? 0 : 2 , grid));
    }
    return length;
}



    int lenOfVDiagonal(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();
         int result = 0 ; 
        for(int i= 0 ; i < m; i++){
            for(int j = 0 ; j  < n; j++){
                if(grid[i][j] == 1){
                   for(int d = 0 ; d < 4; d++){
                  
                     result = max(result , solve(i , j , d, true ,2 , grid) + 1);
                   }
                }
            }
        }
        return result; 
    }
};











//Approach 2 Rec+ memo
class Solution {
public:
int m , n ; 
vector<vector<int>>dir = {{1, 1}, {1, -1}, {-1, -1}, {-1 , 1}};
vector<vector<vector<vector<int>>>>dp; 
int solve(int i , int j , int d , bool canTurn , int value, vector<vector<int>> &grid){
    int newi =  i + dir[d][0];
    int newj = j  + dir[d][1];

    if(newi < 0 || newj < 0 || newi >=m || newj >=n || grid[newi][newj]!=value ) return 0; 

    if(dp[newi][newj][d][canTurn]!=-1) return dp[newi][newj][d][canTurn];
 
    int length = 0 ; 
    int move = 1 + solve(newi , newj , d, canTurn , value==2 ? 0 : 2, grid );
    length = max(length , move);
    if(canTurn){
        length = max(length, 1 + solve(newi , newj , (d+1)%4, false ,  value==2 ? 0 : 2 , grid));
    }
    return dp[newi][newj][d][canTurn] =  length;
}



    int lenOfVDiagonal(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();
         int result = 0 ; 

         dp.assign(m , vector<vector<vector<int>>>(n, vector<vector<int>>(4, vector<int>(2, -1))));
         
        for(int i= 0 ; i < m; i++){
            for(int j = 0 ; j  < n; j++){
                if(grid[i][j] == 1){
                   for(int d = 0 ; d < 4; d++){
                  
                     result = max(result , solve(i , j , d, true ,2 , grid) + 1);
                   }
                }
            }
        }
        return result; 
    }
};