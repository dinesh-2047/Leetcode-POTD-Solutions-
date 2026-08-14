// 3090. Maximum Length Substring With Two Occurrences

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();

        vector<int> freq(26, 0);

        int i = 0 ; 
        int j = 0; 

        int result = 0 ; 

        while(j < n ){
            freq[s[j] - 'a']++;
            while(i<j && freq[s[j] -'a'] > 2){
                freq[s[i]-'a']--;
                i++;
            }
        
            result = max(result, j - i + 1);
            j++;
        }
        return result; 
    }
};