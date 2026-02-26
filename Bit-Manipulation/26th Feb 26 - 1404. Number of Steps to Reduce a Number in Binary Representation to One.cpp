// 1404. Number of Steps to Reduce a Number in Binary Representation to One


class Solution {
public:
    int numSteps(string s) {
        int n = s.length();
        int result = 0 ; 

        while(s.length() > 1){
            if(s.back() == '0'){
                  s.pop_back();
                  result++;
            } 
            else {
                int i = s.length()-1;
                while(i >= 0 && s[i] == '1'){
                    s[i] = '0'; 
                    i--;
                }
                if(i < 0 ) s = '1' + s; 
                else s[i] = '1';
                 result++;

            }
        } 
        return result; 
    }
};