// 628. Maximum Product of Three Numbers


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int mx1 = INT_MIN ; 
        int mx2 = INT_MIN ; 
        int mx3 = INT_MIN ; 

        for(int i = 0 ; i  < n; i++){
            if(nums[i] > mx1){
                mx3 = mx2 ; 
                mx2 = mx1; 
                mx1 = nums[i];
            }

            else if(nums[i] == mx1) {
                mx3 = mx2; 
                mx2 = mx1; 
            }
            else {
                 if(nums[i] > mx2){
                    mx3 = mx2; 
                    mx2 = nums[i];
                 }
                 else if(nums[i] == mx2){
                    mx3 = nums[i];

                 }
                 else {
                    mx3 = max(mx3, nums[i]);
                 }
            }
        }

        int x = mx1* mx2 * mx3; 

        int nmx1 = INT_MAX ; 
        int nmx2 = INT_MAX ; 

        int cnt_neg = 0  ; 

        for(int i = 0 ; i  < n; i++){
            if(nums[i] > 0 ) continue; 
             cnt_neg++;
             if(nmx1 == INT_MAX) {
                nmx1 = nums[i];
                continue; 
             }
            if(abs(nums[i]) > abs(nmx1)){
                nmx2 = nmx1; 
                nmx1 = nums[i];
            }
            else if(abs(nums[i]) == abs(nmx1)){
                nmx2 = nums[i];
            }
            else if(abs(nums[i]) < abs(nmx1)){
                nmx2 = min(nmx2, nums[i]);
            }
        }
 
        if(cnt_neg <= 1) return x; 

        return max(nmx1 * nmx2 * mx1, x);
        
    }
};