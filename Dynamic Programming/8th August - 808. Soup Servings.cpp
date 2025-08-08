// 808. Soup Servings


class Solution {
public:
vector<vector<double>>dp;
double solve(int a , int b){
     if(a <= 0 && b <= 0 ) return  0.5; 
     if(a <= 0 && b > 0 ) return 1.0;
     if(b <= 0 && a > 0 ) return 0.0; 

     if(dp[a][b]!=-1) return dp[a][b];
     
    double op1 = solve(a-100, b);
    double op2 =solve(a-75, b-25);
    double op3 = solve(a-50, b - 50);
    double op4 = solve(a-25, b-75);


    return dp[a][b]=  0.25 * (op1+ op2 + op3 + op4);
    
}

    double soupServings(int n) {
        if(n >= 4800) return 1;

     dp.resize(n+1, vector<double>(n+1, -1)); 
        return solve(n , n );
    }
};