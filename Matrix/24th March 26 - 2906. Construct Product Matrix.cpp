// 2906. Construct Product Matrix

class Solution {
public:
int mod = 12345;
using ll = long long ; 
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
       
        vector<int>vec;

        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j <n; j++){
            vec.push_back(grid[i][j]);
            }
        }

        vector<ll>pref_prod(m * n );
        vector<ll>suff_prod(m * n );

        pref_prod[0] = vec[0];
        suff_prod[m*n - 1] = vec[m*n-1];

        for(int i = 1; i < m*n; i++){
            pref_prod[i] = ((ll)pref_prod[i-1] * vec[i])%mod; 
        }

        for(int i = m * n - 2; i >= 0 ; i--){
            suff_prod[i] = ((ll)suff_prod[i + 1] * vec[i])%mod; 
        }


        vector<vector<int>>result(m , vector<int>(n)); 
        int row = 0 ; 
        int col = 0 ; 

        for(int i = 0 ; i  < m * n ; i++){
            ll l = 1; 
            ll r = 1; 
            if(i - 1 >=0 ) {
                l = pref_prod[i  - 1];
            }
            if( i + 1 < m*n ){
                r = suff_prod[i + 1];
            }

            result[row][col] = (l * r)%mod; 
            col++;
            if(col == n ) {
                row++;
                col =0 ; 
            }
            
        }
        return result;
    }
};