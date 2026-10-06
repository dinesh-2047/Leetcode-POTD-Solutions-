// 921. Minimum Add to Make Parentheses Valid

class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();

        int o  = 0 ; 
        int result = 0 ; 

        for(auto &ch : s){
            if(ch == '('){
                o++;
            }
            else {
                if(o == 0) result++;
                else o--;
            }

        }
        return result+o;
    }
};