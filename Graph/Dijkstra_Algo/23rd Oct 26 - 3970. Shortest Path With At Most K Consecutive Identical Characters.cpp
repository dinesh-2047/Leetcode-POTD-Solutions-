// 3970. Shortest Path With At Most K Consecutive Identical Characters

class Solution {
public:
unordered_map<int , list<pair<int , int>>> adj; 
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }
        
        //wt , consec char count, node
        priority_queue<tuple<int , int , int>, vector<tuple<int , int , int>>, greater<>> pq; 
        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));
        pq.push({0, 1, 0 });
        dist[0][1] = 0;  
        int result = 1e9 ; 

        while(!pq.empty()){
            auto [wt , consecCharCount, node] = pq.top();
            pq.pop();

            if(node == n - 1) result = min(result, dist[node][consecCharCount]);

            for(auto &[nbr, w] : adj[node]){
                int newConsecCharCount = ((labels[nbr] == labels[node]) ? consecCharCount + 1 : 1);
                if(newConsecCharCount > k ) continue; 
                if(w + wt < dist[nbr][newConsecCharCount]){
                        dist[nbr][newConsecCharCount] = w + wt; 
                        pq.push({dist[nbr][newConsecCharCount], newConsecCharCount, nbr});
                }

            }
        }
      return result == 1e9 ? -1 : result; 
        
    }
};