// 3622. Check Divisibility by Digit Sum and Product

class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n ;
        int pro = 1; 
        int sum = 0 ;

        while(n) {
            pro *= n%10; 
            sum += n%10; 
            n/=10; 
        }

        return temp%(sum + pro) == 0 ; 
    }
};