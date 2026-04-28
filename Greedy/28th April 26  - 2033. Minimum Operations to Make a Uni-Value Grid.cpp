// 2033. Minimum Operations to Make a Uni-Value Grid

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

         vector<int> arr; 
         for(int i = 0 ; i  < m  ; i++){
            for(int j = 0 ; j  < n; j++){
                arr.push_back(grid[i][j]);
            }
         }

         sort(begin(arr), end(arr));
         int val = arr[(m * n)/2];
         cout<<val<<endl; 
         int result = 0;  
        for(int i = 0 ; i < m; i++){
            for(int j =0 ;j  < n ; j++){
                int diff = abs(grid[i][j] - val);
                int reqop =  diff/x; 
                if((reqop * x) != diff) return -1; 
                result += reqop;
            }
        }
        return result; 
    }
};