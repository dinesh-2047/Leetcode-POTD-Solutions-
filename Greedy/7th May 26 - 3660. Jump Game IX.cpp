// 3660. Jump Game IX


class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n) ; 
         
        vector<int> pref_max(n);
        int maxi = 0 ; 
        for(int i = 0; i < n; i++){
           maxi = max(maxi , nums[i]);
           pref_max[i] = maxi; 
        }
         int mini = nums[n - 1];
         result[n-1] = pref_max[n-1];
       for(int i = n-2; i >= 0 ; i--){
            if( pref_max[i] <= mini){
                result[i] = pref_max[i];
            }
            else if( pref_max[i] > mini){
                result[i] = result[i + 1];
            }
            else result[i] = nums[i];
            mini = min(mini , nums[i]);
        }
        return result; 
        
        
    }
};