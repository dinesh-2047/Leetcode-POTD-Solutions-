// 3634. Minimum Removals to Balance Array


class Solution {
public:
using ll = long long ; 
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();

        int result = INT_MAX; 

        sort(begin(nums), end(nums));

        int i = 0 ; 
        int j =  0 ; 

        while(j < n ){
            while(nums[j] >(ll) k * nums[i]){
                i++;
            }
            result = min(result, n-(j-i+1));
            j++;
        }
        return result; 
    }
};