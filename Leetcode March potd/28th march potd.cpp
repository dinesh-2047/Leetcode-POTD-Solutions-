// 2503. Maximum Number of Points From Grid Queries


// Approach 1 TLE BFS 


class Solution {
public:
    int k, m, n;  
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};  

    void calculate(vector<vector<int>>& grid, int q, int &temp) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>>que;  // BFS queue

        if (q > grid[0][0]) {  
            temp++;
            visited[0][0] = true;
            que.push({0, 0});

            while (!que.empty()) {
                auto [i, j] = que.front();
                que.pop();

                for (auto &dir : directions) {
                    int newi = i + dir[0];
                    int newj = j + dir[1];

                    if (newi >= 0 && newi < m && newj >= 0 && newj < n && !visited[newi][newj] && grid[newi][newj] < q) {
                        temp++;
                        visited[newi][newj] = true;
                        que.push({newi, newj});
                    }
                }
            }
        }
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        k = queries.size();
        m = grid.size();
        n = grid[0].size();
        vector<int> ans(k);

        for (int i = 0; i < k; i++) {
            int temp = 0;
            calculate(grid, queries[i], temp);
            ans[i] = temp;  // Fix: Use indexing instead of push_back
        }
        return ans;
    }
};

// Approach 2 TLE DFS

class Solution {
    public:
        int k, m, n;
        vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
        void dfs(vector<vector<int>>& grid, int q, int& temp, int i, int j, vector<vector<bool>>& visited) {
            // Base case: Out of bounds or already visited or value ≥ q
            if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] >= q) {
                return;
            }
    
            // Mark visited and count this cell
            visited[i][j] = true;
            temp++;
    
            // Explore 4 directions
            for (auto &dir : directions) {
                int newi = i + dir[0];
                int newj = j + dir[1];
                dfs(grid, q, temp, newi, newj, visited);
            }
        }
    
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            k = queries.size();
            m = grid.size();
            n = grid[0].size();
            vector<int> ans(k);
    
            for (int i = 0; i < k; i++) {
                int temp = 0;
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                dfs(grid, queries[i], temp, 0, 0, visited);
                ans[i] = temp;
            }
            return ans;
        }
    };

//Approach 3 (Prioirity Queue + queries sorting )

class Solution {
    public:
        int k, m, n;
        vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        typedef pair<int , pair<int , int>> p;
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            k = queries.size();
            m = grid.size();
            n = grid[0].size();
            vector<int> ans(k);
    
            vector<pair<int, int>>sortedQ(k);
    
            for(int i = 0 ; i<k; i++){
                sortedQ[i] = {queries[i], i};
            }
    
            sort(begin(sortedQ), end(sortedQ));
    
            priority_queue<p, vector<p>, greater<>>pq; //val , i , j 
            
            vector<vector<bool>>visited(m , vector<bool>(n, false));
    
            int points =0 ;
            pq.push({grid[0][0],{0,0}});
    
            visited[0][0] = true; 
            
            for(auto &query : sortedQ){
                  int q = query.first;
                  int index = query.second; 
                while(!pq.empty() && pq.top().first < q){
                     int i = pq.top().second.first; 
                     int j = pq.top().second.second;
                     pq.pop();
                     points++;
    
                     for(auto &dir : directions){
                        int newi = i + dir[0];
                        int newj  = j + dir[1];
    
                        if(newi < m && newi >=0 && newj >=0 && newj <n && !visited[newi][newj] ){
                            visited[newi][newj] = true;
                            pq.push({grid[newi][newj],{newi, newj}});
                        }
                     }
                }
                ans[index] = points; 
            }
    
         return ans; 
    
        }
    };