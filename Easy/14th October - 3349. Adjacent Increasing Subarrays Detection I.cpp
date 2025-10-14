// 3349. Adjacent Increasing Subarrays Detection I


// Approach 1
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = 0 ; i  < n; i++){
            for(int j = i  ; j  < n; j++){
                if(j-1 >= 0  && i!=j &&  nums[j] <= nums[j - 1] ) break;  
                if(j-i + 1 >= k ){
                     if(n-1-j < k ) return false; 
                     bool valid = true; 
                     for(int l = j  +2 ; l <= j + k ; l++){
                         if(nums[l] <= nums[l- 1]) {
                            valid = false; 
                            break; 
                         }
                     }
                     if(valid ) return true; 
                }
            }
        }
        return false; 
    }
};


//Approach 2 
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n  = nums.size();

        int i = 0 ; 
        int j = 0 ; 

        while(j < n ){
            if(j-1 >= 0 && nums[j] <= nums[j-1]){
                i++;
                j = i ; 
            }
            if((j-i + 1) >=  k ){
                bool valid = true; 
                int l ; 
                if(n-1-j < k) return false; 
               for( l = j + 2 ; l <=  j + k ; l++){
                     if( nums[l] <= nums[l - 1]){
                        i++;
                        j= i ; 
                        valid = false; 
                        break; 
                     }
                    
               }
                if(valid && (l - j + 2) >= k ) return true; 
                
            }
            j++;
        }
        return false; 
    }
};



//approach 3
class Solution {
public:
bool check(vector<int> &nums, int st , int end){
    for(int i = st + 1 ; i < end; i++){
        if(nums[i] <= nums[i - 1]) return false; 
    }
    return true; 
}

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = 0 ;i + 2 * k <= n; i++){
            bool first = check(nums, i, i + k);
            bool second = check(nums, i + k ,i + 2*k);

            if(first && second) return true; 
        }
        return false; 
    }
};


//Approach 4
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int currLen = 1 ; 
        int prevLen = 0 ; 

        for(int i = 1;  i < n ; i++){
            if(nums[i] > nums[i - 1]){
                currLen++;
            }
            else{
                prevLen = currLen ; 
                currLen = 1; 

            }

            if(currLen >= 2*k || min(currLen, prevLen) >= k) return true; 
           
        }
        return false; 
    }
};