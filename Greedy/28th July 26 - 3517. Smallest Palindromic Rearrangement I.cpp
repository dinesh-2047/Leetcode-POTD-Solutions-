// 3517. Smallest Palindromic Rearrangement I

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();

        string result = s; 

        vector<int> freq(26, 0);
        for(auto &ch : s){
            freq[ch - 'a']++;
        }

        char odd = '_';

       if(n%2 == 1){
          for(int i = 0 ; i < 26 ; i++){
            if(freq[i]%2 == 1){
                odd = i + 'a';
                break; 
            }
          }
       }

       int i = 0 ; 
       int j = n-1; 

       for(char ch = 'a' ; ch <= 'z'; ch++){
            if(ch == odd){
                freq[ch -'a']--;
                result[n/2 ] = ch; 
            }
          while(freq[ch - 'a'] > 0 ){
               result[i++] = ch; 
               result[j--] = ch; 
               freq[ch -'a']-=2; 
          }
       }
     return result; 

    }
};