// 407. Trapping Rain Water II/


class Solution {
public:
vector<vector<int>>directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<pair<int , pair<int , int>>, vector<pair<int , pair<int ,int>>>, greater<>>pq; 

        vector<vector<bool>>visited(m , vector<bool>(n+ 1, false));

        for(int row = 0 ; row < m ;row++){
            for(int col : {0, n-1}){
                pq.push({heightMap[row][col], {row, col}});
                visited[row][col] = true; 
            }
        }

        for(int col = 0 ; col < n; col++){
            for(int row : {0 , m-1}){
                pq.push({heightMap[row][col], {row , col}});
                visited[row][col] = true; 
            }
        }

        int water_volume  = 0 ; 

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int height = curr.first; 
            int i = curr.second.first; 
            int j = curr.second.second; 

            for(auto &dir :  directions){
                int newi = i + dir[0];
                int newj = j + dir[1];

                if(newi < m && newj < n && newi >= 0 && newj >= 0 && !visited[newi][newj] ){
                     water_volume += max(height - heightMap[newi][newj], 0);

                     pq.push({max(height, heightMap[newi][newj]), {newi , newj}});
                     visited[newi][newj] = true; 
                }
            }
        }
        return water_volume ; 
    }
};