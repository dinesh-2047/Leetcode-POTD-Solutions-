// 3381. Maximum Subarray Sum With Length Divisible by K


class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        long long maxSum = LLONG_MIN ; 
         

        vector<long long>pref(n , 0);
        pref[0] = nums[0];

        for(int i = 1;  i  < n; i++){
            pref[i] = pref[i - 1] + nums[i];
        }

        for(int st = 0 ; st < k; st++){
            int i = st; 

            long long currSum = 0 ; 
            
            while( i < n && (i +  k -1)< n ){
             int j = i + k -1;

             long long subSum = pref[j] - ((i-  1 >= 0) ? pref[i - 1] : 0);

             currSum = max(subSum, subSum + currSum);

             maxSum = max(maxSum , currSum);

             i+=k;
            }
        }
        return maxSum; 

    }
};