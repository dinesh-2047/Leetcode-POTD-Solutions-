// 3559. Number of Ways to Assign Edge Weights II

class Solution {
public:
int mod = 1e9+ 7;
unordered_map<int , list<int>> adj; 
vector<vector<int>> up ; 
vector<int> depth ; 
int n, cols; 
void dfs(int node, int parent){
       up[node][0] = parent; 
      
       for(auto &nbr : adj[node]){
          if(nbr == parent)  continue; 
           depth[nbr] = depth[node] + 1; 
          dfs(nbr, node);
       }
}

void buildAncestorTable(){


    for(int j = 1; j  < cols; j++){
        for(int node = 0 ; node < n; node++){
            if(up[node][j-1] != - 1)
            up[node][j]= up[up[node][j-1]][j-1];
        }
    }
}

int findLCA(int u , int v){
    if(depth[u] < depth[v]){
        swap(u, v);
    }

    int k = depth[u] - depth[v];

    for(int j = 0 ;  j< cols; j++){
        if(k &(1 << j )) {
            u = up[u][j];
        }
    }

    if(u == v) return u ; 

    for(int j = cols - 1; j >= 0 ; j--){
        if(up[u][j] == -1) continue; 

        if(up[u][j] != up[v][j]) {
            u = up[u][j];
            v  = up[v][j];
        }
    }

    return up[v][0];
}
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n = edges.size() + 1; 
        cols = log2(n) + 1; 
        for(auto &edge : edges){
            int u = edge[0]-1;
            int v = edge[1]-1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
         up.resize(n , vector<int> (cols, -1));
        depth.assign(n , 0);
        dfs(0, -1);

        buildAncestorTable();

         //precompute power of 2 ;
        vector<int> pow2(n + 1, 0);
        pow2[0] = 1; 

        for(int i = 1; i  <= n ; i++){
            pow2[i] = (2LL * pow2[i - 1])%mod;
        }
           
        vector<int> result; 

        for(auto &query : queries){
            int u = query[0] - 1; 
            int v = query[1] - 1; 

            int lca = findLCA(u , v);
            int d = depth[u] + depth[v] - 2*depth[lca];

            if(d == 0) result.push_back(0);

            else {
                result.push_back(pow2[d-1]);
            }
        }
        return result; 
    }
};