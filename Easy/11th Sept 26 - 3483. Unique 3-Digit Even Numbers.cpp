// 3483. Unique 3-Digit Even Numbers

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        int result = 0;
        vector<int> seen(1001, 0);
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                for (int z = 0; z < n; z++) {
                    if (x == y || y == z || x == z)
                        continue;
                    int num = digits[x] ;
                    if(num == 0 ) continue; 
                    num = num*10 + digits[y];
                    num = num * 10 + digits[z];
                    if (!seen[num] &&num%2 == 0 ) {
                        result++;
                        seen[num] = 1; 
                    }
                }
            }
        }
        return result;
    }
};