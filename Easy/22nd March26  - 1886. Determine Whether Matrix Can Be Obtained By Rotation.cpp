// 1886. Determine Whether Matrix Can Be Obtained By Rotation

class Solution {
public:
    bool isEqual(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[i][j])
                    return false;
            }
        }
        return true;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        for (int rot = 0; rot < 4; rot++) {
            for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                    swap(mat[i][j], mat[j][i]);
                }
            }
            for (int i = 0; i < n; i++) {
                reverse(begin(mat[i]), end(mat[i]));
            }

            if (isEqual(mat, target))
                return true;
        }
        return false;
    }
};