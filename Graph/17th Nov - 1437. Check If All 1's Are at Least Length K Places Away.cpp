// 1437. Check If All 1's Are at Least Length K Places Away


// Approach 1

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();

        bool firstOne = false; 
        int count0  = 0 ; 

        for(int i = 0 ; i  < n; i++){
            if(nums[i] == 0){
                count0++;
            }
            else{
                if(firstOne && count0 < k ){
                    return false; 
                }
                else{
                    firstOne = true; 
                    count0 = 0 ; 
                }
            }
        }
        return true; 
    }
};



//Approach 2 
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();

        int prev1 = -1 ; 

        for(int i = 0 ;i < n; i++){
              if(nums[i] == 0 ) continue; 

                if(prev1 == - 1){
                    prev1 = i;
                }
                else if((i - prev1 - 1 ) < k  ){
                    return false; 
                }
                else {
                    prev1 = i; 
                }
            
        }
        return true; 
    }
};