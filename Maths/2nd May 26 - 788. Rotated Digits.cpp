// 788. Rotated Digits

// Approach  1 : Brute Force
class Solution {
public:
    int rotatedDigits(int n) {
        int result = 0 ; 
        for(int x = 1; x <= n ; x++){
             int rx = 0; 
              bool valid = true; 
              bool poss = false; 
             string s = to_string(x);
            for(auto ch : s){
                int digit = ch - '0' ;
                if(digit == 3 || digit == 7 || digit == 4) {
                    valid = false; 
                    break; 
                }

                if(digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                    poss = true; 
                }
                
            
             }
             if(valid && poss) {
                result++;
             }
        }
        return result;
    }
};





//Approach 2 dp rec + memo 
class Solution {
public:
vector<int> dp; 
int solve(int num){

    if(num == 0 ) return 0 ; 

    if(dp[num] != -1) return dp[num];

    int rem = solve(num/10);
    if(rem == 2) return dp[num] =  2; 

    int digit = num % 10; 

    int digitCheck; 
    if(digit == 0 || digit == 1 || digit == 8){
         digitCheck = 0 ;// same
    }
    else if(digit == 2 || digit == 5 || digit == 6 || digit==9){
         digitCheck = 1; // rotate
    }
    else return dp[num] = 2; //invalid

    if(rem == 0  && digitCheck == 0 ) return dp[num] = 0 ; 
    return dp[num] = 1; 

}
    int rotatedDigits(int n) {
        dp.assign(n+1, -1);
        int result = 0 ; 
        for(int x = 1; x <= n ; x++){
             if(solve(x) == 1)result++;
        }
        return result;
    }
};