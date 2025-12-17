// 3573. Best Time to Buy and Sell Stock V


class Solution {
public:
int n ; 
vector<vector<vector<long long>>>dp ; 
long long solve(vector<int> &prices , int k , int type , int i){
    if(i >= n ) {
        if( type == 0 ) return 0; 
        return INT_MIN; 
    }

    if(dp[i][k][type] !=  LLONG_MIN) return dp[i][k][type]; 

    long long not_take = solve(prices, k , type , i + 1);

    long long take = INT_MIN; 

    if(k > 0 ){
        if(type == 1){
            take = prices[i] + solve(prices, k-1 , 0 , i + 1);
        }
        else if(type == 2){
            take = -prices[i] + solve(prices , k-1, 0 , i + 1);
        }
        else{
            take = max(-prices[i] + solve(prices, k, 1, i + 1), prices[i] + solve(prices, k , 2, i + 1)); 
        }
        
    }
     return dp[i][k][type] =  max(take , not_take);
}

    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        dp.assign(n + 1, vector<vector<long long>>(k+ 1, vector<long long>(3, LLONG_MIN)));
        return solve(prices, k , 0 , 0);
    }
};