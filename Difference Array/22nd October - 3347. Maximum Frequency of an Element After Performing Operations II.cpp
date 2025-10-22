// 3347. Maximum Frequency of an Element After Performing Operations II


class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxi =  *max_element(begin(nums), end(nums));
        int n = maxi  + k + 2; 

        map<int ,int>diff;
        unordered_map<int , int>mp; 

        for(int i = 0; i  < nums.size() ; i++){
            mp[nums[i]]++;
            int left = max(0, nums[i] - k );
            int right = min(n-1, nums[i] + k );

            diff[left]++;
            diff[right + 1]--;
            diff[nums[i]] += 0 ;
        }
          int cumSum = 0 ; 
        for(auto &p : diff ){
              p.second+= cumSum ; 
              cumSum = p.second; 
        }
     

        int result = 0 ; 
        for(auto it = diff.begin(); it != diff.end(); it++){
            int i = it->first; 
           
            int currTargetCount = mp[i];

            int needToConvert = it->second - currTargetCount; 

            currTargetCount += min(needToConvert , numOperations);

            result = max(result , currTargetCount);
        }
        return result; 
    }
};