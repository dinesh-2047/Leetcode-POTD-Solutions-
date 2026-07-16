// 3867. Sum of GCD of Formed Pairs

class Solution {
public:
using ll = long long ; 
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        int mx = 0; 
        for(int i = 0 ; i < n; i++){
            mx = max(mx , nums[i]);
            nums[i] = gcd(nums[i], mx);
        }

        sort(begin(nums), end(nums));

        int i = 0 ; 
        int j = n-1 ; 
        ll result = 0 ; 
        while(i < j ){
            result += gcd(nums[i], nums[j]);
            i++;
            j--;
        }
        return result; 
    }
};