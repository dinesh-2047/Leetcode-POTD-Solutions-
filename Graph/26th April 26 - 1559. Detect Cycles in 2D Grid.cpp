// 1559. Detect Cycles in 2D Grid


// Approach 1 DFS : 
class Solution {
public:
int m , n ; 
vector<vector<int>> directions = {{0, 1}, {1,0}, {0,-1}, {-1, 0}};
 vector<vector<bool>> visited;
bool isCycle(vector<vector<char>> &grid, vector<vector<bool>> &visited, int parenti, int parentj, int i , int j, char ch){
      if(i <0 || j < 0 || i >= m || j >= n || grid[i][j] != ch) return false; 

      if(visited[i][j]) return true; 
    
      visited[i][j] = true; 

      for(auto &dir : directions) {
        int newi = i + dir[0];
        int newj = j + dir[1];
        if(newi == parenti && newj == parentj) continue;
        if(isCycle(grid, visited, i, j , newi, newj, ch)) return true;  
       
      }
     
      return false; 
}

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<bool>(n ,false));
        for(int i = 0 ; i  < m; i++){
            for(int j = 0 ; j  < n; j++){
                if(!visited[i][j]){
                if(isCycle(grid, visited, -1 , -1, i , j, grid[i][j]  )){
                    return true; 
                }
                }
            }
        }
        return false; 

    }
};


// Approach 2 DSU :

class Solution {
public:
vector<int> parent, rank;

int find(int x){
    if(parent[x] == x) return x; 
    return parent[x] = find(parent[x]);
}

bool Union(int x , int y){
    int parentx = find(x);
    int parenty = find(y);
     if(parentx == parenty) return true; 

    if(rank[parentx] < rank[parenty]){
        parent[parentx] = parenty; 
    }
    else if(rank[parentx] > rank[parenty]){
        parent[parenty] = parentx;
    }
    else {
        rank[parentx]++;
        parent[parenty] = parentx; 
    }
    return false; 
}
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        rank.resize(m*n, 0);
        parent.resize(m*n);
        
        for(int i = 0 ; i < m*n; i++){
            parent[i] = i; 
        }

        vector<vector<int>> directions = {{0,1},{1,0}};
        for(int i = 0 ; i < m; i++){
            for(int j =0  ; j < n; j++){
                
                for(auto &dir : directions){
                      int newi = i + dir[0];
                      int newj = j + dir[1];

                      if(newi  < 0 || newj < 0 || newi >= m || newj >= n || grid[i][j] != grid[newi][newj]) continue; 

                      if(Union(newi * n + newj, i *n + j )) return true; 
                }
            }
        }
        return false; 
    }
};