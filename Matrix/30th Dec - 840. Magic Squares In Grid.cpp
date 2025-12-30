// 840. Magic Squares In Grid


class Solution {
public:
bool isValid(int stRow, int stCol, vector<vector<int>> &grid){
    unordered_map<int , int>mp ; 
    for(int i = stRow; i < stRow + 3; i++){
        for(int j = stCol; j < stCol + 3; j++){
            if(grid[i][j] > 9  || grid[i][j] == 0 ) return false; 
            mp[grid[i][j]]++;
            if(mp[grid[i][j]] > 1) return false; 
        }
    }

    int SUM = 15;

    for(int i = stRow; i < stRow + 3; i++){
        int sum = 0 ; 
        for(int j = stCol; j < stCol + 3; j++){
            sum += grid[i][j];
        }
        if(sum != SUM) return false; 
    }


    for(int j = stCol; j < stCol + 3; j++){
        int sum = 0 ; 
        for(int i = stRow; i < stRow + 3; i++){
            sum += grid[i][j];
        }
        if(sum != SUM) return false; 
    }

      int diag1 = 0;
        for(int k = 0; k < 3; k++){
            diag1 += grid[stRow + k][stCol + k];
        }
       if(diag1 != SUM) return false; 
    int diag2 = 0 ; 
    int i = stRow + 2; 
          for(int j = stCol; j < stCol + 3; j++){
             diag2 += grid[i][j];
             i--;
          }
    

     if(diag2 != SUM) return false; 

    return true; 


}

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int result = 0 ; 

        for(int i = 0 ; i  < m-2; i++){
            for(int j = 0 ; j  < n-2; j++){
                if(isValid(i , j , grid)){
                    result++;
                }
            }
        }
        return result; 
    }
};