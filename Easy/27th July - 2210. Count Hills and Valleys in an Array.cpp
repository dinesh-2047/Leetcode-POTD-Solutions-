// 2210. Count Hills and Valleys in an Array/



// Approach 1 
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();

        int result = 0 ; 

        for(int i = 1 ; i < n-1; i++){
            int leftNonEqualClosest = -1;
            int rightNonEqualClosest = -1 ; 
            for(int j = 0 ; j < i ; j++){
                if(nums[j]!=nums[i]) leftNonEqualClosest = nums[j];
            }

            for(int j = i+1; j < n; j++){
              if(nums[j]!=nums[i]){
                 rightNonEqualClosest = nums[j];
                 break; 
              }
            }

            if(leftNonEqualClosest !=-1 && rightNonEqualClosest != -1){
                    if(leftNonEqualClosest < nums[i] && rightNonEqualClosest < nums[i]) result++;
                    else if(leftNonEqualClosest > nums[i] && rightNonEqualClosest > nums[i]) result++;
            } 
            while(i < n-1 &&  nums[i] == nums[i+1]){
                   i++;
                  
            } 
             
        }
        return result; 
    }
};







//Approach 2 

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();

        int left = nums[0];
        int result = 0;

        for (int i = 1; i < n - 1; i++) {
            while (i < n - 2 && nums[i] == nums[i + 1])
                i++;
            if (left > nums[i] && nums[i + 1] > nums[i]) {
                result++;
                left = nums[i];
            }
            if (left < nums[i] && nums[i + 1] < nums[i]) {
                result++;
                left = nums[i];
            }
        }

        return result;
    }
};










//Approach 3 
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int up = 0 ; 
        int down = 0 ; 

        int result = 0 ; 

        for(int i = 1 ; i < n; i++){
            if(nums[i] > nums[i-1]){
                up = 1 ; 
                if(down){
                    result++;
                    down = 0 ; 
                }

            }
            else if(nums[i] < nums[i - 1] ){
                down = 1; 
                if(up){
                    result++;
                    up = 0 ; 
                }
            }
        }
        return result; 
    }
};