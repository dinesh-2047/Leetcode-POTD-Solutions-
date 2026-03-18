// 3070. Count Submatrices with Top-Left Element and Sum Less Than k


class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int result = 0;
       
        vector<vector<int>> prefSum(m , vector<int>(n));

        for(int i = 0 ; i  < m; i++){
            for(int j = 0 ; j  < n; j++){
                prefSum[i][j] = grid[i][j];

                if(i - 1 >= 0 ){
                    prefSum[i][j] += prefSum[i-1][j];
                }

                if(j - 1 >= 0){
                    prefSum[i][j] += prefSum[i][j-1];
                }

                if(i -1 >= 0 && j-1 >= 0 ){
                    prefSum[i][j] -= prefSum[i-1][j-1];
                }
            }
        }

        for(int r = 0 ; r < m ; r++){
            for(int c = 0 ; c < n ; c++){
                int sum = prefSum[r][c];
                if(sum <= k) result++;
            }
        }

        return result;
    }
};