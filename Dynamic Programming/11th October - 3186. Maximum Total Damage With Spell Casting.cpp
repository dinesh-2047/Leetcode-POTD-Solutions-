// 3186. Maximum Total Damage With Spell Casting


// Approach 1 Rec + memo
class Solution {
public:
int n ; 
vector<long long> dp ; 
long long solve(vector<long long> &vec,int  i , unordered_map<long long , long long > &mp ){
    if(i >= n ) return 0 ; 
      if(dp[i]!=-1) return dp[i];
   int j = lower_bound(begin(vec) + i + 1, end(vec), vec[i] + 3)-begin(vec);
    long long take = vec[i] * mp[vec[i]] + solve(vec, j, mp);

    long long not_take = solve(vec, i + 1, mp);

    return dp[i] = max(take , not_take);
}

    long long maximumTotalDamage(vector<int>& power) {
        int m = power.size();
        unordered_map<long long , long long>mp ; 

        for(int i = 0 ; i < m; i++)
              mp[power[i]]++;

        vector<long long>vec; 
        
        for(auto &[num , _] : mp){
            vec.push_back(num);
        }
        n = vec.size();
        dp.assign(n + 1, -1);

        sort(begin(vec),end(vec) );

        return solve(vec, 0, mp );

    }
};



//Approach 2 bottom up
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int m = power.size();
        unordered_map<long long , long long>mp ; 

        for(int i = 0 ; i < m; i++)
              mp[power[i]]++;

        vector<long long>vec; 
        
        for(auto &[num , _] : mp){
            vec.push_back(num);
        }
       int  n = vec.size();
     
        sort(begin(vec),end(vec) );

        vector<long long> dp(n, 0);

        for(int i = n-1 ; i >= 0 ; i--){
            long long take = (i + 1  < n)  ? dp[i + 1] : 0;
            int j = lower_bound(begin(vec) + i + 1, end(vec), vec[i] + 3) -begin(vec);
            long long not_take = vec[i] * mp[vec[i]] + ((j < n ) ? dp[j] : 0) ;

            dp[i] = max(take , not_take);
        }
        return *max_element(begin(dp), end(dp));
    }
};