// 3567. Minimum Absolute Difference in Sliding Submatrix

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>result(m-k+1, vector<int>(n-k+1)); 

       int size = min(m-k , n-k);
        for(int i = 0 ; i <= m-k; i++){
            for(int j = 0 ; j  <= n-k; j++){
                vector<int>vec; 
                for(int r = i ; r <i+k; r++){
                    for(int c = j ; c <j+k; c++){
                         vec.push_back(grid[r][c]);
                    }
                }
                sort(begin(vec), end(vec));
                int diff = INT_MAX; 
                for(int l =0 ; l < vec.size() - 1; l++){
                    if(vec[l] != vec[l + 1]){
                      int curr = abs(vec[l] - vec[ l + 1]);
                      diff = min(diff, curr);
                    }
                }
                result[i][j] = (diff == INT_MAX) ? 0 : diff; 
            }
        }
        return result; 
    }
};