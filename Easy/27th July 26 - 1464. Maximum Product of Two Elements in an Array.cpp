// 1464. Maximum Product of Two Elements in an Array

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int mx1 = 0 ;
        int mx2 = 0; 


        for(int i= 0; i  < n; i++){
            if(nums[i] > mx1){
                mx2 = mx1; 
                mx1= nums[i];
            }
            else if(nums[i] == mx1 ){
                mx2 = nums[i];
            }
            else {
                mx2 = max(mx2, nums[i]);
            }
        }
        return (mx1 - 1) * (mx2 - 1);
    }
};