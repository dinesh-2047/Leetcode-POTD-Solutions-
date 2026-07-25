// 3536. Maximum Product of Two Digits

class Solution {
public:
    int maxProduct(int n) {
        int mx1 = 0 ; 
        int mx2 = 0 ; 

        while(n){
            int digit  = n % 10; 
            if(digit > mx1) {
                mx2 = max(mx2, mx1); 
                mx1 = digit; 
            }
            else if(digit==mx1){
                mx1 = digit; 
                mx2 = digit; 
            }
            else {
                mx2= max(mx2, digit);
            }
           n/=10; 
        }
      
        return mx1 * mx2;
    }
};