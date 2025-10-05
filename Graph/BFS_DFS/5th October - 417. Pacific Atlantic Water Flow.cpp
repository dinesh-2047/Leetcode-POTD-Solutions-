// 417. Pacific Atlantic Water Flow


class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void dfs(int i, int j, vector<vector<int>>& heights,
             vector<vector<bool>>& visited, int prevHeight) {

         if(i <  0 || j < 0 || i >= m || j>= n || visited[i][j]|| heights[i][j] < prevHeight ) return ; 

  

        visited[i][j] = true;

        for (auto &dir : directions) {
            int newi = i + dir[0];
            int newj = j + dir[1];
            dfs(newi, newj, heights, visited, heights[i][j]);
              
        }
        
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<int>>result; 

        vector<vector<bool>> pacificVisited(m , vector<bool>(n , false));
        vector<vector<bool>> anlanticVisited(m , vector<bool>(n , false));

        for(int j = 0 ; j  < n; j++){
            dfs(0 , j , heights, pacificVisited, INT_MIN);  //first row
            dfs(m-1 , j , heights, anlanticVisited, INT_MIN);  //last row

        }

        for(int i = 0 ; i  < m; i++){
             dfs(i, 0 , heights, pacificVisited , INT_MIN);
             dfs(i , n-1 , heights, anlanticVisited , INT_MIN);
        }

        for(int i = 0 ; i  <m; i++ ){
            for(int j = 0 ; j  < n ; j++){
                if(pacificVisited[i][j] && anlanticVisited[i][j] ){
                    result.push_back({i, j});
                }
            }
        }
        return result; 
    }
};
