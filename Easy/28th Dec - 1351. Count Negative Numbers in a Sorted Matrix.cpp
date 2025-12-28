// 1351. Count Negative Numbers in a Sorted Matrix


// Approach 1 brute force
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int result = 0; 

        for(int i = 0 ;i  < m; i++){
            for(int j = 0 ; j<n; j++ ){
                if(grid[i][j] < 0 ) result++;
            }
        }
        return result; 
    }
};






//Approach 2 using binary search 
class Solution {
public:


    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int result = 0 ; 
        for(auto &g : grid){
            int neg = n - (upper_bound(begin(g), end(g), 0, greater<int>())-begin(g));
            result += neg; 
        }
        return result; 
    }
};













//Approach 3 (m + n )
class Solution {
public:


    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int result = 0 ; 
        int row = m-1 ; 
        int col = 0 ; 

        while(row >= 0 && col < n ){
            if(grid[row][col] >= 0 ){
                col++;
            }
            else{
                result += n-col; 
                row--;
            }
        }
        return result;
    }
};