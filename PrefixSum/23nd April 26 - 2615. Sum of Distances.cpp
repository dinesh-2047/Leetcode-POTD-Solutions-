// 2615. Sum of Distances

class Solution {
public:
using ll = long long ; 
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        vector<ll> result(n); 
        unordered_map<int , vector<ll>> mp ; 

        for(int i = 0 ; i  < n; i++){
            mp[nums[i]].push_back(i);
        }

        for(auto &[x, v] : mp){
            int m = v.size();
            vector<ll> pref(m);
            pref[0] = v[0];
            for(int i = 1; i < m ; i++){
                pref[i] = pref[i - 1] + v[i];
            }

            for(int i = 0 ; i  < m; i++){
                ll left = v[i] * i ; 
                if( i - 1 >= 0){
                    left -= (pref[i - 1]);
                }

                ll right = (pref[m - 1] - pref[i] )- (v[i] * (m - i - 1));
                result[v[i]] = left + right; 
            }
        }
        return result; 
    }
};