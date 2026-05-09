// 1914. Cyclically Rotating a Grid


class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int row = 0;
        for (int col = 0; col < min(m / 2, n / 2); col++) {
            vector<int> vec;
            //  top row
            for (int j = col; j <= n - col - 1; j++) {
                vec.push_back(grid[row][j]);
            }

            // right col
            for (int i = row + 1; i <= m - row - 2; i++) {
                vec.push_back(grid[i][n - col - 1]);
            }

            // bottom row
            for (int j = n - col - 1; j >= col; j--) {
                vec.push_back(grid[m - row - 1][j]);
            }

            // left col
            for (int i = m - row - 2; i >= row + 1; i--) {
                vec.push_back(grid[i][col]);
            }
            int rot = k % vec.size();
            rotate(begin(vec), begin(vec) + rot, end(vec));

            int v = 0;

            //  top row
            for (int j = col; j <= n - col - 1; j++) {
                grid[row][j] = vec[v++];
            }

            // right col
            for (int i = row + 1; i <= m - row - 2; i++) {
                grid[i][n - col - 1] = vec[v++];
            }

            // bottom row
            for (int j = n - col - 1; j >= col; j--) {
                grid[m - row - 1][j] = vec[v++];
            }

            // left col
            for (int i = m - row - 2; i >= row + 1; i--) {
                grid[i][col] = vec[v++];
            }

            row++;
        }

        return grid;
    }
};
