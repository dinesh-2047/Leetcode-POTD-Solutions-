// 1680. Concatenation of Consecutive Binary Numbers

class Solution {
public:
    using ll = long long;
    int mod = 1e9 + 7;
    string getBinary(int n) {
        string binary = "";
        while (n) {
            binary.push_back(n % 2 + '0');
            n /= 2;
        }
        reverse(begin(binary), end(binary));
        return binary;
    }
    int concatenatedBinary(int n) {
        ll result = 0;

        int num = 1;
        while (num <= n) {
            string binary = getBinary(num);
            for (int i = 0; i < binary.length(); i++) {
                result = (result * 2) % mod;
                if (binary[i] == '1') {
                    result = (result + 1) % mod;
                }
            }
            num++;
        }
        return result;
    }
};