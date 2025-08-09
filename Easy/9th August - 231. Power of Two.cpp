// 231. Power of Two


// Approach 1 

class Solution {
public:
    bool isPowerOfTwo(int n) {
    
       for(int x = 0 ; x <= 30; x++){
            if(pow(2, x) == n ) return true; 
       }
       return false;
    }
};







//Approach 2 
class Solution {
public:
    bool isPowerOfTwo(int n) {
    
        double x = log2(n);
        if(x<0) return false; 
        if(x== floor(x) ) return true; 
        else return false; 
    }
};






//Approach 3 


class Solution {
public:
    bool isPowerOfTwo(int n) {
    
      if(n==1)  return true; 

      if(n <= 0 || n%2!=0) return false; 

      return isPowerOfTwo(n/2);
    }
};






//Approach  4
class Solution {
public:
    bool isPowerOfTwo(int n) {
       if(n <= 0) return false; 

       return __builtin_popcount(n) == 1; 
    }
};




//Approach 5
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
         return (n> 0 && (n  & (n-1))) == 0 ;
    }
};





//Approach 6 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
         return ((1<<30)%n == 0 ); // 2^30 %n == 0 
    }
};