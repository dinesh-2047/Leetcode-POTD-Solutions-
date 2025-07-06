// 1865. Finding Pairs With a Certain Sum

// TC -> O(m+n) for FindSumPairs()
// O(1) for add
// O(n) for count 


// SC-> O(m+n) due to vec1  + vec2


class FindSumPairs {
public:
    vector<int> arr1;
    vector<int> arr2;
    unordered_map<int, int> mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        for (int i = 0; i < nums2.size(); i++) {
            mp[arr2[i]]++;
        }
    }

    void add(int index, int val) {
        mp[arr2[index]]--;
        arr2[index] += val;

        mp[arr2[index]]++;
    }

    int count(int tot) {

        int result = 0;

        for (int i = 0; i < arr1.size(); i++) {
            int x = tot - arr1[i];
            if (mp.find(x) != mp.end()) {
                result += mp[x];
            }
        }
        return result;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */