// 3876. Construct Uniform Parity Array II

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(begin(nums1), end(nums1));

        if(mn%2 == 1) return true; 

        for(auto &x : nums1){
            if(x%2 == 1) return false; 
        }
        return true; 
    }
};