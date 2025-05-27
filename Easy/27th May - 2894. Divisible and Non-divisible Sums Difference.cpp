// 2894. Divisible and Non-divisible Sums Difference



// Approach 1 

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0;
        int num2 = 0;

        for (int i = 1; i <= n; i++) {
            if (i % m == 0) {
                num2 += i;

            } else {
                num1 += i;
            }
        }

        return num1 - num2;
    }
};





//Approach 2 - constant time
class Solution {
public:
    int differenceOfSums(int n, int m) {
        return n*(n+1)/2  - m * (n/m) * (n/m + 1);
    }
};