// 3302. Find the Lexicographically Smallest Valid Sequence

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();


        vector<int> dp(n+1);
        int i = n - 1; 
        int j = m - 1; 

        while(i >= 0 && j >= 0 ){
            if(word1[i] == word2[j]){
                dp[i] = dp[i + 1] + 1; 
                i--;
                j--;
            }
            else {
                dp[i] = dp[i + 1];
                i--;
            }
        }

        while(i >= 0 ){
            dp[i] = dp[i + 1];
            i--;
        }
        i = 0 ; 
        j = 0 ; 
        vector<int > result; 
        bool canChange = true; 
        while(i < n && j < m ){
            if(word1[i] == word2[j]){
                result.push_back(i);
                i++;
                j++;
            }
            else {
                int req = m - j - 1; 
                if(req > dp[i + 1]){
                    i++;
                }
                else {
                    if(canChange){
                        canChange = false; 
                        result.push_back(i);
                        i++;
                        j++;
                    }
                    else i++;
                }
            }
        }
     
        if(j < m) return {};
        return result; 
    }
};