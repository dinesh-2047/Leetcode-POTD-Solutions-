// 2965. Find Missing and Repeated Values

// Approach 1 
class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = grid.size();
            vector<int>freq((n*n)+1,0);
            vector<int>ans(2);
    
            for(int i = 0 ; i<n; i++){
                for(int j = 0 ; j<n; j++){
                    freq[grid[i][j]]++;
                }
            }
    
            for(int i = 1 ; i<freq.size() ;i++){
                if(freq[i]==2) ans[0] = i;
                else continue; 
            }
    
            for(int i = 1 ; i<freq.size(); i++){
                if(freq[i] == 0){
                    ans[1] = i;
                    break;
                } 
            }
            return ans; 
        }
    };


    // Approach 2 --

    class Solution {
        public:
            vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
                int n = grid.size();

                long long N = n*n;
        
                long long gridSum   = 0;
                long long gridSqSum = 0;
        
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++) {
                        gridSum += grid[i][j];
                        gridSqSum += grid[i][j]*grid[i][j];
                    }
                }
        
                long long sum   = (N * (N+1))/2; //Expected sum of N natural numbers
                long long sqSum = (N * (N+1) * (2*N+1))/6; //Expected sq sum of natural numbers
        
                int sqDiff  = gridSqSum - sqSum;
                int sumDiff = gridSum - sum;
        
                int a = (sqDiff/sumDiff + sumDiff)/2; 
                int b = (sqDiff/sumDiff - sumDiff)/2;
        
                return {a, b};
            }
        };
        