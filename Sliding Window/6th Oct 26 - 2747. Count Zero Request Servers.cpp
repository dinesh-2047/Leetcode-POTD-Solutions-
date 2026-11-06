// 2747. Count Zero Request Servers

class Solution {
public:
static bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        int l = logs.size();
        int q = queries.size();

        sort(begin(logs), end(logs), cmp);
        vector<pair<int , int>> qi(q);
        for(int i = 0 ; i  < q; i++){
            qi[i] = {queries[i], i};
        }
        sort(begin(qi), end(qi));

        vector<int> result(q); 


        int i = 0 ; 
        int j = 0 ; 
        unordered_map<int , int> mp ; 

        for(auto [query , idx ] : qi){
             while(j < l && logs[j][1] <= query ){
                   mp[logs[j][0]]++;
                   j++;
             }

             while( i <  j && logs[i][1] < query-x){
                  mp[logs[i][0]]--;
                  if(mp[logs[i][0]] == 0) mp.erase(logs[i][0]);
                  i++;
             }
             result[idx] = n - mp.size();
        }
        return result; 
    }
};