// 2145. Count the Hidden Sequences



class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            int n = differences.size();
    
            int curr = 0 ; 
            int minValue = 0 ; 
            int maxValue = 0 ; 
    
    
            for(int i = 0 ; i<n; i++){
                curr = curr + differences[i];
    
                minValue = min(minValue, curr);
                maxValue = max(maxValue , curr);
    
                if((upper - maxValue) - (lower - minValue) + 1 <=0 ) return 0 ;
            }
    
            return (upper - maxValue) - (lower - minValue) + 1 ;
        }
    };