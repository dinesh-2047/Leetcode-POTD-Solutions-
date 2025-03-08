// 2379. Minimum Recolors to Get K Consecutive Black Blocks

// Approach 1 

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int n = blocks.length();
            int minOpr = 1e9;
    
            for(int i = 0 ; i<=n-k; i++){
                string str = blocks.substr(i, k );
                int op = 0;
                for(int j = 0 ; j <str.length(); j++){
                    if(str[j] == 'B') continue; 
                    if(str[j] == 'W') {
                        op++;
                       
                    }
                }
                 minOpr = min(minOpr, op);
            }
            return minOpr;
        }
    };

    // Approach 2 

    class Solution {
        public:
            int minimumRecolors(string blocks, int k) {
                int n = blocks.size();
        
                int minOpr = 1e9;
                int white = 0 ; 
                int i = 0 ; 
                int j = 0 ; 
        
                while(j<n){
                    if(blocks[j] == 'W') white++;
        
                    if(j-i+1 == k ) {
                        minOpr = min(minOpr, white);
                        if(blocks[i] == 'W') {
                            white--;
                        }
                        i++;
                    }
                    
                      j++;
                }
                return minOpr;
            }
        };