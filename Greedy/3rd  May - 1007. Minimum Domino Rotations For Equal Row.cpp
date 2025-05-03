// 1007. Minimum Domino Rotations For Equal Row


// Approach 1 
class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            int n = tops.size();
    
            unordered_map<int ,int>mp1;
            unordered_map<int , int>mp2; 
    
            for(int i = 0 ; i<n; i++){
                if(tops[i]!=bottoms[i]){
                mp1[tops[i]]++;
                mp2[bottoms[i]]++;
                }
            }
    
    
            int result = 0 ;
            int temp1 = 0 ; 
            int temp2 = 0 ; 
             
             int maxCountNum = 0 ; 
             int count = 0 ; 
            for(auto &pair : mp1) {
               int num = pair.first; 
               int cnt = pair.second; 
    
               if(cnt > count) {
                  count = cnt ; 
                  maxCountNum = num ;
               }
            }
    
            if(count == 0 )return 0 ;
            
            int sameFreq1 = 0 ; 
            for(int i = 0 ; i<n; i++){
                if(tops[i]==maxCountNum && tops[i]==bottoms[i]) sameFreq1++;
            }
    
            for(auto &pair : mp2){
                int num = pair.first; 
                int cnt = pair.second ; 
    
                if(maxCountNum == num ){
                    if(cnt >= n - count - sameFreq1){
                        temp1 = n - count - sameFreq1; 
                        break; 
                    }
                }
            }
    
    
            maxCountNum = 0 ; 
            count = 0 ; 
            for(auto &pair : mp2){
                int num = pair.first; 
                int cnt = pair.second; 
    
    
                if(cnt > count){
                    maxCountNum = num ; 
                    count = cnt ; 
                }
            }
    
            
            int sameFreq2 = 0 ; 
            for(int i = 0 ; i<n; i++){
                if(tops[i] == maxCountNum && tops[i]==bottoms[i]) sameFreq2++;
            }
    
            for(auto &pair : mp1){
                int num = pair.first; 
                int cnt = pair.second ; 
    
                if(num == maxCountNum ){
                    if(cnt >= n - count-sameFreq2){
                        temp2 = n-count-sameFreq2; 
                        break; 
                    }
                }
            }
             
             if(temp1 == 0 && temp2  == 0 ) return -1;
             if(temp2 == 0 && temp1 != 0 ) return temp1;
            if(temp1 == 0 && temp2 != 0 ) return temp2;
            result = min(temp1 , temp2 );
            return result; 
    
        }
    };



    //Approach 2 
    class Solution {
        public:
            int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
                int n = tops.size();
                  int totalSwapCount = 0 ; 
                  int swapCountTop = INT_MAX ; 
                  int swapCountBottom = INT_MAX; 
        
                for(int num = 1;  num <=6; num++){
                    
                    int swaps = 0;
                    bool valid = true; 
                    for(int i = 0 ; i<n; i++){
                        if(tops[i]!=num && bottoms[i]!=num){
                          valid = false; 
                           break ;
                        } 
                        if(tops[i] == num ) continue; 
                        if(tops[i] != num && bottoms[i] == num ) swaps++;
                    }
                   if(valid) swapCountTop = min(swapCountTop, swaps);
                }
        
        
        
                 for(int num = 1;  num <=6; num++){
                  
                      int swaps  = 0 ; 
                      bool valid = true; 
                    for(int i = 0 ; i<n; i++){
                        if(tops[i]!=num && bottoms[i]!=num) {
                           valid = false; 
                             break; 
                        } 
                        if(bottoms[i] == num) continue; 
                      
                        if(bottoms[i] != num && tops[i] == num ) swaps++;
                    }
                   if(valid) swapCountBottom = min(swapCountBottom , swaps);
                }
         
         
                totalSwapCount = min(swapCountTop, swapCountBottom);
        
                return totalSwapCount == INT_MAX ? -1 : totalSwapCount ;
            }
        };



        //Approach 3 
        class Solution {
            public:
            int n ; 
            int countSwaps(vector<int> &tops, vector<int> &bottoms , int num ){
                int swapCountTop = 0 ; 
                    int swapCountBottom = 0 ;
            
                    for(int i = 0 ; i <n; i++){
                        if(tops[i] != num && bottoms[i] != num )return -1; 
                        if(tops[i] == num && bottoms[i] != num ) {
                            swapCountBottom++;
                        }
                        if(tops[i]!=num && bottoms[i] == num ) swapCountTop++;
                    }
                    return min(swapCountTop , swapCountBottom );
            }
            
            
            
                int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
                     n = tops.size();
            
                    int result = INT_MAX; 
                    
            
                    for(int num = 1; num <= 6 ; num++){
                        int swaps = countSwaps(tops , bottoms ,num );
                        
                        if(swaps != -1 ) result = min(swaps , result);
                        
                    }
            
                    return result == INT_MAX ? -1 : result; 
                }
            };