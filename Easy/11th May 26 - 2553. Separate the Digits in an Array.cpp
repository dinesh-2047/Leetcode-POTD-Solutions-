// 2553. Separate the Digits in an Array

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result; 

        for(auto &x : nums){
            string s = to_string(x);
            for(int i = 0 ; i < s.length(); i++){
                result.push_back(s[i] - '0');
            }
        }
        return result;
    }
};