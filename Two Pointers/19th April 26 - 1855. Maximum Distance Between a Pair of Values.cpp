// 1855. Maximum Distance Between a Pair of Values

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int result = 0 ; 

        int i = n - 1 ; 
        int j = m - 1; 

        while( i >= 0 && j>=0  ){
            if(nums1[i] <= nums2[j]){
                result = max(result, j - i );
                i--;
            }
            else {
                j--;
            }
        }
        return result; 
    }
};