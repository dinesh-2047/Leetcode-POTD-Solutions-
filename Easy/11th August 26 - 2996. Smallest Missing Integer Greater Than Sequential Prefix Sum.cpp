// 2996. Smallest Missing Integer Greater Than Sequential Prefix Sum

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int>st (begin(nums), end(nums));

        int sum = nums[0] ;
        for(int i = 1; i  < n; i++){
            if(nums[i] - nums[i - 1] == 1){
                sum += nums[i];
            }
            else {
                   if(!st.count(sum)) return sum; 
                   break; 
            }
        }
        for(int i = sum ; i < 2501; i++){
            if(!st.count(i)) return i; 
        }
        return 51; 
    }
};