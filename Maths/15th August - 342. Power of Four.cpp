// 342. Power of Four

// Approach 1
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0 ) return false; 

        double x = log10(n)/log10(4);
        if(x == int(x)) return true; 
        else return false; 
    }
};







//Approach 2 
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0 ) return false; 
  if(n==1) return true; 
         if(n%4!=0) return false;
         

         return isPowerOfFour(n/4) ;
    }
};









//Approach 3 

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0 ) return false; 
        for(int i = 0 ; i <= 15 ; i++){
            if(pow(4, i) == n  ) return true; 
        }
        return false; 
    }
};










//Approach 4
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false; 
      bitset<32>binary(n); 
      int cnt = 0 ; 

      for(int i = 0 ; i < binary.size(); i+=2){
            if(binary[i] == 1)
              cnt++;
              if(binary[i+1]==1) return false;
      }
      return cnt ==1 ; 
    }
};


//Approach 5
class Solution {
public:
    bool isPowerOfFour(int n) {
       return n > 0 &&( n &(n-1)) == 0 && ((n-1)%3)==0;
    }
};







//Approach 6 
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false; 
       while(n%4==0){
         n/=4; 
       }
       return n == 1; 
    }
};