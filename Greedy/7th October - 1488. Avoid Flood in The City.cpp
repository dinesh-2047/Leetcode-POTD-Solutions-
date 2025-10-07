// 1488. Avoid Flood in The City


class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        vector<int>result(n, 1);

        unordered_map<int ,int>mp ; 
        set<int>st; 

        for(int i = 0 ; i  < n; i++){
           int lake = rains[i];

           if(lake == 0 ){
              st.insert(i);
           }
           else{
               result[i] = -1; 

               if(mp.count(lake)){
                  auto it = st.lower_bound(mp[lake]);
                  if(it == st.end()){
                     return {};
                  }
                  int idx = *it; 
                  result[idx] = lake; 
                  st.erase(it);
               }
           }
           mp[lake] = i; 
        }
        return result; 
    }
};