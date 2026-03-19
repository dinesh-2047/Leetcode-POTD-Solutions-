// 3212. Count Submatrices With Equal Frequency of X and Y


class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int result = 0;

        vector<vector<int>> pref_x(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'X') {
                    pref_x[i][j] = 1;
                } else
                    pref_x[i][j] = 0;
                if (i - 1 >= 0) {
                    pref_x[i][j] += pref_x[i - 1][j];
                }
                if (j - 1 >= 0) {
                    pref_x[i][j] += pref_x[i][j - 1];
                }

                if (i - 1 >= 0 && j - 1 >= 0) {
                    pref_x[i][j] -= pref_x[i - 1][j - 1];
                }
            }
        }

        vector<vector<int>> pref_y(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'Y') {
                    pref_y[i][j] = 1;
                } else
                    pref_y[i][j] = 0;
                if (i - 1 >= 0) {
                    pref_y[i][j] += pref_y[i - 1][j];
                }
                if (j - 1 >= 0) {
                    pref_y[i][j] += pref_y[i][j - 1];
                }

                if (i - 1 >= 0 && j - 1 >= 0) {
                    pref_y[i][j] -= pref_y[i - 1][j - 1];
                }
            }
        }

        for(int r = 0 ; r < m; r++){
            for(int c = 0 ; c  < n; c++){
                int x_freq = pref_x[r][c];
                int y_freq = pref_y[r][c];

                if(x_freq != 0 && x_freq == y_freq) result++;
            }
        }
        return result; 
    }
};
