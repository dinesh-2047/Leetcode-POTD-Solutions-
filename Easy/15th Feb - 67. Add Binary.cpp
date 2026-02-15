// 67. Add Binary


class Solution {
public:
    string addBinary(string a, string b) {
       int n = a.length();
       int m = b.length();

       int i = n-1;
       int j = m-1; 
       int carry = 0;
        string result = "";

      while(i >= 0 || j >=0 || carry){
          int sum = carry ; 
          if(i >= 0 ){
            sum += (a[i] - '0');
          }
          if(j >=0 ) sum += (b[j] - '0');

          if(sum == 3){
             carry = 1; 
             result += '1';

          }
          if(sum == 2){
             carry = 1; 
             result += '0';
          }

          if(sum == 1){
            carry = 0; 
            result += '1';
          }
          if(sum == 0 ){
            carry = 0 ; 
            result += '0';
          }
          i--;
          j--;
      }
       reverse(begin(result), end(result));

       return result; 
    }
};