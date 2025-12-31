// 1970. Last Day Where You Can Still Cross


// Approach 1 DFS

class Solution {
public:
int ROW, COL; 
vector<vector<int>>directions = {{0,1},{1,0},{0,-1},{-1,0}};
bool canCrossDFS(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited){
    
    if( i < 0 || j < 0 || i >= ROW || j >= COL || grid[i][j] == 1 || visited[i][j]) return false; 

    if( i == ROW-1) return true; 
     
     visited[i][j] = true; 

        for(auto &dir : directions){
            int newi = i + dir[0];
            int newj = j + dir[1];

            if(canCrossDFS(newi, newj , grid, visited)){
                return true; 
            }
        }

    return false; 
}

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
         ROW = row; 
         COL = col; 
        int n = cells.size();
         
        int result = 0 ; 
        int l = 0 ; 
        int r = n- 1 ; 

        while(l <= r){
            int mid = l + (r- l )/2;
            vector<vector<int>>grid(row, vector<int>(col, 0));

          for(int i = 0 ; i  <= mid; i++){
            int r = cells[i][0];
            int c = cells[i][1];

            grid[r-1][c-1] = 1; 
          }

            vector<pair<int , int>>lands; 

            for(int j = 0 ; j  < col; j++){
                if(grid[0][j] == 0 ){
                    lands.push_back({0 , j});
                }
            }
  
             bool canCross = false;
            for(auto &p : lands){
                 vector<vector<bool>>visited(ROW, vector<bool>(COL, false));
                if(canCrossDFS(p.first, p.second, grid, visited)){
                    result = mid + 1; 
                    canCross = true;
                    break; 
                }
            }

            if(!canCross){
                r = mid - 1;
            }
            else l = mid + 1; 

        }

        return result; 
    }
};



//Approch 2 BFS
class Solution {
public:
int ROW, COL; 
vector<vector<int>>directions = {{0,1},{1,0},{0,-1},{-1,0}};
bool canCrossBFS(int r, int c, vector<vector<int>> &grid){
    queue<pair<int , int>>q; 
    vector<vector<bool>>visited(ROW, vector<bool>(COL, false));

    q.push({r, c});
    visited[r][c] = true; 

    while(!q.empty()){
        auto curr = q.front();
        q.pop();

        int i = curr.first; 
        int j = curr.second ; 

        if(i == ROW - 1) return true; 

        for(auto &dir : directions){
            int newi = i + dir[0];
            int newj = j + dir[1];

            if(newi < ROW && newj < COL && newi >= 0 && newj >= 0 && !visited[newi][newj] && grid[newi][newj] != 1  ){
                visited[newi][newj] = true; 
                q.push({newi , newj});
            }
        }


    }
    return false; 
}

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
         ROW = row; 
         COL = col; 
        int n = cells.size();
         
        int result = 0 ; 
        int l = 0 ; 
        int r = n- 1 ; 

        while(l <= r){
            int mid = l + (r- l )/2;
               vector<vector<int>>grid(row, vector<int>(col, 0));

          for(int i = 0 ; i  <= mid; i++){
            int r = cells[i][0];
            int c = cells[i][1];

            grid[r-1][c-1] = 1; 
          }

            vector<pair<int , int>>lands; 

            for(int j = 0 ; j  < col; j++){
                if(grid[0][j] == 0 ){
                    lands.push_back({0 , j});
                }
            }
  
             bool canCross = false;
            for(auto &p : lands){
                if(canCrossBFS(p.first, p.second, grid)){
                    result = mid + 1; 
                    canCross = true;
                    break; 
                }
            }

            if(!canCross){
                r = mid - 1;
            }
            else l = mid + 1; 

        }

        return result; 
    }
};