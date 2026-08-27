// 3720. Lexicographically Smallest Permutation Greater Than Target

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
         int n = s.length() ;

         string pref = "";
         string result = "";
          
          vector<int> freq(26, 0);
          for(auto &ch : s) freq[ch -'a']++;

         for(int i = 0 ;i < n; i++){
             for(char c = target[i] + 1; c <= 'z'; c++){
                 if(freq[c-'a'] > 0 ){
                    string cand = pref; 
                    cand += c; 
                    freq[c-'a']--;

                    for(char ch = 'a'; ch <= 'z'; ch++){
                        cand += string(freq[ch - 'a'], ch);
                    }

                    if(result.empty() || cand < result){
                        result = cand;
                    }
                    freq[c - 'a']++;
                 }
             }
             if(freq[target[i] - 'a'] == 0 ) break; 
             freq[target[i] -'a']--;
             pref += target[i];
         }
         return result; 
    }
};