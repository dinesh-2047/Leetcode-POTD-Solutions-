// 2536. Increment Submatrices by One


class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>diff(n, vector<int>(n, 0));
        for(auto &query : queries){
            int r1 = query[0];
            int c1 = query[1];
            int r2 = query[2];
            int c2 = query[3];

            for(int i = r1 ; i<= r2; i++){
                 diff[i][c1]++;
                 if(c2 + 1 < n ){
                    diff[i][c2 + 1]--;
                 }
            }
        }

        for(int i= 0 ; i < n; i++){
            for(int j = 1; j < n; j++){
                diff[i][j] += diff[i][j-1] ;
            }
        }
        return diff;
    }
};