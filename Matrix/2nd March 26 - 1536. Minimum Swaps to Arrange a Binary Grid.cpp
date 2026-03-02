// 1536. Minimum Swaps to Arrange a Binary Grid

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int>endZeros(n,0);

        for(int i = 0 ; i < n; i++){
            int count = 0 ; 
            for(int j = n-1; j >= 0; j--){
                if(grid[i][j] == 1) break; 
                count++;
            }
            endZeros[i] = count; 
        }
        int result = 0 ; 
        for(int i = 0 ; i  < n; i++){
            int need = n - i - 1; 
            int j = i ; 
            while(j < n && endZeros[j] < need){
                j++;
            }
            if(j == n ) return -1; 
            result += j- i; 

            while( j > i ){
                swap(endZeros[j], endZeros[j - 1]);
                    j--;
                
            }
        }
        return result; 


    }
};