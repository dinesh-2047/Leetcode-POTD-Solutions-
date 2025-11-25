// 1015. Smallest Integer Divisible by K


//Approach 1
class Solution {
public:
    int smallestRepunitDivByK(int k) {
       int n = 0;
       if(k %2 == 0 || k%5 == 0 ){
            return -1; 
       }

       for(int i = 1  ; i <= k; i++){
           n = (n * 10  + 1)%k;
           if(n == 0) return i ; 
       }
       return -1;
    }
}; 









//Approach 2 
class Solution {
public:
    int smallestRepunitDivByK(int k) {
       int n = 0;

        for(int i = 0 ; i  < 1e5; i++){
           n = (n*10+1)%k;
            if(n%k == 0 ) return i + 1; 
        }
        return -1; 
    }
};






//Approach 3 
class Solution {
public:
    int smallestRepunitDivByK(int k) {
       int n = 0;
       if( k== 1) return 1; 

       for(int i = 1  ; i <= k; i++){
           n = (n * 10  + 1)%k;
           if(n == 0) return i ; 
       }
       return -1;
    }
};