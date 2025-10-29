// 3370. Smallest Number With All Set Bits


// Approach 1 
class Solution {
public:
    int smallestNumber(int n) {
        int x = 0 ; 
        for(int p = 0; p < 10; p++){
            if(x >= n){
                return x; 
            }
            x += 1<<p;
        }
          return x;
    }
};

// Approach 2
class Solution {
public:
    int smallestNumber(int n) {
        int x = n ; 
        while(true){
            if((x & (x + 1) ) == 0  ){
                return x; 
            }
            x++;
        }
        return x; 
    }
};


//Approach 3 
class Solution {
public:
    int smallestNumber(int n) {
        int x = 1; 
        while(x < n ){
            x = 2 * x + 1; 
        }
        return x; 
    }
};


//Approach 4
class Solution {
public:
    int smallestNumber(int n) {
        int bits = log2(n) + 1;

        return (1 << bits) -1 ; 
    }
};