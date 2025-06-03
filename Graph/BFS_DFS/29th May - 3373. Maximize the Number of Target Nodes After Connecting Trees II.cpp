// 3373. Maximize the Number of Target Nodes After Connecting Trees II



// Approach 1 DFS 
class Solution {
public:
void dfs(int node, unordered_map<int , list<int>> &adj , int parent , vector<int> &mark , int &zeroMarkCount , int &oneMarkCount){
    if(mark[node] == 0) {
        zeroMarkCount++;
    }
    else oneMarkCount++;

    for(auto &nbr : adj[node]){
        if(nbr != parent){
            mark[nbr] = (mark[node]==0)?1:0;
            dfs(nbr, adj , node, mark , zeroMarkCount, oneMarkCount);
        }
    }
}


unordered_map<int , list<int>> makeAdj(vector<vector<int>> &edges){
    unordered_map<int, list<int>>adj; 
    for(auto &edge : edges){
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj; 
}

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1; 
 
       unordered_map<int , list<int>> adj1  = makeAdj(edges1);
       unordered_map<int , list<int>>adj2 = makeAdj(edges2);    

       vector<int>markTree1(n , -1);
       markTree1[0] = 0 ;
       int zeroMarkCountTree1 = 0 ; 
       int oneMarkCountTree1 = 0 ; 

       dfs(0, adj1 , -1, markTree1, zeroMarkCountTree1 , oneMarkCountTree1);   

        vector<int>markTree2(m , -1);
       markTree1[0] = 0 ;
       int zeroMarkCountTree2 = 0 ; 
       int oneMarkCountTree2 = 0 ; 

       dfs(0, adj2 , -1, markTree2, zeroMarkCountTree2 , oneMarkCountTree2);   

       int maxFromTree2 = max(zeroMarkCountTree2, oneMarkCountTree2);

       vector<int>result(n);
       for(int i = 0 ; i <n; i++){
           if(markTree1[i] == 0){
               result[i] = zeroMarkCountTree1 + maxFromTree2;
           }
           else result[i] = oneMarkCountTree1 + maxFromTree2;
       }
     return result; 
    }
};




//Approach 2 BFS
class Solution {
public:
    void bfs(int node, unordered_map<int, list<int>>& adj, int parent,
             vector<int>& mark, int& zeroMarkCount, int& oneMarkCount, int n) {

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (mark[curr] == 0) {
                zeroMarkCount++;
            } else
                oneMarkCount++;

            for (auto& nbr : adj[curr]) {
                if (!visited[nbr]) {
                    mark[nbr] = (mark[curr] == 0) ? 1 : 0;
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
    }

    unordered_map<int, list<int>> makeAdj(vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        unordered_map<int, list<int>> adj1 = makeAdj(edges1);
        unordered_map<int, list<int>> adj2 = makeAdj(edges2);

        vector<int> markTree1(n, -1);
        markTree1[0] = 0;
        int zeroMarkCountTree1 = 0;
        int oneMarkCountTree1 = 0;

        bfs(0, adj1, -1, markTree1, zeroMarkCountTree1, oneMarkCountTree1, n);

        vector<int> markTree2(m, -1);
        markTree2[0] = 0;
        int zeroMarkCountTree2 = 0;
        int oneMarkCountTree2 = 0;

        bfs(0, adj2, -1, markTree2, zeroMarkCountTree2, oneMarkCountTree2, m);

        int maxFromTree2 = max(zeroMarkCountTree2, oneMarkCountTree2);

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            if (markTree1[i] == 0) {
                result[i] = zeroMarkCountTree1 + maxFromTree2;
            } else
                result[i] = oneMarkCountTree1 + maxFromTree2;
        }
        return result;
    }
};