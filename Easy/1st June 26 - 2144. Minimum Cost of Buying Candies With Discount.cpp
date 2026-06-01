// 2144. Minimum Cost of Buying Candies With Discount


class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size() ;

        sort(begin(cost), end(cost));

        int result = 0 ; 
        int buy = 0 ; 
        for(int i = n - 1; i >= 0 ; i--){
              if(buy == 2){
                  buy = 0 ; 
                  continue; 
              }
              else {
                result += cost[i];
                buy++;
              }
        }
        return result; 
    }
};