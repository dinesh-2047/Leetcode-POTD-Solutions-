// 3620. Network Recovery Pathways

class Solution {
public:
using ll = long long;  
int n; 
unordered_map<int , list<pair<int, int>>> adj; 
using P =  pair<ll , int>; 
bool isPossible(ll &mid, ll &k ){
    vector<ll> dist(n, 1e18);

    priority_queue<P, vector<P>, greater<>>pq; 
    
    pq.push({0, 0});
    dist[0] = 0; 

    while(!pq.empty()){
        auto curr= pq.top();
        pq.pop();

        ll c = curr.first; 
        int node = curr.second; 

        if(node == n-1){
            return dist[n-1] <= k ; 
        }

        if (c > dist[node]) continue;

        for(auto &[nbr, cc] : adj[node]){
            if(cc < mid ) continue; 
            if(cc + c < dist[nbr]){
                dist[nbr] = cc + c; 
                pq.push({dist[nbr], nbr});
            }
        }
    }
    return dist[n - 1] <= k; 
}

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        ll maxi = 0  ; 
        adj.clear();
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int c = edge[2];

            if(online[u] && online[v]){
                adj[u].push_back({v,c});
                maxi = max(maxi ,1LL *  c);
            }
        }

        ll l = 0; 
        ll r = maxi;

        ll result = -1;  

        while(l <= r){
            ll mid = l + (r - l )/2; 
            if(isPossible( mid, k )){
                result = mid ; 
                l = mid + 1; 
            }
            else r = mid - 1; 

        }
      return result ; 

    }
};