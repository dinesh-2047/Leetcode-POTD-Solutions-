// Substrings with more 1's than 0's

class Solution {
  public:
    int countSubstring(string& s) {
        int n = s.length();
        
        int sum = 0 ; 
        int bs = 0 ; 
        
        int result = 0; 
        
        unordered_map<int , int> mp; 
        mp[0] = 1; 
        
        for(auto &ch : s){
            if(ch == '0'){
                sum--;
                bs-=mp[sum];
            }
            else {
                sum++;
                bs += mp[sum - 1];
            }
            
            result += bs; 
            mp[sum]++;
            
            
        }
        return result; 
        
    }
};