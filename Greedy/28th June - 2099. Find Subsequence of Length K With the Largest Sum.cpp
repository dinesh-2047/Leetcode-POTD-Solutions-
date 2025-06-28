// 2099. Find Subsequence of Length K With the Largest Sum





// Approach 1 TC- (nlogn)
class Solution {
public:
static bool cmp(pair<int , int> a ,pair<int , int>b){
    return a.second< b.second; 
}
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int>result; 

        vector<pair<int , int>>vec; 

        for(int i = 0 ; i <n; i++){
            vec.push_back({nums[i], i});
        }

        sort(vec.rbegin(), vec.rend());

        sort(vec.begin(), vec.begin() + k, cmp );

         for(int i = 0 ; i<k; i++){
            result.push_back(vec[i].first);
         }
         return result; 
    }
};










// Approach2 TC- Average O(n)/
class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> result;
        vector<int> vec = nums;

        nth_element(vec.begin(), vec.begin() + k - 1, vec.end(),
                    greater<int>());

        unordered_map<int, int> mp;
        for (int i = 0; i < k; i++) {
            mp[vec[i]]++;
        }

        int kth_largest = vec[k - 1];
        for (int i = 0; i < n; i++) {
            if (nums[i] >= kth_largest && mp[nums[i]] > 0) {

                result.push_back(nums[i]);
                mp[nums[i]]--;

                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
            }
        }

        return result;
    }
};