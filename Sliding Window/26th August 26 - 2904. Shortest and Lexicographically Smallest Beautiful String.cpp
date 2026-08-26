// 2904. Shortest and Lexicographically Smallest Beautiful String

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();

        int i = 0 ; 
        int j = 0 ; 

        string result = "";
        int count1 = 0 ; 

        while(j < n ){
            if(s[j] == '1'){
                count1++;
            }

            while(i <= j && count1 == k){
                if(result.empty()) result = s.substr(i, j-i+1);
                else {
                    if(result.length() == j - i + 1){
                        result = min(result, s.substr(i, j - i + 1));
                    }
                    else if(result.length() > j - i + 1){
                        result = s.substr(i, j - i + 1);
                    }
                }
                if(s[i] == '1') count1--;
                i++;
            }
            j++;
        }
        return result; 
    }
};