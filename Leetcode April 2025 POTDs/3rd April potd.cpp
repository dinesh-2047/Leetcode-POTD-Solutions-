// 2873. Maximum Value of an Ordered Triplet II


// Approach 1   TLE
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            long long ans = 0 ; 
    
            for(int i = 0 ; i < n-2 ; i++){
                for(int j = i+1 ; j <n-1; j++)
                     for(int k = j+1; k <n; k++){
                        ans = max(ans, (long long )(nums[i]-nums[j]) * nums[k]);
                     }
    
            }
            return ans; 
        }
    };



//Approach 2 
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            long long ans = 0; 
    
            vector<int>leftMax(n);
            vector<int>rightMax(n);
    
            leftMax[0] = 0;
            rightMax[n-1] = 0;
    
            for(int i= 1 ; i<n; i++){
                leftMax[i] = max(leftMax[i-1], nums[i-1]);
            }
    
            for(int i = n-2; i >= 0 ; i--){
                rightMax[i] = max(rightMax[i+1], nums[i+1]);
            }
    
            for(int j = 1; j < n ; j++){
                ans = max(ans, (long long)(leftMax[j]-nums[j])*rightMax[j]);
            }
            return ans; 
        }
    };




///Approach 3 
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long ans = 0 ; 
            int n = nums.size();
            long long  max_i = 0 ; 
            long long  maxDiff = 0; 
        
    
            for(int k = 0 ; k < n; k++){
                   ans = max(ans, (long long ) (maxDiff * nums[k]));
                   maxDiff = max(maxDiff, max_i - nums[k]);
                   max_i = max(max_i , (long long )nums[k]);
            }
            return ans; 
        }
    };