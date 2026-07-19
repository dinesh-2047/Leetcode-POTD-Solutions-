// 1081. Smallest Subsequence of Distinct Characters

class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();

        vector<int> last(26, 0);
        for(int i = 0 ; i  < n; i++){
            last[s[i] - 'a'] = i; 
        }

        string result = "";
        vector<int> seen(26, 0);
        for(int i = 0 ; i  < n; i++){
            if(seen[s[i] - 'a']) continue; 
            while(!result.empty()&& result.back() >= s[i]){
                if(last[result.back() - 'a'] >= i ){
                    seen[result.back() -'a'] = 0; 
                    result.pop_back();
                }
                else break; 
            }
            
            result += s[i];
            seen[s[i] - 'a'] = 1;
            
        }
        return result;
    }
};