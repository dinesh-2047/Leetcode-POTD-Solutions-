// 3650. Minimum Cost Path with Edge Reversals

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int , list<pair<int , int>>>adj; 
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, 2*w});
        }

        vector<int>dist(n , INT_MAX);
        priority_queue<pair<int , int> , vector<pair<int , int>>, greater<>>pq; 
        pq.push({0,0});
        dist[0] = 0; 

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int node = curr.second; 


            for(auto &ngbr : adj[node]){
                int nbr = ngbr.first; 
                int w = ngbr.second; 

                if(dist[nbr] > dist[node] + w ){
                    dist[nbr] = dist[node] + w; 
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        return dist[n-1] == INT_MAX ? -1 : dist[n-1];
    }
};