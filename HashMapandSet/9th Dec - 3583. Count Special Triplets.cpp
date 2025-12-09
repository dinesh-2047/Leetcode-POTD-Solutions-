// 3583. Count Special Triplets


//Approach  1
class Solution {
public:
int mod = 1e9 + 7 ;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int , int>mp ;
        unordered_map<int , int>mp1; 
        for(int i = 1 ; i  < n; i++) mp1[nums[i]]++;
        mp[nums[0]]++;
        long long result = 0 ; 

        for(int i = 1 ; i< n-1; i++ ){
            mp1[nums[i]]--;
                  result = (result +  1LL * mp[nums[i] * 2] * mp1[nums[i] * 2])%mod;
            mp[nums[i]]++;
        }
        return result; 
        
    }
};




// Approach 2
class Solution {
public:
int mod = 1e9 + 7 ;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int , int>valid_i ; 
        unordered_map<int , int>valid_j; 
        long long result = 0 ; 
        
        for(int i = 0 ; i  < n; i++){
            
            if(nums[i]%2 == 0 ){
                result = (result + valid_j[nums[i]/2])%mod; 
            }
            valid_j[nums[i]] = (valid_j[nums[i]] + valid_i[nums[i]*2])%mod; 
            valid_i[nums[i]]++;
        }
        return result; 
    }
};