// 3487. Maximum Unique Subarray Sum After Deletion


// Approach 1 
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.rbegin(), nums.rend());
        unordered_map<int , int>mp ; 

        int sum = nums[0] ;
        mp[nums[0]]++; 
        for(int i = 1 ;i < n; i++){
            if(mp.count(nums[i]) || nums[i] <=0 ) continue; 
            mp[nums[i]]++;
            sum += nums[i];
        }
        return sum ;

    }
};







//Approach 2 
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int , int>mp ; 
        auto lambda = [] (int num){
            return num <= 0 ;
        };
       
         if(all_of(nums.begin(), nums.end(), lambda)) return *max_element(nums.begin(), nums.end());
          int sum = 0;

         for(int i = 0 ; i <n; i++){
             if(mp.count(nums[i]) || nums[i] <= 0) continue; 
              mp[nums[i]]++;
              sum += nums[i];
         }
         return sum; 
        
      return sum; 
    }
};






//Approach 3 

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
         if(nums[0] <= 0 ) return nums[0];
         int sum =  nums[0];

         for(int i = 1 ; i <n; i++){
             if(nums[i] == nums[i-1] || nums[i] <= 0) continue; 
             
              sum += nums[i];
         }
    
         return sum; 
 
    }
};








//Approach 4

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        
       vector<int>cnt(101, 0) ; 
       int maxi = *max_element(nums.begin(), nums.end()) ; 
       if(maxi < 0 ) return maxi ; 
          int sum = 0;

         for(int i = 0 ; i <n; i++){
             if(nums[i] <= 0 || cnt[nums[i]] > 0  ) continue; 
              cnt[nums[i]]++;
              sum += nums[i];
         }
         return sum; 

    }
};



//Approach 5 
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        
       unordered_set<int>st;  
     
          int sum = 0;
          int maxNegative = INT_MIN; 

         for(int i = 0 ; i <n; i++){
            if(nums[i] <= 0 ){
                maxNegative = max(maxNegative, nums[i]);
            }

            else if(!st.count(nums[i])){
                sum += nums[i];
                st.insert(nums[i]);
            }
         }
         return (sum == 0 ) ? maxNegative : sum; 

    }
};




//Approach 6
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        
      vector<int>cnt(101, 0);
     
          int sum = 0;
          int maxNegative = INT_MIN; 

         for(int i = 0 ; i <n; i++){
            if(nums[i] <= 0 ){
                maxNegative = max(maxNegative, nums[i]);
            }

            else if(cnt[nums[i]] ==  0){
                sum += nums[i];
                cnt[nums[i]]++;
            }
         }
         return (sum == 0 ) ? maxNegative : sum; 

    }
};