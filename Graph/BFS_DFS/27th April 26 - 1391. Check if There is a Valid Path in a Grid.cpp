// 1391. Check if There is a Valid Path in a Grid


// Approach 1 DFS :
class Solution {
public:
int m , n ; 
unordered_map<int ,vector<vector<int>>>  directions;
bool dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i , int j ){
    if( i == m - 1 && j == n -1 )return true; 

    visited[i][j] = true; 

    for(auto &dir : directions[grid[i][j]]){
        int newi = i + dir[0];
        int newj = j + dir[1];

        if(newi < 0 || newj < 0 || newi >= m || newj >= n || visited[newi][newj]) continue; 

        for(auto &revDir : directions[grid[newi][newj]]){
             if(newi + revDir[0] == i && newj +revDir[1] == j){
                if(dfs(grid, visited, newi , newj)) return true; 
             }
        }
    }
    return false; 
}

    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        directions[1] = {{0, -1}, {0, 1}};
        directions[2] = {{1, 0}, {-1, 0}};
        directions[3] = {{0, -1}, {1, 0}};
        directions[4] = {{0, 1}, {1, 0}};
        directions[5] = {{0, -1}, {-1, 0}};
        directions[6] = {{0, 1}, {-1, 0}};
        vector<vector<bool>> visited(m, vector<bool> (n , false));
        return dfs(grid, visited, 0 , 0);
    }
};






//Approach 2 BFS: 
class Solution {
public:
int m , n ; 
unordered_map<int ,vector<vector<int>>>  directions;
bool bfs(vector<vector<int>> &grid){
 vector<vector<bool>> visited(m, vector<bool> (n , false));
    queue<pair<int , int>> q; 
    q.push({0 , 0});
    

    while(!q.empty()){
        auto curr = q.front();
        q.pop();

        int i = curr.first; 
        int j = curr.second; 

        if( i == m- 1 && j == n- 1) return true; 

         visited[i][j] = true; 

        for(auto &dir : directions[grid[i][j]]){
        int newi = i + dir[0];
        int newj = j + dir[1];

        if(newi < 0 || newj < 0 || newi >= m || newj >= n || visited[newi][newj]) continue; 

        for(auto &revDir : directions[grid[newi][newj]]){
             if(newi + revDir[0] == i && newj +revDir[1] == j){
               q.push({newi , newj}) ;
             }
        }
    }

    }
   

    
    return false; 
}

    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        directions[1] = {{0, -1}, {0, 1}};
        directions[2] = {{1, 0}, {-1, 0}};
        directions[3] = {{0, -1}, {1, 0}};
        directions[4] = {{0, 1}, {1, 0}};
        directions[5] = {{0, -1}, {-1, 0}};
        directions[6] = {{0, 1}, {-1, 0}};
       
        return bfs(grid);
    }
};