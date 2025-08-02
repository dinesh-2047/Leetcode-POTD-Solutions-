// 118. Pascal's Triangle


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result;

        for(int i = 0 ; i < numRows; i++ ){
            vector<int>curr(i + 1, 1);
            for(int j = 1 ;j <  i ; j++){
                curr[j] = result[i-1][j-1] + result[i-1][j];
            }
            result.push_back(curr);
        }
        return result;
    }
};