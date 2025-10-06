// 778. Swim in Rising Water



// Approach 1 -> dfs
class Solution {
public:
int m , n ; 
vector<vector<int>>directions = {{0, 1}, {0 ,-1}, {1, 0}, {-1, 0}};
bool dfs(int i , int j , vector<vector<int>> &grid, vector<vector<bool>> &visited, int mid){

    if(i >= m || j >= n || i < 0 || j < 0 || visited[i][j] || grid[i][j] > mid) return false; 
      visited[i][j] = true; 
      if(i == m-1 && j == n-1) return true; 
      for(auto &dir : directions){
         int newi = i + dir[0];
         int newj = j + dir[1];

         if(dfs(newi , newj , grid, visited, mid)) return true; 
      }
      return false; 
}



bool isPossible(vector<vector<int>> &grid, int mid){
    vector<vector<bool>>visited(m , vector<bool>(n , false));
    return dfs(0 , 0 ,grid , visited, mid );
}

    int swimInWater(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int l = 0 ; 
        int r = n * n - 1; 
        int result = 0 ; 

        while(l <= r){
            int mid = l + (r - l)/2; 

            if(isPossible(grid, mid)){
                result = mid; 
                r = mid - 1; 
            }
            else l = mid + 1; 
        }
        return result; 
    }
};












//Approach 2 -> bfs
class Solution {
public:
int m , n ; 
vector<vector<int>>directions = {{0, 1}, {0 ,-1}, {1, 0}, {-1, 0}};
bool bfs(int i , int j , vector<vector<int>> &grid, int mid){

    if(grid[0][0] > mid) return false;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = true;

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            if(i == m-1 && j == n-1) return true;

            for(auto &dir : directions){
                int newi = i + dir[0];
                int newj = j + dir[1];

                if(newi >= 0 && newi < m && newj >= 0 && newj < n &&
                   !visited[newi][newj] && grid[newi][newj] <= mid){
                    
                    visited[newi][newj] = true;
                    q.push({newi, newj});
                }
            }
        }
        return false;
}



bool isPossible(vector<vector<int>> &grid, int mid){
    return bfs(0 , 0 ,grid , mid );
}

    int swimInWater(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int l = 0 ; 
        int r = n * n - 1; 
        int result = 0 ; 

        while(l <= r){
            int mid = l + (r - l)/2; 

            if(isPossible(grid, mid)){
                result = mid; 
                r = mid - 1; 
            }
            else l = mid + 1; 
        }
        return result; 
    }
};