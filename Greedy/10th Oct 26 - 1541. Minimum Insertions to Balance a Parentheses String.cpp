// 1541. Minimum Insertions to Balance a Parentheses String

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();

        int result = 0;
        int o = 0 ; 

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                o++;
            } else {
                if (i + 1 < n && s[i + 1] == ')') {
                    if (o>0) { 
                        o--;
                    } else {
                        result++; 
                    }
                    i++;
                } else if (i + 1 < n && s[i + 1] == '(') {
                    if (o>0) {
                        o--;
                        result++;
                    } else {
                        result += 2;
                    }
                }
                else {
                    if(o==0) {
                        result += 2; 
                    }
                    else {
                        o--;
                        result++;
                    }
                }
            }
        }
       result += o * 2; 
        return result;
    }
};