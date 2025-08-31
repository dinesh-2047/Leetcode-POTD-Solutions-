// 37. Sudoku Solver


class Solution {
public:
bool isValid(vector<vector<char>>&board, char num, int row , int col){
    //row and col check 
    for(int i =0  ; i < 9 ; i++){
        if(board[i][col] == num) return false;
        if(board[row][i] == num) return false; 
    }
     //3*3 box check 

      int stRow = row/3 * 3; 
      int stCol = col/3 * 3; 
      for(int i = stRow ; i < stRow + 3; i++){
        for(int j = stCol ; j < stCol + 3; j++){
            if(board[i][j] == num) return false; 
        }
      }


     return true; 

}



bool solve(vector<vector<char>>&board){
    for(int i  =0 ; i < 9; i++){
        for(int j = 0 ; j  < 9; j++){
            if(board[i][j] != '.') continue; 
            else{
                for(int val = 1; val <= 9; val++){
                   char num = val + '0';
                    if(isValid(board, num, i , j)){
                        board[i][j] =  num; //do
                       if( solve(board)) return true;//explore
                        board[i][j] = '.';//undo
                    }
                }
                return false; 
            }
        }
    }
    return true; 
}

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};