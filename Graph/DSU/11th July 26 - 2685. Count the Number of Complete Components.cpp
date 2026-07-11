// 2685. Count the Number of Complete Components




class DSU{
    public:
    vector<int>parent;
    vector<int>size;

    DSU(int n ){
        parent.resize(n);
        size.resize(n);
        for(int i = 0 ; i<n; i++){
            parent[i] = i;
            size[i]= 1;
        }
    }

    int find(int x){
        if(parent[x] == x) return x; 
        return parent[x] = find(parent[x]);
    } 


    void Union(int x , int y ){
       int parent_x  = find(x);
       int parent_y = find(y);

       if(parent_x == parent_y) return ; 

       if(size[parent_x]  > size[parent_y]){
           parent[parent_y] =parent_x;
           size[parent_x] += size[parent_y];
       }
       else if(size[parent_x]  < size[parent_y]){
         parent[parent_x] = parent_y;
         size[parent_y] += size[parent_x];
       }

       else{
        parent[parent_x] = parent_y;
         size[parent_y] += size[parent_x];
       }
      }

};


class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        unordered_map<int , int>mp ; //root -> edges; 

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            dsu.Union(u , v);
        }


        for(auto &edge :edges){
            int u = edge[0];
            int v = edge[1];

            int root = dsu.find(u);
            mp[root]++;
        }

        int cnt = 0 ; 
        for(int i = 0 ; i<n; i++){
            if(dsu.find(i) == i) {// root
            int v = dsu.size[i];
            int e  = mp[i];

            if(v*(v-1)/2 == e) cnt++;
            }
        }
        return cnt; 
    }
};