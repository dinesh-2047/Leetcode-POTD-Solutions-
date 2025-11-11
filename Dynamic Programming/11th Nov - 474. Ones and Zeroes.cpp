// 474. Ones and Zeroes

// Approach 1 rec + memo 
class Solution {
public:

vector<vector<vector<int>>>dp ; 
int solve(int i , vector<int> &pref0 , vector<int> &pref1, int m , int n ){
    if( i >= pref0.size() || (m == 0 && n == 0 )) return 0 ; 
   

   if(dp[i][m][n]!=-1) return dp[i][m][n];
    int take = 0 ;

    if(m >= pref0[i] && n >= pref1[i])
    take  = 1 + solve( i + 1 ,pref0, pref1 , m - pref0[i], n - pref1[i]);

    int not_take = solve(i  + 1, pref0 , pref1 , m , n);

    return dp[i][m][n] = max(take , not_take) ;

      
}
    int findMaxForm(vector<string>& strs, int m, int n) {
       
    dp.assign(strs.size()+ 1, vector<vector<int>>(m + 1, vector<int> ( n + 1, -1)));
       vector<int>pref0, pref1; 

       for(auto &s : strs){
          int count0 = 0;
          int count1 = 0 ;  
          for(int i = 0 ; i < s.length() ; i++){
                if(s[i] == '0') count0++;
                else count1++;
          }
           pref0.push_back(count0);
           pref1.push_back(count1);
       }

       

      return solve(0 , pref0 , pref1, m , n);

    }
};




//Approach 2  bottom up 
class Solution {
public:

    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto& s : strs) {
            int count0 = 0;
            int count1 = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == '0')
                    count0++;
                else
                    count1++;
            }

            for (int zero = m; zero >= count0; zero--) {
                for (int one = n; one >= count1; one--) {
                    dp[zero][one] = max(dp[zero][one],1 +  dp[zero - count0][one - count1]);
                }
            }
        }

        return dp[m][n];
    }
};