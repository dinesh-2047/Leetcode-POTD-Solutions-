// 3568. Minimum Moves to Clean the Classroom

struct Node {
    int r;
    int c;
    int e;
    int clMask; // cl mask
};

class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].length();

        int maxE = energy;

        int litterBit[20][20];

        int sti = 0;
        int stj = 0;

        int bitPos = 0;
        int litterCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                litterBit[i][j] = -1;
                if (classroom[i][j] == 'S') {
                    sti = i;
                    stj = j;
                }
                if (classroom[i][j] == 'L') {
                    litterBit[i][j] = litterCount;
                    litterCount++;
                }
            }
        }

        int allCollected = (1 << litterCount) - 1;
        if (litterCount == 0)
            return 0;

        vector<vector<vector<vector<int>>>> visited(m,vector<vector<vector<int>>>(n, vector<vector<int>>(maxE + 1, vector<int>(1 << litterCount, false))));

        queue<Node> q;
        q.push({sti, stj, maxE, 0});

        visited[sti][stj][maxE][0] = true;

        int moves = 0;

        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                Node curr = q.front();
                q.pop();

                if (curr.clMask == allCollected)
                    return moves;
                if (curr.e == 0)
                    continue;

                for (auto& dir : directions) {
                    int newi = curr.r + dir[0];
                    int newj = curr.c + dir[1];

                    if (newi < 0 || newi >= m || newj < 0 || newj >= n)
                        continue;

                    char cell = classroom[newi][newj];

                    if (cell == 'X')
                        continue;

                    int nextE = curr.e - 1;
                    int nextMask = curr.clMask;

                    if (cell == 'R') {
                        nextE = maxE;
                    } else if (cell == 'L') {
                        nextMask |= (1 << litterBit[newi][newj]);
                    }

                    if (!visited[newi][newj][nextE][nextMask]) {
                        visited[newi][newj][nextE][nextMask] = true;
                        q.push({newi, newj, nextE, nextMask});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};