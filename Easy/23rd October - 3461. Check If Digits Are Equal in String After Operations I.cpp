// 3461. Check If Digits Are Equal in String After Operations I/


// Approach 1 
class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();

        for (int i = 0; i < n - 2; i++) {
            string newString = "";
            for (int j = 0; j < n - 1; j++) {
                int digit1 = s[j] - '0';
                int digit2 = s[j + 1] - '0';

                int newDigit = (digit1 + digit2) % 10;

                char nd = newDigit + '0';

                newString.push_back(nd);
            }
            s = newString;
        }
        return s[0] == s[1];
    }
};





// approach 2 
class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();

         while( n > 2){
            for(int i =0 ; i < n; i++){
                s[i] = ((s[i] -'0') + (s[i + 1]- '0'))%10 + '0'; 
            }
            n--;
         }
         return s[0] == s[1];
    }
};