// 2110. Number of Smooth Descent Periods of a Stock


class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
          int n = prices.size();

          long long result = 1 ; 
          long long count = 1 ; 

          for(int i = 1; i < n; i++ ){
               int diff = prices[i] - prices[i - 1];
               if(diff == -1){
                 count++;
               }
               else {
                  count = 1;
               }
               result += count; 
          }
          return result; 
    }
};