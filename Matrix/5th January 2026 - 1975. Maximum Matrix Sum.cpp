// 1975. Maximum Matrix Sum

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int countNeg = 0 ; 

        long long result = 0 ; 
          int mini = INT_MAX;
        for(int i = 0 ; i  < n; i++){
            for(int j = 0 ; j < n; j++){
                if(matrix[i][j] < 0 ) countNeg++;
                result += abs(matrix[i][j]);
                mini = min(mini, abs(matrix[i][j]));
            }
        }

        if(countNeg%2 == 0  ) return result; 
        return result - 2* mini; 
    }
};