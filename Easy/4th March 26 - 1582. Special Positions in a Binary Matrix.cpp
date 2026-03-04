// 1582. Special Positions in a Binary Matrix

class Solution {
public:
int m , n ; 
bool isSpecial(vector<vector<int>> &mat, int i , int j){
    
    for(int col = 0 ; col < n; col++){
        if(col == j ) continue; 
        if(mat[i][col] == 1) return false; 
    }

    for(int row = 0 ; row < m; row++){
        if(row == i) continue; 
        if(mat[row][j] == 1) return false; 
    }
    return true; 
}

    int numSpecial(vector<vector<int>>& mat) {
         m = mat.size();
         n = mat[0].size();

         int result = 0 ; 

         for(int i = 0 ; i  < m; i++){
            for(int j = 0 ; j < n; j++){
                if(mat[i][j] == 1){
                    if(isSpecial(mat, i , j)){
                        result++;
                    }
                }
            }
         }

    return result; 
    }
};