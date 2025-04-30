// 1295. Find Numbers with Even Number of Digits


// Approach 1 ; 
class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int n = nums.size();
            int count = 0  ; 
    
            for(int i = 0 ; i < n ; i++){
                string s = to_string(nums[i]);
    
                if(s.length()%2==0) count++;
            }
            return count; 
        }
    };



//Approachs 2 
class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int n = nums.size();
            int count = 0  ; 
    
            for(int i = 0 ; i < n ; i++){
               if(nums[i] >=  10 && nums[i] <= 99) count++; 
               if(nums[i] >= 1000 && nums[i] <= 9999) count++;
    
               if(nums[i] >= 100000) count++;
            }
            return count; 
        }
    };



//Approach 3 
class Solution {
    public:
    void countDigits(int num , int &digits ){
        
        while(num){
            digits++;
            num /= 10;
        }
      
    }
    
        int findNumbers(vector<int>& nums) {
            int n = nums.size();
            int count = 0  ; 
    
            for(int i = 0 ; i < n ; i++){
                int digits = 0; 
                countDigits(nums[i], digits);
    
              if(digits%2 == 0 ) count++;
            }
            return count; 
        }
    };



//Approach 4 ; 
class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int n = nums.size();
              int count = 0 ; 
            for(int i= 0 ; i<n; i++){
                int digits = floor(log10(nums[i])) + 1;
                if(digits %2 == 0 )count++;
            }
            return count;
        }
    };




//Approach 5 
class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int n = nums.size();
              int count = 0 ; 
            for(int i= 0 ; i<n; i++){
                int digits = ceil(log10(nums[i]+1));
                if(digits %2 == 0 )count++;
            }
            return count;
        }
    };