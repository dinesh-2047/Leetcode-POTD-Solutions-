// 3607. Power Grid Maintenance/



// Approach 1 using dfs 
class Solution {
public:
    void dfs(unordered_map<int, list<int>>& adj, set<int>& component,
             vector<bool>& visited, int node, int &comp , unordered_map<int , int> &node_comp) {

        visited[node] = true;
        component.insert(node);
        node_comp[node] = comp ; 

        for (auto& nbr : adj[node]) {
            if (!visited[nbr]) {
                dfs(adj, component, visited, nbr, comp , node_comp);
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        unordered_map<int, list<int>> adj;

        for (auto& connection : connections) {
            int u = connection[0];
            int v = connection[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, int> node_comp;
        unordered_map < int, set<int>> comp_on_off;

        vector<bool> visited(c + 1, false);
        int comp = 0;

        for (int node = 1; node <= c; node++) {
            if (!visited[node]) {
                set<int> component;
                dfs(adj, component, visited, node, comp , node_comp);

                comp_on_off[comp] = {component};
                comp++;
            }
        }

        vector<int> result;
        for (auto& query : queries) {
            int op = query[0];
            int x = query[1];

            int comp_id = node_comp[x];

            auto& online = comp_on_off[comp_id];
        

            if (op == 1) {
                if (online.count(x)) {
                    result.push_back(x);
                } else {
                    if (online.empty()) {
                        result.push_back(-1);
                    } else
                        result.push_back(*online.begin());
                }
            } else {
                online.erase(x);
            }
        }

        return result;
    }
};





//Approach 2 using bfs 
class Solution {
public:
    void bfs(unordered_map<int, list<int>>& adj, set<int>& component,
             vector<bool>& visited, int node, int &comp , unordered_map<int , int> &node_comp) {

       queue<int>q; 
       q.push(node);

       while(!q.empty()){
          auto node = q.front();
          q.pop();

          visited[node] = true; 
          component.insert(node);
          node_comp[node] = comp; 

          for(auto &nbr : adj[node]){
            if(!visited[nbr]){
                q.push(nbr);
            }
          }
       }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        unordered_map<int, list<int>> adj;

        for (auto& connection : connections) {
            int u = connection[0];
            int v = connection[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, int> node_comp;
        unordered_map < int, set<int>> comp_on_off;

        vector<bool> visited(c + 1, false);
        int comp = 0;

        for (int node = 1; node <= c; node++) {
            if (!visited[node]) {
                set<int> component;
                bfs(adj, component, visited, node, comp , node_comp);

                comp_on_off[comp] = {component};
                comp++;
            }
        }

        vector<int> result;
        for (auto& query : queries) {
            int op = query[0];
            int x = query[1];

            int comp_id = node_comp[x];

            auto& online = comp_on_off[comp_id];
        

            if (op == 1) {
                if (online.count(x)) {
                    result.push_back(x);
                } else {
                    if (online.empty()) {
                        result.push_back(-1);
                    } else
                        result.push_back(*online.begin());
                }
            } else {
                online.erase(x);
            }
        }

        return result;
    }
};






//Approach 3 using dsu 
class Solution {
public:
vector<int>rank; 
vector<int>parent; 

int find_parent(int x){
    if(x == parent[x]) return x; 
    return parent[x] = find_parent(parent[x]);
}

void Union(int x , int y ){
    int x_parent = find_parent(x);
    int y_parent = find_parent(y);

    if(rank[x_parent] > rank[y_parent]){
         parent[y_parent] = x_parent; 
         rank[x_parent]++;
    }
    else if(rank[x_parent] < rank[y_parent]){
        parent[x_parent] = y_parent;
        rank[y_parent]++;
    }
    else {
        parent[y_parent] = x_parent; 
        rank[x_parent]++;
    }
}


    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        
        rank.assign(c+ 1, 0);
        parent.resize(c+ 1);

        for(int i = 1; i <= c; i++) parent[i] = i ; 

        for(auto &connection : connections){
            int u = connection[0];
            int v = connection[1];

            Union(u, v);
        }

        unordered_map<int , int>node_comp; 
        unordered_map<int , set<int>>comp_on; 

        for(int i = 1 ; i<=c; i++){
            int par = find_parent(i);
            node_comp[i] = par;
            comp_on[par].insert(i);
        }
        
        vector<int>result; 

        for(auto &query : queries){
            int op = query[0];
            int x = query[1];

            int comp_id = node_comp[x];
            auto &online = comp_on[comp_id];

            if(op == 1){
                if(online.count(x)){
                    result.push_back(x);
                }
                else{
                    if(online.empty()){
                        result.push_back(-1);
                    }
                    else result.push_back(*online.begin());
                }
        }
        else online.erase(x);
        }
        return result; 
    }
};