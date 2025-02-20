// 1980. Find Unique Binary String 



// Approach 1 :  Cantor's Diagonalization (Greedy Approach)

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
         string ans  = "";

        for(int i = 0 ; i<n; i++){
            char ch = nums[i][i];

            if(ch =='0'){
                ans += '1';
            }
            else ans += '0';
        }
        return ans; 
    }
};


// Approach 2 
class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            unordered_set<int> st; // Hash set to store decimal equivalents of given binary strings
            string ans = ""; 
    
            // Convert each binary string in 'nums' to an integer and store it in the set
            for(auto &num  : nums){
                st.insert(stoi(num , 0 , 2 )); // stoi converts binary string to integer
            }
            
            int n  = nums.size(); // Length of binary strings in 'nums'
    
            // Try numbers from 0 to n (ensuring we get a unique binary string)
            for(int number = 0 ; number <= n ; number++){
                if(st.find(number) == st.end()){ // If the number is not in the set, it's our answer
                   ans = bitset<16>(number).to_string(); // Convert number to a 16-bit binary string
                   return ans.substr(16 - n, n); // Extract only the required 'n' bits from the right
                }
            }
            return ans; // This line is redundant but added for safety
        }
};
