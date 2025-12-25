// 3075. Maximize Happiness of Selected Children


class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();

        long long result  = 0 ; 
        sort(rbegin(happiness), rend(happiness));
        
        for(int i = 0 ; i  < k ; i++){
            result += max(0, happiness[i]-i); 
        }
        return result; 
    }
};