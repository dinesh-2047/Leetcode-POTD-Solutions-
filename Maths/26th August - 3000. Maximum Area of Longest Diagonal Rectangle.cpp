// 3000. Maximum Area of Longest Diagonal Rectangle

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int result  = 0 ; 
        int resultDiagonal = 0 ;
        for(auto &d : dimensions){
            int l = d[0];
            int w = d[1];
            int currDiagonal = l*l + w*w;
             if(currDiagonal > resultDiagonal){
                  result = l * w;
                  resultDiagonal = currDiagonal ; 
             }
             if(currDiagonal == resultDiagonal){
                result = max(result , l  *w);
             }
           
        }
        return result; 
    }
};