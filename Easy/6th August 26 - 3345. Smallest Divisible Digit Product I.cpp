// 3345. Smallest Divisible Digit Product I


class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i = n; i <= 100; i++){
             int pro = 1; 
             int temp = i; 
             while(temp){
                pro *= (temp%10);
                temp /= 10;
             }
             if(pro%t == 0) return i; 
          
        }
        return -1;
    }
};