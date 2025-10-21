// 3346. Maximum Frequency of an Element After Performing Operations I



class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxi = *max_element(begin(nums), end(nums));

        int n = maxi + k + 1 ; 

        vector<int>pref(n , 0);

        for(auto &num : nums){
            pref[num]++;
        }

        for(int i = 1 ; i < n; i++){
            pref[i] = pref[i - 1] + pref[i];
        }
   
      

        int result = 0 ; 
        for(int i = 0 ; i <n; i++){
            if(pref[i] == 0 ) continue; 
            int left =  max(0 , i - k); 
            int right = min(n -1 , i + k) ; 

            int totalInRange = pref[right] - (left > 0 ? pref[left - 1] : 0);
            int currTargetCount = pref[i] - (i > 0 ? pref[i - 1] : 0);
            int needToConvert = totalInRange - currTargetCount; 

            currTargetCount += min(needToConvert , numOperations);

            result = max(result , currTargetCount);
        }
        return result; 
    }
};