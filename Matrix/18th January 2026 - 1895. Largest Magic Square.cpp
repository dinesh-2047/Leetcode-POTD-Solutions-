// 1895. Largest Magic Square


class Solution {
public:
bool isMagic(vector<vector<int>> &grid, int len , int i , int j){
    int target = 0 ; 
    for(int k = j; k  < j + len; k++) target += grid[i][k];

    for(int r = i + 1; r < i + len ; r++){
        int sum = 0 ; 
        for(int c = j ; c < j + len ; c++ ){
            sum += grid[r][c];
        }
        if(sum != target) return false; 
    }

    for(int c = j ; c < j + len ; c++){
        int sum = 0 ; 
        for(int r = i ; r < i + len ; r++){
            sum += grid[r][c];
        }
        if(sum != target) return false; 
    }

            int d1 = 0 ; 
            int d2 = 0 ; 

        for (int k = 0; k < len; k++) {
            d1 += grid[i + k][j + k];
            d2 += grid[i + k][j + len - 1 - k];
        }

        return d1 == target && d2 == target;
}

    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int result = 1; 

        for(int i = 0 ; i  < m ; i++){
            for(int j = 0 ; j  < n ; j++){
                for(int len = 2; i + len <= m && j + len <= n; len++ ){
                    if(isMagic(grid, len , i , j )){
                        result = max(result , len);
                    }
                }
            }
        }
        return result; 
    }
};