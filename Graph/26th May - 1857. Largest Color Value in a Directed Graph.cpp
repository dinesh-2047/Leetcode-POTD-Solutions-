// 1857. Largest Color Value in a Directed Graph


class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        unordered_map<int , list<int>>adj; 

        vector<int>indegree(n,0);

        for(auto &edge : edges){
            int u  = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            indegree[v]++;
        }

          queue<int>q; 
           vector<vector<int>>vec(n , vector<int>(26,0));
        for(int i = 0 ;i<n; i++){
            if(indegree[i] == 0  ){
                q.push(i);
                vec[i][colors[i]-'a'] = 1;
            } 
        }

          int result = 0 ; 
          int countNode = 0 ; 
        while(!q.empty()){
           int u = q.front();
           q.pop();

           countNode++;
       
        
           result = max(result , vec[u][colors[u]-'a']);


           for(auto &v : adj[u]){
              
              for(int i = 0 ; i<26; i++){
                 vec[v][i] = max(vec[v][i], vec[u][i] + (colors[v]-'a' ==i));
              }

              indegree[v]--;
              if(indegree[v]==0) q.push(v);
           }

        }


        if(countNode < n ) return -1; 

        return result; 


    }
};