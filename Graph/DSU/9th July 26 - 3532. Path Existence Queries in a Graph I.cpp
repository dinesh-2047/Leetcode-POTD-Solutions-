// 3532. Path Existence Queries in a Graph I


class DSU{
    public:
    vector<int> parent, rank ;
    DSU(int n){
        parent.resize(n);
        rank.assign(n, 0);  

        for(int i = 0 ; i  < n; i++){
            parent[i] = i ; 
        }
    }

    int find(int x){
        if(parent[x] == x) return x; 
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int px = find(x);
        int py = find(y);

        if(px == py) return ; 

         if (rank[px] < rank[py]) {
            parent[px] = py;
        }
        else if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int m = nums.size();
        DSU dsu(n);
        for(int i = 0 ;i < m - 1; i ++){
            if(nums[i + 1] - nums[i] <= maxDiff){
                dsu.Union(i, i + 1);
            }
        }
         int Q = queries.size();
        vector<bool> result(Q, false);

        for(int i = 0 ; i  < Q ; i++){
            auto q = queries[i];
            int u = q[0];
            int v = q[1];

            if(u == v) {
                result[i] = true; 
                continue; 
            }

            if(dsu.parent[u] == dsu.parent[v]){
                result[i]  =  true; 
            }


        }
        return result; 

        
    }
};