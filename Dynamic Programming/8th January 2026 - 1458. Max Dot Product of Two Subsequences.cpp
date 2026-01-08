// 1458. Max Dot Product of Two Subsequences

class Solution {
public:
int m , n; 
vector<vector<int>>dp; 
using ll = long long; 
int solve(vector<int> &nums1, vector<int> &nums2, int i , int j ){
     if(i >= n || j >= m ) return INT_MIN ; 

       if(dp[i][j]!=INT_MIN) return dp[i][j];

      ll val = nums1[i] * nums2[j];
      ll takeij = nums1[i] * nums2[j] + (ll) solve(nums1, nums2, i + 1, j + 1);
      ll takei = solve(nums1, nums2, i , j + 1);
      ll takej = solve(nums1, nums2, i + 1, j);

      return dp[i][j] = max({val , takeij, takei, takej});
}


    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
       dp.assign(n , vector<int>(m, INT_MIN));
        return solve(nums1, nums2, 0 , 0);
    }
};