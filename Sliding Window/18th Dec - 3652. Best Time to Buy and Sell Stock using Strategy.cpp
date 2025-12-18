// 3652. Best Time to Buy and Sell Stock using Strategy

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        vector<long long>profit(n);


        long long actualProfit = 0 ; 
        for(int i = 0 ; i  <  n ; i++){
            profit[i] = 1LL * prices[i] * strategy[i];
            actualProfit += profit[i];
        }

        int i = 0 ; 
        int j = 0 ; 

        long long modifiedWindowProfit = 0 ; 
        long long originalWindowProfit = 0 ;
        long long maxGain = 0 ; 

        while( j < n ){
            originalWindowProfit  += profit[j];

            if(j - i + 1 > k/2){
                modifiedWindowProfit += prices[j];
            }
            if(j - i + 1 > k ){
                originalWindowProfit -= profit[i];
                modifiedWindowProfit -= prices[i + k/2];
                i++;
            }
            if(j - i +1  == k ){
                maxGain = max(maxGain  ,modifiedWindowProfit - originalWindowProfit );
            }
          j++;
        }
        return actualProfit + maxGain; 
    }
};