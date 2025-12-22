// 960. Delete Columns to Make Sorted III


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].length();
        
        int lis = 0 ; 
        vector<int>dp(m, 1);

        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j  < i ; j++){
                bool valid = true; 
                for(int k = 0 ; k < n; k++ ){
                     if(strs[k][j] > strs[k][i]){
                        valid = false; 
                        break; 
                     }

                }
                if(valid) {
                   dp[i] = max(dp[i], dp[j] + 1);
                }
            }
              lis = max(lis , dp[i]);
        }
        return m - lis;
    }
};