// 594. Longest Harmonious Subsequence



// Approach 1 -> O(n)

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int , int>mp ;

        for(int i = 0 ; i < n; i++){
            mp[nums[i]]++;
        }

        int result = 0 ; 

        for(auto &pair : mp){
            int num = pair.first; 
            int freq = pair.second; 

            if(mp.find(num + 1)!=mp.end()){
                int nextnum = num +1; 
                int nextfreq = mp[num+1];

                result = max(result , freq + nextfreq);
            }
        }
        return result; 
    }
};







// Approach 2 -> O(nlongn)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int i = 0;
        int j = 0;
        int result = 0;

        while (j < n) {

            if (nums[j] - nums[i] == 1) {
                result = max(result, j - i + 1);
            }

            while (nums[j] - nums[i] > 1) {
                i++;
            }
            j++;
        }
        return result;
    }
};