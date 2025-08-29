// 3021. Alice and Bob Playing Flower Game


// Approach 1
class Solution {
public:
    long long flowerGame(int n, int m) {
        long long odd_n = (n+1)/2; 
        long long even_n = n/2; 

        long long odd_m = (m+1)/2; 
        long long even_m = m/2;

        return (odd_n * even_m) +(even_n * odd_m); 
    }
};-



// Approach 2
    long long flowerGame(int n, int m) {
        return n * m  / 2;
    }