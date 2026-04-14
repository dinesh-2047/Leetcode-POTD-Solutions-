// 2463. Minimum Total Distance Traveled

class Solution {
public:
using ll = long long ; 
int n ; 
vector<vector<ll>> dp; 
ll solve(vector<int> &robot, vector<int> &fac, int i , int j ){
         if(i >= n) return 0; 
         if(j >= fac.size()) return 1e18; 

         if(dp[i][j] != -1) return dp[i][j];

         ll take = abs(robot[i] - fac[j]) + solve(robot, fac, i + 1, j + 1);
         ll not_take = solve(robot , fac, i , j + 1);

         return dp[i][j] = min(take , not_take);
}

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
         n = robot.size();

         sort(begin(robot), end(robot));
         sort(begin(factory), end(factory));

         vector<int> fac; 
         for(int i = 0 ; i < factory.size() ; i++){
             for(int j = 0 ; j  < factory[i][1]; j++){
                 fac.push_back(factory[i][0]);
             }
         }
         dp.assign(n + 1 , vector<ll> (fac.size() + 1, -1));
         return solve(robot, fac, 0 , 0);
    }
};