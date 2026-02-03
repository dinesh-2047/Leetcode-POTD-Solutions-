// 3637. Trionic Array I


class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        int inc_count = 0 ; 
        int dec_count = 0 ; 

        char curr = '/';

        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1]) return false; 
            if(nums[i] < nums[i - 1]){
                if(curr == 'd') continue; 
                curr = 'd';
                dec_count++;
            }
            else {
                if(curr == 'i') continue; 
                curr = 'i';
                inc_count++ ; 
            }
        }


        return inc_count == 2 && dec_count == 1; 
    } 
};