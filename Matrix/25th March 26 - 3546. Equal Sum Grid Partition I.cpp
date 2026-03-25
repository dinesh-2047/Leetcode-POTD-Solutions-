// 3546. Equal Sum Grid Partition I

class Solution {
public:
    using ll = long long;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        ll cumSum = 0 ; 
        for(int i = 0 ; i  < m; i++){
            for(int j = 0 ; j< n; j++){
                cumSum += grid[i][j];
            }
        }

        if(cumSum % 2 != 0 ) return false; 
        
        ll sum = 0 ; 
        for(int i = 0 ; i < m - 1; i++){
            for(int j = 0 ; j< n; j++){
                  sum += grid[i][j];
            }

            if(sum == cumSum/2) return true; 
        }
        sum = 0 ; 
        for(int j = 0 ;j  < n- 1; j++){
            for(int i = 0 ; i < m ; i++){
                 sum += grid[i][j];
            }
            if(sum == cumSum/2) return true; 
        }
         return false; 
    }
};