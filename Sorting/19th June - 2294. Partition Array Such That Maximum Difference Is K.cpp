// 2294. Partition Array Such That Maximum Difference Is K


class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
       sort(nums.begin(),  nums.end());
        int result = 0 ; 

        int mini = nums[0];

        for(int i = 0 ; i <n ;i++){
               if( nums[i] - mini <= k){
                  continue; 
               }
               else {
                  result++;
                  mini = nums[i];
               }
        }
        return result+1 ;
    }
};