// 961. N-Repeated Element in Size 2N Array


// Approach 1 using set 
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int>st; 
        for(auto &x : nums){
            if(st.count(x)) return x;
            st.insert(x);
        }
        return nums[0];
    }
};







//Approach 2 using map
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int>mp ; 

        for(auto &x : nums){
            mp[x]++;
        }
        for(auto &[num, freq] : mp){
            if(freq == n/2) {
                return num; 
            }
        }
        return -1;
    }
};












//Approach 3 using freq array 
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        vector<int>freq(10001,0);

        for(auto &x : nums){
            freq[x]++;
        }
        for(int i= 0 ; i < 10001 ; i++){
            if(freq[i] == n/2) return i ;
        }
        return -1;
    }
};






// Approach 4 O(1)
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();

        for(int i = 2; i< n; i++){
            if(nums[i] == nums[i - 1] || nums[i] == nums[i - 2]) return nums[i];
        }
        return nums[0];
    }
};