// 3190. Find Minimum Operations to Make All Elements Divisible by Three




// Approach 1 

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        int result = 0 ; 

        for(auto &num : nums){
            int op = INT_MAX ; 
            for(int i = max(0, num - 2) ; i < num + 2; i++){
                if(i%3 == 0 ){
                    op = min(op, abs(num - i));
                }
            }
            result += op;
        }
        return result; 
    }
};



//Approach 2 
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        int result = 0 ; 

       for(auto &num : nums){
          if(num%3 != 0 ){
            result++;
          }
       }
        return result; 
    }
};



//Appraoch 3 
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        int result = 0 ; 
        
        for(auto &num : nums){
            result += min(num%3, 3-(num%3));
        }
        return result; 
    }
};