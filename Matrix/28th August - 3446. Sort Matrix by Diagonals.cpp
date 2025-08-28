// 3446. Sort Matrix by Diagonals



// Approach 1 -> using map 
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>result(m , vector<int>(n));

        unordered_map<int , vector<int>>mp ; 

        for(int i = 0 ; i < m ;i++){
            for(int j = 0 ; j < n ;j++){
                    mp[i-j].push_back(grid[i][j]);
                
            }
        }

        for(auto &[key , vec] : mp){
            if(key >=0){
                sort(vec.rbegin(), vec.rend());
            }
            else{
                sort(vec.begin(), vec.end());
            }
               int k = 0 ; 
            for(int i = 0 ; i < m; i++){
                for(int j = 0 ; j < n;j++ ){
                      if(i-j == key ){
                           result[i][j] = vec[k++];
                      }
                }
            }
        }

      return result; 
    }
};





//approach 2 without map 
class Solution {
public:
int m , n ;
void refill(vector<int> &vec , vector<vector<int>> &grid , int row , int col ){
     int i = row ; 
     int j = col ; 
      int k = 0 ; 
     while(i < m && j < n ){
         grid[i][j] = vec[k++];
         i++;
         j++;
     }
     
}
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();

        for(int row = 0 ; row < m; row++){
              int i = row ; 
              int j = 0 ; 
              vector<int>vec; 
              while(i < m  && j < n ){
                   vec.push_back(grid[i][j]);
                   i++;
                   j++;
              }
              sort(rbegin(vec), rend(vec));
              refill(vec, grid, row, 0);
        }
        for(int col = 1 ; col < n ; col++ ){
            vector<int>vec; 
            int i = 0 ; 
            int j = col ; 
            while(i < m && j  < n ){
                vec.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(begin(vec),end(vec));
            refill(vec, grid, 0 , col);
        } 
        return grid; 
    }
};