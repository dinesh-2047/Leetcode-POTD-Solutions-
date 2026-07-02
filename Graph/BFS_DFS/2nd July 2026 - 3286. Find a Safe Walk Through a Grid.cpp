// 3286. Find a Safe Walk Through a Grid

class Solution {
public:
using P = pair<int , pair<int , int>>; 
vector<vector<int>> directions= {{0,1},{1,0},{0,-1},{-1,0}};
vector<vector<bool>> visited; 
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        deque<P>dq; 
        if(grid[0][0] == 1){
            dq.push_back({1, {0, 0}});
        }
        else dq.push_back({0, {0, 0}});
        visited.assign(m, vector<bool>(n, false));
        visited[0][0] = true; 

        while(!dq.empty()){
            auto curr = dq.front();
            dq.pop_front();

            int x = curr.first; 
            int i = curr.second.first; 
            int j = curr.second.second; 

            if(i == m - 1&& j == n - 1)
                 return (health - x) >= 1; 

            for(auto &dir : directions){
                int newi = i + dir[0];
                int newj = j + dir[1];

                if(newi >= m || newj >= n || newi < 0 || newj < 0 || visited[newi][newj]) continue; 

                if(grid[newi][newj] == 0){
                    dq.push_front({x, {newi, newj}});
                }
                else {
                    dq.push_back({x + 1, {newi, newj}});
                }
                 visited[newi][newj] = true; 
            }

        }
        return false; 
    }
};