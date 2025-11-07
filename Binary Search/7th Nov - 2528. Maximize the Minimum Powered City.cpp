// 2528. Maximize the Minimum Powered City



class Solution {
public:
vector<long long>diff;
int n ;
bool isPossible(int r , int k , long long mid){
    vector<long long>pref = diff; 

    for(int i = 0 ; i < n; i++){
        if(i-1 >= 0 ){
         pref[i] = pref[i - 1] + pref[i];
        }
        if(pref[i] < mid){
            long long req = mid - pref[i];
            if(req > k ){
                return false; 
            }
            k-=req; 
            pref[i] += req; 

            if(i + 2 * r + 1 < n ){
                pref[i+2*r + 1] -= req; 
            }
        }
        
    }
    return true; 
   
}


    long long maxPower(vector<int>& stations, int r, int k) {
         n = stations.size();
     
       diff.assign(n , 0);

       for(int i = 0 ; i  < n; i++){
        diff[max(0, i-r)] += stations[i];
        if(i + r + 1 < n){
            diff[i + r + 1] -= stations[i];
        }
       }

        long long left = *min_element(begin(stations), end(stations));
        long long right = accumulate(begin(stations), end(stations),1LL  * 0)  + k ; 

        long long result = 0 ; 

        while(left <= right){
            long long  mid = left  + (right-left)/2;
            if(isPossible(r, k , mid)) {
                result = mid ; 
                left = mid + 1; 
            }
            else right = mid - 1; 
        }
        return result; 
    }
};