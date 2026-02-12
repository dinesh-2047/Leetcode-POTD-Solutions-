// 3713. Longest Balanced Substring I



class Solution {
public:
bool isBalanced(vector<int> &freq){
    int prev = -1; 
    for(int i = 0 ; i < 26; i++){
        if(freq[i] == 0 ) continue; 
        if(prev != -1 && freq[i] != freq[prev]) return false; 
        prev = i ;
    }
    return true; 
}

    int longestBalanced(string s) {
        int n = s.length();
        
        int result = 0 ;
        for(int i = 0 ; i < n; i++){
            vector<int>freq(26, 0);
            for(int j = i; j  < n; j++){
                freq[s[j] -'a']++;
                if(isBalanced(freq)) result = max(result, j - i + 1);
            }
        }
        return result; 

    }
};