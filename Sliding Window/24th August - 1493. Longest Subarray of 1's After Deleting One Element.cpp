// 1493. Longest Subarray of 1's After Deleting One Element



// Approach 1 
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
       vector<int>prevOneCount(n);
       vector<int>nextOneCount(n);
       int cnt =  0 ; 
       for(int i = n-1; i >=0; i--){
           if(nums[i]==0){
              nextOneCount[i] = 0; 
              cnt=0;
           }
           else{
            cnt++;
            nextOneCount[i] = cnt; 
           }
       }

       cnt = 0 ; 
       for(int i = 0 ; i < n; i++){
           if(nums[i] == 0 ){
              prevOneCount[i] =  0; 
              cnt = 0 ;
           }
           else{
              cnt++;
              prevOneCount[i] = cnt; 
           }
       }
         int result = 0 ; 
       for(int i = 0 ; i < n; i++){
             int curr = (i-1>=0) ?  prevOneCount[i-1] : 0;
             curr+=nums[i];
             curr+= i+1<n ? nextOneCount[i+1] : 0;
              result = max(result ,  curr );
       }
       return result == n ? result -1 : result; 
        
    }
};









//Approach 2 
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0 ; 
        int j =0 ; 
        int result = 0 ; 
        int prev = 0;
        while( j < n && nums[j] == 0 ){
            j++;
        }
        i=j;

        while( j < n ){
            if(nums[j] == 0){
                prev = j - i ;
                if(j + 1 < n && nums[j + 1] == 1 ){
                    j++;
                    i=j;
                    while( j < n  && nums[j] == 1){
                        j++;
                    }
                    result = max(result , j - i  + prev);
                }
                else{
                    while( j < n && nums[j]==0){
                        j++;
                    }
                    i = j;
                }
            }
            else{
                result = max(result , j - i + 1 );
                j++;
            }
        }
        return result == n ? result -1 : result; 

    }
};










//Approach 3 
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int zeros = 0 ; 
        int result = 0 ; 

        int i = 0 ; 
        int j = 0 ; 


        while( j < n ){
            if(nums[j] == 0 ) {
                zeros++;
                while(zeros > 1){
                    if(nums[i] == 0 ) zeros--;
                    i++;
                }
            }
            result = max(result , j - i );
            j++;
        }
        return result; 
    }
};













//Approach 4 
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int last_zero = -1 ; 
        int result = 0 ; 

        int i = 0 ; 
        int j = 0 ; 


        while( j < n ){
            if(nums[j] == 0 ) {
               i = last_zero + 1;
               last_zero = j ;
            }
            result = max(result , j - i );
            j++;
        }
        return result; 
    }
};