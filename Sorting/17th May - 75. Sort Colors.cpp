// 75. Sort Colors


// Approach 1 -> counting sort 
class Solution {
public:
    void sortColors(vector<int>& nums) {
       int red = 0 ; 
       int white  = 0 ; 
       int blue = 0 ; 


       for(auto &num : nums){
        if(num == 0) red++;
        if(num == 1) white++;
        if(num==2) blue++;
       }
       int i = 0 ; 
      while(red--){
        nums[i++] = 0;
      }
      while(white--){
        nums[i++] = 1;
      }
      while(blue--){
        nums[i++] = 2; 
      }

  

    }
};








// Approach 2 -> dutch national flag algorightm /

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0 ; 
        int m = 0 ; 
        int r = n-1; 

        while(m <= r){
              if(nums[m] == 0){
                swap(nums[m], nums[l]);
                m++;
                l++;
              }
              else if(nums[m]==1){
                m++;
              }
              else{
                //nums[m] == 0
                swap(nums[m],nums[r] );
                    r--;
                
              }
        }
        
    }
};