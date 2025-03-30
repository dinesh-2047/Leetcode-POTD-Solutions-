// 763. Partition Labels/


// Approach 1 /

class Solution {
    public:
        vector<int> partitionLabels(string s) {
            int n = s.length();
             vector<int>ans; 
           unordered_map<char, int>last; 
    
           for(int i = 0 ; i<n; i++){
             last[s[i]] = i;
           }
    
           for(int i = 0 ; i<n; i++){
              int end = last[s[i]];
              for(int j = i ; j<end; j++){
                 if(last[s[j]] > end) end= last[s[j]];
                
              }
               
              ans.push_back(end-i+1);
              i = end;
    
           }
           return ans; 
        }
    };