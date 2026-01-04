// 1390. Four Divisors

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();

        int result = 0;

        for (auto& num : nums) {
            vector<int> divisors;
            bool valid = true;
            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    divisors.push_back(i);
                    if (i != num / i) {
                        divisors.push_back(num / i);
                    }
                }

                if (divisors.size() > 4) {
                    valid = false;
                    break;
                }
            }
            if (valid && divisors.size() == 4) {
                result += divisors[0] + divisors[1] + divisors[2] + divisors[3];
            }
        }
        return result;
    }
};