// 1784. Check if Binary String Has at Most One Segment of Ones

class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();

        bool isOnePresent = false; 
        for(int i = n - 1; i  >= 0 ; i--){
            if(s[i] == '1') isOnePresent = true; 
            if(s[i] == '0' && isOnePresent) return false; 
        }
        return true; 
    }
};