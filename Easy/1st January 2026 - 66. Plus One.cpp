// 66. Plus One

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        int sum = digits[n-1] + 1;
        int carry = sum/10;
        digits[n-1] = sum%10; 
        for(int i = n -  2; i >= 0 ; i--){
               sum = digits[i] + carry ; 
              digits[i] =  sum%10; 
              carry = sum/10; 
        }
        if(carry!=0){
            digits.push_back(carry);
            reverse(digits.begin(), digits.end());
        }
        
        return digits; 
    }
};