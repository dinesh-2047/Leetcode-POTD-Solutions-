// 3464. Maximize the Distance Between Points on a Square


class Solution {
public:
using ll = long long; 
ll get_slp(int x , int y , int side){
        if(y == 0 ) return x; 
        if(x == side) return side + y; 
        if( y == side) return 3LL * side - x; 
        else return 4LL * side - y; 
}

bool isPossible(vector<ll> &vec, ll mid , int k, int side){
    int n = vec.size();
    
    for(int start = 0 ; start < n; start++){
          int count = 1 ; 
          int last = start;
          
          while(count < k ){
              ll target = vec[last] + mid; 
              int idx = lower_bound(begin(vec),end(vec), target ) - begin(vec);
              if(idx == n) break; 

              last = idx ; 
              count++;

          }
           if(count >= k && (( vec[start] + 4LL * side) - vec[last] )>= mid ) return true; 
    }
    return false;
}


    int maxDistance(int side, vector<vector<int>>& points, int k) {
        
        vector<ll> vec; 

        for(auto &point : points){
            int x = point[0];
            int y = point[1];

            ll slp = get_slp(x, y, side) ;// slp  -> staright line postion 
            vec.push_back(slp);
        }

        sort(begin(vec), end(vec));

        ll l = 0; 
        ll r = 4LL * side; 
        ll result = 0 ;

        while( l<= r){
            ll mid = l + ( r- l)/2; 
            if(isPossible(vec, mid, k, side)){
                result = mid; 
                l = mid + 1; 
            }
            else r = mid - 1; 
        }
        return result; 

    }
};