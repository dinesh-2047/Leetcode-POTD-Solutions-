// 1780. Check if Number is a Sum of Powers of Three


//Approach-1 (Using School Maths)
//T.C : O(log3(n))
//S.C : O(1)
class Solution {
    public:
        bool checkPowersOfThree(int n) {
            int p = 0;
    
            while(pow(3, p) <= n) {
                p++;
            }
    
            while(n > 0) {
                if(n >= pow(3, p)) {
                    n = n - pow(3, p);
                }
    
                if(n >= pow(3, p)) {
                    return false;
                }
    
                p--;
            }
    
            return true;
        }
    };
    
    
    //Approach-2 (Using Ternary Representation)
    //T.C : O(log3(n))
    //S.C : O(1)
    class Solution {
    public:
        bool checkPowersOfThree(int n) {
            while(n > 0) {
                if(n%3 == 2) {
                    return false;
                }
    
                n = n/3;
            }
    
            return true;
        }
    };
    
    
    //Approach-3 (Using take and not take power)
    //T.C : O(2^(log3(n)))
    //S.C : O(log3(n)) system resuction stack space
    class Solution {
    public:
        int solve(int n, int p) {
            if(n == 0) {
                return true;
            }
    
            if(pow(3, p) > n) {
                return false;
            }
    
            bool p_ko_lelo = solve(n - pow(3, p), p+1);
    
            bool p_ko_nahi_lo = solve(n, p+1);
    
            return p_ko_lelo || p_ko_nahi_lo;
        }
    
        bool checkPowersOfThree(int n) {
            return solve(n, 0);
        }
    };

    
    // Approach 4 :- Backtracking 

    class Solution {
        public:
            bool solve(int n, int currSum, int i) {
                if (currSum == n) return true;  // Base case: Found a valid sum
                if (currSum > n || i > 16) return false; // Stop if we exceed n or go beyond 3^16
        
                // Include the current power of 3
                if (solve(n, currSum + pow(3, i), i + 1)) return true;
        
                // Exclude the current power and move to the next
                if (solve(n, currSum, i + 1)) return true;
        
                return false;
            }
        
            bool checkPowersOfThree(int n) {
                return solve(n, 0, 0); // Start from 3^0
            }
        };