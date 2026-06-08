// 2161. Partition Array According to Given Pivot

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> result; 

        for(int i= 0 ; i  < n; i++){
            if(nums[i] < pivot){
                result.push_back(nums[i]);
            }
        }
        for(int i = 0 ; i  < n; i++){
            if(nums[i] == pivot){
                result.push_back(nums[i]);
            }
        }
        for(int i = 0;  i  < n; i++){
            if(nums[i] > pivot){
                result.push_back(nums[i]);
            }
        }
        return result; 
    }
};