// 3228. Maximum Number of Operations to Move Ones to the End


class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int result = 0 ; 
        int count1 = 0 ; 
        for(int i = 0 ; i  < n; i++){
            if(s[i] == '1'){
               count1++;
            }
            else{
                result += count1; 
                while(i+1 < n && s[i+1] !='1') i++;
            }

        }
        return result; 
    }
};