// 3296. Minimum Number of Seconds to Make Mountain Height Zero


class Solution {
public:
using ll = long long ; 
int n ; 

bool isPossible(int mh , vector<int> &wt , ll mid){

    for(int i = 0 ; i  < n; i++){
       ll x = (sqrt(1 + (8LL * mid) / wt[i]) - 1) / 2;

        if(x <= mid){
            mh -= x; 
            if(mh <= 0 ) return true; 
        }
        else {
            return false; 
        }
    }
    return mh <= 0; 
}

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        n = workerTimes.size();

        sort(begin(workerTimes), end(workerTimes));

        ll l = 1; 
        ll r = (((ll)mountainHeight  * (mountainHeight  + 1))/2) *(ll) workerTimes[0];

        ll result = r; 

        while(l <= r){
            ll mid = l + (r-l)/2;
            if(isPossible(mountainHeight, workerTimes, mid)){
                result = mid ; 
                r = mid - 1; 
            }
            else l = mid + 1; 
        }
        return result; 
    }
};