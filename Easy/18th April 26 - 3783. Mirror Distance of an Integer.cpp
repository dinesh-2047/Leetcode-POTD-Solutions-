// 3783. Mirror Distance of an Integer

class Solution {
public:
    int mirrorDistance(int n) {
        int x = n ;
        int revn = 0 ; 

        while(x){
            revn = (revn * 10 ) + (x %10);
            x/=10 ; 
        }

        return abs(revn - n);

    }
};