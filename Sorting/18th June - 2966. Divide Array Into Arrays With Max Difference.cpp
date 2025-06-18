// 2966. Divide Array Into Arrays With Max Difference/




class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> result; 

        for(int i = 1; i <n; i+=3){
            if(nums[i+1] - nums[i-1] > k ) return {};
            else result.push_back({nums[i-1], nums[i], nums[i+1]});
        }

        return result; 
    }
};