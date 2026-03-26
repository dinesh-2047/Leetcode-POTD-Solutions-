// 3548. Equal Sum Grid Partition II

class Solution {
public:
    using ll = long long;
    ll total = 0;
   
    bool hor_solve(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        unordered_set<ll> st;
        ll sum = 0;
        for (int i = 0; i < m-1; i++) {
            for (int j = 0; j < n; j++) {
                st.insert(grid[i][j]);
                sum += grid[i][j];
            }

            ll l = sum; 
            ll r = total - sum ;

            if(l == r) return true; 

            ll diff = l - r; 
           if (diff ==(ll) grid[0][0]) return true;
            if (diff == (ll)grid[0][n-1]) return true;
            if (diff ==(ll) grid[i][0]) return true;

            
           if(i > 0 && n > 1 && st.count(diff)) {
                return true;
            }
        }
     return false; 

    }



    bool canPartitionGrid(vector<vector<int>>& grid) {
        int  m = grid.size();
         int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }

        if (hor_solve(grid)) return true; 

        reverse(begin(grid), end(grid)) ; 
        if(hor_solve(grid)) return true; 

        vector<vector<int>> temp(n, vector<int>(m));
        for(int i = 0 ; i  < m ; i++){
            for(int j = 0 ; j < n; j++){
                  temp[j][i] = grid[i][j];
            }
        } 
        if(hor_solve(temp)) return true; 

        reverse(begin(temp), end(temp));
        if(hor_solve(temp)) return true; 
        return false; 
    }
};