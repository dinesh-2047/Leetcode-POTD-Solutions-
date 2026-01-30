// 2977. Minimum Cost to Convert String II



class Solution {
public:
using ll = long long ; 
int n , m; 
set<int>valid_len;  
unordered_map<string, list<pair<string , ll>>>adj;
unordered_map<string, unordered_map<string , ll>>dij_memo; 
vector<ll>dp;
ll dijkstra(string &src, string &target){
    if(dij_memo[src].count(target)){
        return dij_memo[src][target];
    }
    if(src == target) return 0 ;
   priority_queue<pair<ll ,string>, vector<pair<ll , string>>, greater<>>pq; 
   pq.push({0, src});

   unordered_map<string , ll>dist; 
   dist[src] = 0;

   while(!pq.empty()){
      auto curr = pq.top();
      pq.pop();

      string node = curr.second; 
      ll c = curr.first; 

      for(auto &ngbr : adj[node]){
         ll nbr_cost = ngbr.second; 
         string nbr = ngbr.first; 

         if(!dist.count(nbr) || dist[nbr] > c + nbr_cost){
            dist[nbr] = c +  nbr_cost; 
            pq.push({dist[nbr], nbr});
         }

      }
   }
 
   return dij_memo[src][target] = (dist.count(target) ? dist[target] : 1e18); 
}
ll solve(string &source, string &target, int i){
    
   if(i >= n) return 0;

   if(dp[i]!=-1) return dp[i];

    ll result = 1e18;
    if(source[i] == target[i]){
        result = solve(source, target, i +1 );
    }

    //try all valid len substrings ; 
    for(auto &len : valid_len){
        if(i+len > n){
            break; 
        }
        string srcSub = source.substr(i, len);
        string targetSub = target.substr(i, len);

        if(!adj.count(srcSub)) continue; 

        ll c = dijkstra(srcSub, targetSub);
        if(c == 1e18){
            continue;
        }
        ll next = solve(source, target, i + len);
        if (next != 1e18) {
            result = min(result, c + next);
        }
       
    }
    return dp[i] =  result; 
}


    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        n = source.length();
        m = cost.size();
        dp.assign(n + 1, -1);
        for(int i = 0 ; i  < m; i++){
            string u = original[i];
            string v = changed[i];
            ll c = cost[i];

            adj[u].push_back({v, c});

        } 

        for(auto &o : original) valid_len.insert(o.length());
        

        ll result =  solve(source, target, 0);
        return result == 1e18 ? -1 : result; 
    }
};