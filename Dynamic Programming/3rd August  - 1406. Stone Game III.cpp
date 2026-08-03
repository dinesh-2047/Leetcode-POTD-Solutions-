// 1406. Stone Game III



class Solution {
public:
int n ;
vector<vector<int>> dp; 
int solve(vector<int> &stoneValue, int i , int turn){
    if(i >= n ) return 0; 

    if(dp[i][turn] != -1) return dp[i][turn];

    if(!turn){
        //alice turn 
        int result = INT_MIN;
        int sum = 0 ; 
        for(int j = i ; j < i + 3 && j < n ; j++){
            sum += stoneValue[j];
            result = max(result,sum + solve(stoneValue, j + 1 , 1));
        }
        return dp[i][turn] = result; 
    }
    else {
        //bob turn 
        int result = INT_MAX; 
        int sum = 0 ; 
 
        for(int j = i ; j < i + 3 && j < n ; j++){
            sum += stoneValue[j];
            result = min(result, solve(stoneValue, j + 1 , 0)-sum);
        }
        return dp[i][turn] =  result;
        

    }
}
    string stoneGameIII(vector<int>& stoneValue) {
       n = stoneValue.size() ;
       dp.assign(n + 1, vector<int> (2 ,-1));
       int result = solve(stoneValue, 0 , 0);
       if(result < 0 ) return "Bob";
       else if(result == 0) return "Tie";
       else return "Alice";
    }
};