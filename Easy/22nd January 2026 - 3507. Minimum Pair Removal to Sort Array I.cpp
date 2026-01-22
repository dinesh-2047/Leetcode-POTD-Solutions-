// 3507. Minimum Pair Removal to Sort Array I



class Solution {
public:
bool isSorted(vector<int> &nums){
    int n = nums.size();
    for(int i = 1 ; i  < n; i++){
        if(nums[i] < nums[i - 1] ) return false; 
    }
    return true; 
}
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();

        int result = 0 ; 
        while(!isSorted(nums)){
            int minSum = INT_MAX ; 
            int idx = -1; 
            for(int i = 0; i  < nums.size() -1 ; i++){
                int sum = nums[i] + nums[i + 1];
                if(minSum > sum){
                    minSum = sum ; 
                    idx = i ; 
                }
            }

            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);
            result++;
        }
        return result; 
    }
};