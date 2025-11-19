// 2154. Keep Multiplying Found Values by Two


// Approach 1
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int result = original ; 

        unordered_set<int>st(begin(nums), end(nums));

        while(st.count(result)){
            result *= 2; 
        }
        return result; 
    }
};


//Approach 2
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        int result = original ; 

        sort(begin(nums), end(nums));

        for(int i = 0 ; i  < n; i++){
            if(nums[i] == result){
                result *= 2; 

            }
            else if(nums[i] > result){
                return result; 
            }

        }
        return result; 
    }
};



//approach 3
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        int result = original ; 

        vector<int>arr(1001, 0);
        for(auto &num : nums) arr[num]++;

        while(original <= 1000 && arr[original] != 0 ){
            original *= 2; 
        }
        return original ;
    }
};