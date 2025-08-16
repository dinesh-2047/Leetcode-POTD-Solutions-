// 1323. Maximum 69 Number



//Approach 1
class Solution {
public:
    int maximum69Number (int num) {
       string s = to_string(num);

       for(int i = 0 ; i <s.length(); i++){
           if(s[i] == '6'){
              s[i] = '9';
              break; 
           }
       }
       return stoi(s);
    }
};


// Approach 2 


class Solution {
public:
    int maximum69Number (int num) {
        int sixPos = -1; 

         int n = num ; 
         int pos = 0  ; 
         while(n ) {
            if((n%10 )== 6){
               sixPos = pos; 
            }
            n/=10;
            pos++;
         }
          if(sixPos == -1 ) return num ;
         return num + (3 * ((int)pow(10, sixPos)));

    }
};