// 3310. Remove Methods From Project

class Solution {
public:
     unordered_map<int , list<int>> adj; 
void dfs(int node, vector<bool> &isSusp ){
    isSusp[node] = true; 

    for(auto &nbr : adj[node]){
        if(!isSusp[nbr]){
            dfs(nbr, isSusp);
        }
    }
}
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
    
         for(auto &inv : invocations){
            int a = inv[0];
            int b = inv[1];

            adj[a].push_back(b);
         }

         vector<bool> isSusp(n ,false); 
         dfs(k, isSusp);

       bool outHit = false; 
       for(auto it = adj.begin(); it!=adj.end(); it++){
            auto &node = it->first; 
            auto &v = it->second; 

            if(isSusp[node]) continue; 
             
            for(auto &x : v){
                if(isSusp[x]){
                    outHit = true; 
                    break;
                }
            }
            if(outHit) break; 
       }

      vector<int> result;
      if(outHit){
        for(int i = 0 ; i  < n; i++) result.push_back(i);
        return result; 
      }
      for(int i = 0 ; i < n; i++){
        if(!isSusp[i]) result.push_back(i);
      }
       return result; 
    }
};
