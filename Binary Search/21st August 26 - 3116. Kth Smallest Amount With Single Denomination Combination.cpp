// 3116. Kth Smallest Amount With Single Denomination Combination

class Solution {
public:
using ll = long long  ; 
int n ; 
bool isPossible(vector<int> &coins, ll mid , int k){
    ll c = 0 ;
    for(int exp = 1; exp <= (1<<n)-1; exp++){
        int order = 0 ; 
        ll LCM = 0 ;
        for(int i = 0 ; i  < n; i++){
            if(exp &(1<<i)){
                order++;
                if(LCM == 0){
                    LCM = coins[i];
                }
                else {
                    LCM = (LCM * coins[i])/gcd(LCM, (ll)coins[i]);
                }
            }
        }
        if(order%2 == 0 ){
             c-=mid/LCM; 
        }
        else c += mid/LCM; 
    }
    return c >= k ;
}

    long long findKthSmallest(vector<int>& coins, int k) {
        n = coins.size();

        ll l = 1; 
        ll r = *max_element(begin(coins), end(coins)) *1LL * k; 
        ll result = 0 ;
        while(l <= r){
            ll mid = l + (r-l)/2; 
            if(isPossible(coins, mid, k)){
                result = mid ; 
                r = mid - 1; 
            }
            else l = mid + 1; 
        }
        return result; 
    }
};