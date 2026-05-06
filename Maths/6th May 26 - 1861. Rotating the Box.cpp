// 1861. Rotating the Box


class Solution {
public:
int m , n; 
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        m = boxGrid.size();
        n = boxGrid[0].size();

        vector<vector<char>> result(n , vector<char> (m, '.'));
     
        for(int row = 0 ; row < m; row++){
            int i = n - 1; 
            for(int col = n-1 ; col >= 0 ;col--){
                if(boxGrid[row][col] == '#'){
                    result[i][m - row - 1 ] = '#';
                    i--;
                }
                else if(boxGrid[row][col] == '*'){
                    result[col][m - row - 1] = '*';
                    i = col - 1; 
                }
            }
        }
        return result; 
    }
};