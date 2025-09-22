// 3005. Count Elements With Maximum Frequency/



// Approach 1 :
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int , int>mp ; 
        int maxFreq = 0 ;  
        for(auto &num : nums){
            mp[num]++;
            maxFreq = max(maxFreq, mp[num]);
        }
        int result = 0 ; 
        for(auto &[_, freq] : mp){
            if(freq == maxFreq){
                result +=freq; 
            }
        }
        return result; 
    }
};












//Approach 2
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();

        vector<int>cnt(101, 0) ; 
        int maxFreq = 0 ;  
        for(auto &num : nums){
            cnt[num]++;
            maxFreq = max(maxFreq, cnt[num]);
        }
        int result = 0 ; 
        for(auto &freq : cnt){
            if(freq == maxFreq){
                result +=freq; 
            }
        }
        return result; 
    }
};