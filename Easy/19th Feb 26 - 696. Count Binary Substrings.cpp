// 696. Count Binary Substrings

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();

        int curr = 1 ; 
        int prev = 0 ; 
        int result = 0 ;

        for(int i = 1; i < n; i++){
            if(s[i] == s[i - 1]) curr++;
            else {
                prev = curr;
                curr = 1;  
            }
            if(curr <= prev) result++;
        }
        return result; 
    }
};