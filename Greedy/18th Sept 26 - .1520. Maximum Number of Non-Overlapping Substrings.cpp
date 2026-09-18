// 1520. Maximum Number of Non-Overlapping Substrings

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();

        vector<string> result; 

        vector<int> start(26, -1);
        vector<int> end(26, -1);

        vector<bool> isValid(26, true);

        for(int i = 0 ; i < n; i++){
            if(start[s[i] - 'a'] == -1){
                start[s[i] - 'a'] = i; 
            }
            end[s[i] - 'a'] = i ; 
        }
       
        for(int ch = 0 ; ch < 26 ; ch++){
            if(start[ch] == -1) continue; 

            for(int i = start[ch]; i <= end[ch] ; i++){
                if(start[s[i] - 'a'] < start[ch]){
                    isValid[ch] = false; 
                    break; 
                }
                end[ch] = max(end[ch], end[s[i] - 'a']);
            }
        }

        int lastTakenStart = 1e9; 
        for(int i = n - 1; i >= 0; i--){
            int ch = s[i] - 'a';

            if(!isValid[ch]) continue; 

            if(i == start[ch] && end[ch] < lastTakenStart){
                 result.push_back(s.substr(i, end[ch] - i + 1));
                 lastTakenStart = i ; 
            }
        }
        return result; 
         
    }
};