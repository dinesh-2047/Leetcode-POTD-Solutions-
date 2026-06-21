// 1833. Maximum Ice Cream Bars


class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        vector<int> vec(1e5 + 1, 0);
        for(auto &c : costs){
            vec[c]++;
        }
         long long c = 0 ; 
         int result = 0 ; 
        for(int i = 0 ; i < vec.size(); i++){
            if(vec[i] == 0 ) continue; 
            int cdiff = coins - c; 
            int ct = cdiff/i; 
            result += min(ct, vec[i]);
            if(c + (1LL * vec[i] * i) <= coins){
                c += (1LL  * vec[i] * i);
            }
            else if(c + (1LL * ct * i) <= coins){
                c += (1LL  * ct * i );
            }
        }
        return result; 
    }
};