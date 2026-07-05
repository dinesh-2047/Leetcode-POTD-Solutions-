// 1301. Number of Paths with Max Score

class Solution {
public:
int n ; 
int maxi; 
int dp1[101][101];
int dp2[101][101][1774];
int mod = 1e9 + 7 ; 
int solve1(vector<string> &board, int i , int j ){
    if(i < 0 || j < 0 || i>=n || j>=n ||  board[i][j] == 'X' ) return -1e9; 
    if(board[i][j] == 'E' ){
        return 0; 
    }
    
      if(dp1[i][j]!=-1)  return dp1[i][j];

    int val = (board[i][j] == 'S') ? 0 : (board[i][j] - '0');
    int up = val + solve1(board, i-1, j);
    int left = val +  solve1(board, i, j - 1);
    int diag = val+ solve1(board, i - 1, j - 1);

    return dp1[i][j] =  max({up, left, diag})%mod;
}

int solve2(vector<string> &board, int i , int j, int sum){
    if(i < 0 || j < 0 || j >= n || i >= n ||  board[i][j] == 'X' ) return 0; 
    if(board[i][j] == 'E' && sum == maxi){
        return 1; 
    }

     if(dp2[i][j][sum]!=-1) return dp2[i][j][sum];

    int val = (board[i][j] == 'S') ? 0 : board[i][j] - '0';
    int up = solve2(board, i-1, j, sum + val );
    int left = solve2(board, i, j - 1, sum + val);
    int diag = solve2(board, i - 1, j - 1, sum + val);

    return dp2[i][j][sum] =  (up + left + diag)%mod; 

}

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
         memset(dp1, -1, sizeof(dp1));
         memset(dp2, -1, sizeof(dp2));
         maxi = solve1(board, n - 1 , n - 1);
        int paths = solve2(board, n - 1, n-1, 0);

        return {max(maxi, 0) , paths};
    }
};