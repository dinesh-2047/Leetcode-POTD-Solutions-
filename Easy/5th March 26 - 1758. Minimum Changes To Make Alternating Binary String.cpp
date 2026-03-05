// 1758. Minimum Changes To Make Alternating Binary String

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        int start_with_1 = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (s[i] == '0') {
                    start_with_1++;
                }
            } else {
                if (s[i] == '1') {
                    start_with_1++;
                }
            }
        }
        return min(start_with_1, n - start_with_1);
    }
};