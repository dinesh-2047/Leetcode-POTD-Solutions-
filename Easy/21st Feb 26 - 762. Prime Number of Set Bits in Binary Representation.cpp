// 762. Prime Number of Set Bits in Binary Representation

class Solution {
public:
bool isPrime(int n){
    return n ==2 || n == 3 || n ==  5 || n == 7 || n==11 || n==13 || n==17 || n== 19;
}
    int countPrimeSetBits(int left, int right) {
        int result = 0 ;
        for(int i = left; i <= right; i++){
            if(isPrime(__builtin_popcount(i))) result++;
        }
        return result; 
    }
};