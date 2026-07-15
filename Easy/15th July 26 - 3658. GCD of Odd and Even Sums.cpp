// 3658. GCD of Odd and Even Sums


class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return gcd( n * n , ((n + 1) * n )); 
    }
};