// 2226. Maximum Candies Allocated to K Children


// Approach 1 brute force TLE 
class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            int n= candies.size();
    
            int maxC = 0;
            for(int i = 0;i<n; i++){
                maxC = max(maxC , candies[i]);
            }
    
            for(int c = maxC ; c>=1; c--){
                long long count = 0 ; 
                for(int i = 0 ; i<n; i++){
                    count += candies[i]/c; // how many children can get c candies from this pile
                }
                if(count>=k) return c; 
            }
            return 0 ; 
        }
    };


// Optimized approach using binary search 
class Solution {
    public:
    bool canDistribute(int mid , long long  k , vector<int>candies){
         int n = candies.size();
         long long count = 0 ;
         for(int i = 0; i < n; i++ ){
             count += candies[i]/mid; 
         }
         if(count>=k) return true; 
         return false; 
    }
    
        int maximumCandies(vector<int>& candies, long long k) {
            int n= candies.size();
    
            int maxC = 0;
            for(int i = 0;i<n; i++){
                maxC = max(maxC , candies[i]);
            }
    
           int l = 1;
           int r = maxC;
           int result = 0  ; 
    
           while(l<=r){
            int mid = l + (r-l)/2;
    
              if(canDistribute(mid, k, candies)){
                result = mid;
                l = mid + 1;
              }
              else r = mid-1;
           } 
           return result ; 
        }
    };