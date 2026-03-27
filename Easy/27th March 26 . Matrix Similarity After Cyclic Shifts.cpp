// 2946. Matrix Similarity After Cyclic Shifts

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>>temp = mat; 

        for(int i = 0 ;i  < m; i++){
            for(int j = 0 ; j  < n; j++){
                if(mat[i][j] != mat[i][(j+k)%n]) return false; 
            }
        }

        return true; 
    }
};