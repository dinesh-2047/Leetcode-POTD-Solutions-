// 1399. Count Largest Group


// Approach 1 

class Solution {
    public:
        int countLargestGroup(int n) {
           unordered_map<int , int>mp ;  
    
           for(int i = 1; i<=n; i++){
               string s = to_string(i);
               
               int sum = 0 ; 
               for(int j = 0 ; j< s.length(); j++){
                    sum += (s[j] - '0');
               }
    
               mp[sum]++;
           }
              unordered_map<int , int>mp2; 
    
              for(auto &pair : mp){
                int sum = pair.first; 
                int len = pair.second; 
                mp2[len]++;
              }
               
               int count = mp2.begin()->second; 
               int maxLength = mp2.begin()->first; 
              for(auto &pair : mp2){
                int len = pair.first; 
                int cnt = pair.second; 
                 if(len > maxLength){
                    maxLength = len; 
                    count = cnt; 
                 }
    
    
              }
              return count;
           
        }
    };



    // Approach 2 one pass with time complexity o(log n)
    class Solution {
        public:
        int findSum(int num){
            int sum = 0 ; 
            while(num > 0){
                 sum += (num %10);
                 num /= 10;
            }
            return sum ;
        }
        
            int countLargestGroup(int n) {
                unordered_map<int , int>mp ;
                int maxLen = 0 ; 
                  int count = 0 ; 
        
        
                  for(int i = 1 ; i <=n; i++){
                    int sum = findSum(i);
                       mp[sum]++;
                    if(mp[sum]==maxLen){
                        
                        count++;
                    }
                    else if(mp[sum] > maxLen){
                        maxLen = mp[sum];
                        count = 1; 
                    }
                   
                  }
                  return count; 
            }
        };