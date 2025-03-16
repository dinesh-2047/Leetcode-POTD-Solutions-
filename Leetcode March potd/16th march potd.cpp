// 2594. Minimum Time to Repair Cars

class Solution {
    public:
    bool isPossible(vector<int> &ranks , int cars , long long  time ){
        long long  canRepair = 0;
       for(int i = 0 ; i< ranks.size(); i++){
          canRepair += sqrt(time/ranks[i]);
       }
        if(canRepair < cars ) return false; 
        else return true; 
    }
    
    
        long long repairCars(vector<int>& ranks, int cars) {
            int n = ranks.size();
    
            long long ans = -1 ; 
    
            long long  l = 1;
            long long  r = (long long )*max_element(ranks.begin(), ranks.end()) * cars * cars ;
    
            while(l<=r){//log(maxRank * cars * cars)
                long long  mid = l + (r-l)/2;
                if(isPossible(ranks , cars, mid )){
                    ans = mid ; 
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            return ans; 
        }
    };
    //T.C: O(n * log(maxRank*cars*cars));
    