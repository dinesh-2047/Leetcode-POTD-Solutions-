// 3731. Find Missing Elements

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>present (101, 0);

        int n = nums.size();

        int maxi = nums[0];
        int mini = nums[0];

        for(int i = 0 ; i  < n; i++){
            present[nums[i]] = 1; 
            maxi = max(nums[i], maxi);
            mini = min(nums[i], mini);
        }

        vector<int> result; 
        for(int i = mini ; i <= maxi ; i++){
            if(!present[i]){
                result.push_back(i);
            }
        }
        return result;

    }
};