// 3488. Closest Equal Element Queries

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        vector<int>result; 

        unordered_map<int, vector<int>>mp ; 

        for(int i = 0 ; i  < n; i++){
            mp[nums[i]].push_back(i);
        }

        for(auto &query : queries){
             int val = nums[query];

             auto &v = mp[val];

             int idx = lower_bound(begin(v), end(v), query) - begin(v);
              int dist = INT_MAX; 
           
                dist = min(dist, abs(query - v[(idx  + 1)%v.size()]) );
                dist = min(dist , abs(query - v[(idx - 1 + v.size())%v.size()]));
                dist = min(dist, n -  abs(query - v[(idx  + 1)%v.size()]) );
                dist = min(dist , n -  abs(query - v[(idx - 1 + v.size())%v.size()]));
            

             if(dist == 0) result.push_back(-1);
             else result.push_back(dist);
        }
        return result; 
    }
};