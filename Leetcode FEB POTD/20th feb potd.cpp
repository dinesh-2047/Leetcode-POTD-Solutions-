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