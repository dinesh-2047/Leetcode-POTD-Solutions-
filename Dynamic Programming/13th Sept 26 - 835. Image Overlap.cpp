// 835. Image Overlap


class Solution {
public:
int n; 
int countOverlapping(vector<vector<int>> &img1, vector<vector<int>> &img2, int row_offset, int col_offset){
    int count = 0;
    for(int i = 0 ; i < n ;i++ ){
        for(int j = 0 ;j < n; j++){
            if(i+row_offset < 0 || i + row_offset >=n || j + col_offset < 0  || j + col_offset >= n ) continue ; 

            count += img1[i][j] * img2[i + row_offset][j + col_offset];
        }
    }
    return count;
}
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        n = img1.size() ;

        int result = 0; 

        for(int row_offset = -n + 1; row_offset < n ; row_offset++ ){
            for(int col_offset = - n + 1; col_offset < n; col_offset++){
                result = max(result, countOverlapping(img1, img2, row_offset, col_offset));
            }
        }
        return result;
    }
};