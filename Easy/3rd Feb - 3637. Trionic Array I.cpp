// 3637. Trionic Array I



// Approach 1
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


//Approach 2 
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
         int i = 1 ; 
        while(i < n && nums[i] > nums[i - 1]) i++;
       
        if(i == n-1 || i == 1 ) return false;

        while(i < n && nums[i] < nums[i - 1]) i++;
        
         if(i == n) return false; 

        while(i < n && nums[i] > nums[i - 1]) i++;
        
        return i == n; 
    }
};