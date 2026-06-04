// 3751. Total Waviness of Numbers in Range I


class Solution {
public:
    int totalWaviness(int num1, int num2) {
         int result = 0 ; 
        for(int i = num1; i <= num2; i++){
            string s = to_string(i);
            
            for(int j = 1; j  < s.length()- 1; j++){
                if((s[j] > s[j - 1] && s[j] > s[j + 1]) || (s[j] < s[j - 1] && s[j] < s[j + 1])) result++;
            }
        }
        return result; 
    }
};