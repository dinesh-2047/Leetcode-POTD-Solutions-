// 1872. Stone Game VIII

class Solution {
public:
vector<int> pref; 
vector<int> dp; 
int n ;
int solve( int i ){
    if(i == n - 1 ){
        return pref[n-1] ; 
    }
     if(dp[i]!=-1e9) return dp[i];
    int not_take = solve(i + 1);
    int take  = pref[i] - solve(i + 1);

    return dp[i] =  max(take, not_take);

}
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        pref.resize(n , 0);
        dp.resize(n + 1, -1e9);
        pref[0] = stones[0];

        for(int i = 1; i < n; i++){
            pref[i] = pref[i  - 1] + stones[i];
        }

        return solve(1);
    }
};