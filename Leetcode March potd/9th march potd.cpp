// 3208. Alternating Groups II

// Approach 1 TLE
class Solution {
    public:
    bool isAlternate(vector<int> &colors, int start , int k ){
        int n = colors.size();
    
        
        for (int i = start; i < start + k - 1; i++) { 
            if (colors[i%n] == colors[(i + 1)%n]) return false;
        }
        return true;
    }
    
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int n = colors.size();
           int ans = 0 ; 
            for(int i = 0 ; i<n; i++){
                
               if(isAlternate(colors, i , k )){
                       ans++;
               }
            }
            return ans; 
        }
    };



// Approach 2
class Solution {
    public:
    
    
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int n = colors.size();
    
            for(int i = 0 ; i<k; i++) colors.push_back(colors[i]);
           int i = 0 ; 
           int j = 0 ;
           int ans = 0; 
    
           while(j<n+k-1 ){
            if(colors[j] == colors[j+1]) {
                  i= j;
            } 
              if(j-i + 1 == k){
                 ans++;
                 i++;
              }
              j++;
                
           }
           return ans; 
        }
    };

// Approach 3
class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int n = colors.size();
            
    
            for(int i = 0 ; i<k; i++){
                colors.push_back(colors[i]);
            }
    
          
            int len = 1  ; 
            int ans = 0 ; 
    
           for(int i = 0 ; i< n+k-2; i++){
               if(colors[i]==colors[i+1]) {
                 len = 1; 
    
               }
               if(colors[i] != colors[i+1]) len++;
    
               if(len >= k ) ans++;
           }
           return ans; 
        }
    };