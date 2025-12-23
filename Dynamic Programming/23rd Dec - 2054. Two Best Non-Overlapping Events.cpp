// 2054. Two Best Non-Overlapping Events


class Solution {
public:
int n ; 
vector<vector<int>>dp;
static bool cmp(int value  , vector<int> &e){
    return value  < e[0];
}
int solve(vector<vector<int>> &events , int count , int i ){
    if(count == 2 || i>= n) return 0 ; 
    
    if(dp[i][count] != -1) return dp[i][count];

    int not_attend = solve(events , count , i + 1);
    int nextIdx = upper_bound(events.begin(), events.end(), events[i][1], cmp)- events.begin();
    int attend = events[i][2] + solve(events, count + 1, nextIdx);

    return dp[i][count] =  max(attend , not_attend);
}
    int maxTwoEvents(vector<vector<int>>& events) {
         n = events.size();
        dp.assign(n + 1, vector<int>(3, -1));
         sort(begin(events), end(events));

         return solve(events , 0 , 0);
    }
};