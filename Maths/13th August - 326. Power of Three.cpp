// 326. Power of Three




// Approach 1 
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0 ) return false;
        if(n==1) return true; 

         if(n%3!=0) return false; 

         return isPowerOfThree(n/3);
     }
};



// Approach 2 
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0 ) return false; 
        for(int i = 0 ; i <=20; i++){
            if(pow(3,i) == n ) return true; 
        }
        return false; 
         
     }
};



// Approach 3 
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0 ) return false ; 

        while(n%3==0) n/=3; 
        return n==1; 
    }
};



// Approach 4 
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0 ) return false; 

        return( (int)pow(3, 19)) % n ==0 ; 
    }
};



// Approach 5 
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0 ) return false; 
         
         double x = log10(n)/log10(3);
         return (x == int(x)) ;
    }
};