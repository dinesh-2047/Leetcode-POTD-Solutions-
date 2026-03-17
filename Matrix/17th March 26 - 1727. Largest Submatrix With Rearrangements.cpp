// 1727. Largest Submatrix With Rearrangements


class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        
        int result = 0 ; 

        vector<pair<int , int>>prevHeight; // height , col

        for(int i = 0 ; i  < m; i++){

            vector<pair<int, int>>currHeight; 
            vector<bool>seen(n, false);

            for(auto [height , col] : prevHeight){
                if(matrix[i][col] == 1){
                currHeight.push_back({height + 1, col});
                seen[col] = true; 
                }
            }

            for(int j = 0 ; j< n; j++){
                if(!seen[j] && matrix[i][j] == 1){
                    seen[j] = true; 
                    currHeight.push_back({1, j});
                }
            }

            for(int j = 0 ; j  < currHeight.size(); j++){
                int h = currHeight[j].first; 
                int b = j + 1; 

                result = max(result , h * b);
            }
            prevHeight = currHeight; 
        }
        return result; 

    }
};