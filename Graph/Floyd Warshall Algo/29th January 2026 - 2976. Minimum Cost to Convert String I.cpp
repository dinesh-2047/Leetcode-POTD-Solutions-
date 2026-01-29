// 2976. Minimum Cost to Convert String I


class Solution {
public:
using ll = long long; 
int n , m ;
void floydWarshall(vector<char>& original, vector<char>& changed, vector<int>& cost, vector<vector<ll>> &adj){
   
   for(int i = 0 ; i < n ; i++){
     int o = original[i] - 'a';
     int c = changed[i] -'a';

     adj[o][c] = min(adj[o][c], (ll)cost[i]);
   }

   for(int k = 0 ; k < 26; k++){
     for(int i = 0 ; i  < 26; i++){
        for(int j =0  ; j  < 26; j++){
            adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
        }
     }
   }
}

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
         n = cost.size();
         m = source.length();

        vector<vector<ll>>adj(26, vector<ll>(26, INT_MAX)); 
        
         floydWarshall( original , changed, cost, adj);
        
         
         ll result = 0 ; 
        for(int i = 0 ;i < m; i++) {
            if(source[i] == target[i]) continue; 
        

        if(adj[source[i] - 'a'][target[i] - 'a'] == INT_MAX) return -1; 

        result += adj[source[i] - 'a'][target[i] - 'a'];
        }
        return result; 
    }
};