// 799. Champagne Tower

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
       vector<double>prev(1, poured);

       for(int i = 1; i <= query_row; i++){
          vector<double>curr(i + 1);
          for(int j = 0 ; j < i; j++){
             if(prev[j] > 1){
                    double overflow = (prev[j] - 1) / 2.0;
                    curr[j] += overflow;
                    curr[j + 1] += overflow;
                }
          }
          prev = curr; 
       } 
       return min(1.00000, prev[query_glass]);
    }
};