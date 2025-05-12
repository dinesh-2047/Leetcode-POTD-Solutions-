// 2094. Finding 3-Digit Even Numbers


// Approach 1 
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();

        vector<int>ans;
        for(int i = 0 ; i<n; i++){
            for(int j = 0; j < n ; j++ ){
                for(int k = 0 ; k<n; k++){
                    if(i!=j && j != k && i!=k ){
                        int num = (digits[i] * 100 ) + (digits[j]*10) + digits[k];
                        int digit = ceil(log10(num+1));
                        if(digit == 3 && num%2==0 ) ans.push_back(num);
                    }
                }
            }
        }
        set<int>st(ans.begin(), ans.end());
        return vector<int>(st.begin(), st.end()); 

    }
};









//Approach 2 
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();

        vector<int>mp(10,0);
        for (int i = 0; i < n; i++)
            mp[digits[i]]++;
        vector<int> ans;

        for (int num = 100; num <= 999; num++) {
            if (num % 2 == 1)
                continue;
             int copyNum = num; 
            int firstDigit = copyNum  % 10;
            copyNum /= 10;
            int secondDigit = copyNum % 10;
            copyNum  /= 10;
            int thirdDigit = copyNum;

            if ( mp[firstDigit] > 0) {
                mp[firstDigit]--;

            } else {

                continue;
            }

            if ( mp[secondDigit] > 0) {
                mp[secondDigit]--;
            } else {

                mp[firstDigit]++;
                continue;
            }
            if ( mp[thirdDigit] > 0) {
                mp[thirdDigit]--;
            } else {
                mp[firstDigit]++;
                mp[secondDigit]++;
                continue;
            }
            
            
            ans.push_back(num);
            mp[firstDigit]++;
            mp[secondDigit]++;
            mp[thirdDigit]++;
        }
        return ans;
    }
};