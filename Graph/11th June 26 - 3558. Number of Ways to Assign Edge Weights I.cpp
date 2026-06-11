// 3558. Number of Ways to Assign Edge Weights I


class Solution {
public:
unordered_map<int, list<int>> adj; 
int maxD = 0 ; 
int mod = 1e9 + 7; 
using ll = long long ; 
int power(int a , int b){
    if(b == 0 ) return 1; 
    ll half = power(a, b/2)%mod;
    ll result = (half * half)%mod;

    if(b%2 == 1){
        result = (result * a)%mod; 
    }
    return result%mod; 
}

void dfs(int node, int parent, int d){
    bool leaf = true; 

    for(auto &nbr : adj[node]){
        if(nbr == parent) continue; 
            leaf = false; 
            dfs(nbr, node, d + 1);
        
    }
    if(leaf){
        maxD = max(maxD, d);
    }
}
    int assignEdgeWeights(vector<vector<int>>& edges) {
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v});
            adj[v].push_back({u});
        }

        dfs(1, 0, 0);

        return power(2, maxD-1)%mod; 


    }
};