// 2492. Minimum Score of a Path Between Two Cities

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int , list<pair<int , int>>> adj; 

        for(auto &r : roads){
            int a = r[0]-1;
            int b = r[1]-1;
            int c = r[2];

            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }


       queue<int> q; 
       vector<bool> visited(n, false);
       visited[0] = true; 
       q.push(0);
       int result = 1e9 ; 
       while(!q.empty()){
           int node = q.front();
           q.pop();

           for(auto &[nbr, d] : adj[node]){ 
               result = min(result, d);
               if(visited[nbr]) continue; 
               q.push(nbr);
               visited[nbr] = true; 
           }
       }
       return result; 
        
    }
};