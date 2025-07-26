// 3480. Maximize Subarrays After Removing One Conflicting Pair



#define maxx(x) *max_element(begin(x), end(x))
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        
       unordered_map<int , list<int>>conflictPoints;

        for(auto &p : conflictingPairs){
            int a = min(p[0], p[1]);
            int b = max(p[0], p[1]);

            conflictPoints[b].push_back(a);
        }

        int maxConflict = 0 ; 
        int secondMaxConflict = 0 ; 
        vector<long long>extra(n+1); 
        long long valid = 0 ; 

        for(int end = 1; end <= n; end++){
            
            for(auto &u : conflictPoints[end]){
                if(u >= maxConflict ){
                    secondMaxConflict = maxConflict; 
                    maxConflict = u ; 
                }
                else if(u >= secondMaxConflict){
                    secondMaxConflict = u ; 
                }
            }
            valid  += end - maxConflict ; 
            extra[maxConflict] += maxConflict - secondMaxConflict; 
        }

        return valid + maxx(extra);
    }
};