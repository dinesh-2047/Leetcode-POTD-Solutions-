// 1189. Maximum Number of Balloons

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>freq (26, 0);

        for(auto &t : text){
            freq[t-'a']++;
        }

        string s = "balloon";
        for(int i = 0 ; i < s.length(); i++){
            if(freq[s[i] - 'a'] == 0 ) return 0; 
            else if(s[i] == 'l' && freq[s[i] -'a'] < 2) return 0 ; 
            else if(s[i] == 'o' && freq[s[i] - 'a'] < 2) return 0 ; 
        }
        freq['l' - 'a']/=2; 
        freq['o' - 'a']/=2; 
        int result = INT_MAX ; 
       for(auto &ch : s){
           result = min(result, freq[ch - 'a']);
       }
       return result; 
    }
};