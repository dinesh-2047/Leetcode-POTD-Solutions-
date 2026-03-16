// 1878. Get Biggest Three Rhombus Sums in a Grid

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
 

        set<int>st; 

        for(int r = 0 ;  r < m; r++){
            for(int c = 0 ; c < n; c++){
                st.insert(grid[r][c]);
                     if(st.size() > 3) st.erase(st.begin());
                for(int s = 1 ; s <= min({r,m-1-r,c,n-1-c}); s++ ){

                    int sum = 0 ; 
                    for(int i = 0 ; i  < s; i++){
                        sum += grid[r-s+i][c+i];
                        sum += grid[r+i][c + s - i];
                        sum += grid[r + s - i][c - i];
                        sum += grid[r - i][c - s + i];
                    }
                     st.insert(sum);
                     if(st.size() > 3) st.erase(st.begin());
                }
               
            }
        }
    
      vector<int>result(rbegin(st), rend(st));
      return result; 

    }
};