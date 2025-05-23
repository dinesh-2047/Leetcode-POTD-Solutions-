// Sum of all substrings of a number


// Approach 1 
class Solution {
  public:
    int sumSubstrings(string &s) {
        int n = s.length();
        int sum = 0 ; 
        
        for(int i = 0 ; i<n; i++){
            for(int j = i ; j<n; j++){
                string str = "";
                for(int k = i ; k <=j ; k++){
                    str = str + s[k];
                }
                sum = sum + stoi(str);
                 
            }
        }
        return sum; 
        
    }
};






//Approach 2 

class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        int n = s.length();
        int result = 0 ; 
        
        
        for(int i = 0 ; i<n; i++){
            int currSum = s[i]-'0';
            result+=currSum ; 
            
            for(int j = i + 1; j < n; j++){
                currSum = currSum *10 + (s[j]-'0');
                result += currSum; 
            }
        }
        return result; 
    }
};





//Approach 3 
class Solution {
  public:
    int sumSubstrings(string &s) {
        int n = s.length();
        
        vector<int>dp(n,0);
        dp[0] = s[0]-'0';
        
        
        int ans = dp[0];
        
        for(int i = 1; i <n; i++){
            dp[i] = dp[i-1]*10 +  (s[i]-'0')*(i+1);
            ans += dp[i];
        }
        
      return  ans; 
        
    }
};