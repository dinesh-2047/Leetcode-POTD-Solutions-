// 2016. Maximum Difference Between Increasing Elements


// Approach 1 

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();

        int result = -1 ; 
        for(int i = 0 ; i < n-1; i++){
            for(int j= i + 1; j <n; j++){
                if(nums[i] < nums[j]){
                  result = max(result , abs(nums[j] - nums[i]));
                }
            }
        }
        return result; 
    }
};






//Approach 2 
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>largerToRight(n);
        vector<int>smallerToLeft(n);
        largerToRight[n-1] = nums[n-1];
        smallerToLeft[0] = nums[0];

        for(int i = 1 ; i <n; i++){
            smallerToLeft[i] = min(smallerToLeft[i-1], nums[i]);
        }

        for(int i = n-2; i>= 0; i--){
            largerToRight[i] = max(largerToRight[i+1], nums[i]);
        }

        int result = -1 ; 

        for(int i = 0 ; i<n; i++){
            if(smallerToLeft[i]!=largerToRight[i]){
                result = max(result, abs(largerToRight[i] - smallerToLeft[i]));
            }
        }
        return result; 
    }
};







//Approach 3 
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        
        int mini = nums[0];
        int result = -1; 

        for(int i = 1 ; i<n; i++){
             if(nums[i] >  mini){
                result = max(result, abs(nums[i] - mini));
             }

             else mini = nums[i];
        }

        return result; 

    }
};