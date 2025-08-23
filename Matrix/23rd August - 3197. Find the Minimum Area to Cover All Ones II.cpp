// 3197. Find the Minimum Area to Cover All Ones II


class Solution {
public:
int minArea(int rowSt, int rowEnd , int colSt , int colEnd, vector<vector<int>> &grid){
     int minRow = rowEnd ; 
     int minCol = colEnd ; 
     int maxRow = rowSt ; 
     int maxCol = colSt; 

     for(int i = rowSt ; i < rowEnd; i++){
        for(int j = colSt; j < colEnd ; j++){
            if(grid[i][j] == 1 ){
                minRow = min(minRow , i);
                minCol = min(minCol , j);
                maxRow = max(maxRow , i);
                maxCol = max(maxCol , j);
                
            }
        }
     }

     int l = (maxRow - minRow + 1) ;
     int b = (maxCol - minCol + 1);

     return l *b;
}


    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result = INT_MAX; 

        //case 1 and case 2 
        for(int rowSplit = 1 ; rowSplit < m ; rowSplit++){
            for(int colSplit =  1 ; colSplit < n ; colSplit++){
                int top = minArea(0, rowSplit , 0 , n , grid);
                int bottomLeft = minArea(rowSplit , m , 0 , colSplit, grid);
                int bottomRight = minArea(rowSplit   , m , colSplit , n, grid);
                result = min(result , (top + bottomLeft + bottomRight));

                int topLeft = minArea(0 , rowSplit , 0, colSplit, grid); 
                int topRight = minArea(0 , rowSplit , colSplit , n, grid);
                int bottom = minArea(rowSplit , m , 0 , n, grid);
                 result = min(result , (topLeft+ topRight + bottom));

            }
        }

        for(int rowSplitOne = 1 ; rowSplitOne < m ; rowSplitOne++){
            for(int rowSplitTwo = rowSplitOne + 1; rowSplitTwo < m;rowSplitTwo++){
                int top = minArea(0, rowSplitOne , 0 , n,  grid);
                int mid = minArea(rowSplitOne , rowSplitTwo , 0 , n, grid);
                int bottom = minArea(rowSplitTwo , m , 0 , n, grid);

                result = min(result , (top + mid + bottom));
            }
        }
    
        vector<vector<int>>rotatedGrid(n , vector<int>(m));
       
        for(int i = 0;i < m; i++){
            for(int j = 0 ; j  < n ;j++){
                rotatedGrid[j][m-i-1] = grid[i][j];
            }
        }
         swap(n , m);
          for(int rowSplit = 1 ; rowSplit < m ; rowSplit++){
            for(int colSplit =  1 ; colSplit < n ; colSplit++){
                int top = minArea(0, rowSplit , 0 , n , rotatedGrid);
                int bottomLeft = minArea(rowSplit , m , 0 , colSplit, rotatedGrid);
                int bottomRight = minArea(rowSplit   , m , colSplit , n, rotatedGrid);
                result = min(result , (top + bottomLeft + bottomRight));

                int topLeft = minArea(0 , rowSplit , 0, colSplit, rotatedGrid); 
                int topRight = minArea(0 , rowSplit , colSplit , n, rotatedGrid);
                int bottom = minArea(rowSplit , m , 0 , n, rotatedGrid);
                 result = min(result , (topLeft+ topRight + bottom));

            }
        }

        for(int rowSplitOne = 1 ; rowSplitOne < m ; rowSplitOne++){
            for(int rowSplitTwo = rowSplitOne + 1; rowSplitTwo < m;rowSplitTwo++){
                int top = minArea(0, rowSplitOne , 0 , n, rotatedGrid);
                int mid = minArea(rowSplitOne , rowSplitTwo , 0 , n, rotatedGrid);
                int bottom = minArea(rowSplitTwo , m , 0 , n, rotatedGrid);

                result = min(result , (top + mid + bottom));
            }
        }
        return result; 


    }
};