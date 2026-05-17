// 1306. Jump Game III

class Solution {
public:
unordered_map<int , list<int>>adj; 
int n ; 
bool dfs(vector<int> &arr, vector<int> &visited, int i){
    visited[i] = true; 
    if(arr[i] == 0 ) return true; 

    for(auto &nbr : adj[i]){
        if(!visited[nbr]){
            if(dfs(arr, visited, nbr)) return true; 
        }
    }
    return false; 

}
    bool canReach(vector<int>& arr, int start) {
         n = arr.size();

         for(int i = 0 ; i  < n; i++){
            if(i + arr[i] < n ){
                adj[i].push_back(i + arr[i]);
            }
            if(i - arr[i] >= 0 ){
                adj[i].push_back(i - arr[i]);
            }
         }


         vector<int> visited(n , false);
        if( dfs(arr, visited, start)) return true; 
        return false; 

         
    }
};