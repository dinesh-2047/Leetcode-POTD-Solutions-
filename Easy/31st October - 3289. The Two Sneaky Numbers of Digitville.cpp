// 3289. The Two Sneaky Numbers of Digitville/



// Approach 1 

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();

        vector<int>freq(n, 0);

        for(auto &num : nums){
            freq[num]++;
        }
        vector<int>result;
        for(int i = 0 ; i < n; i++){
             if(freq[i] > 1){
                result.push_back(i);
             }
        }
        return result; 
    }
};




//approach 2 
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size()-2;

        int totalSum = (n * (n - 1))/2; 
        int totalSquareSum = (n * (n - 1) * ( 2 * n - 1))/6; 

        int sum = 0 ; 
        int squareSum = 0 ; 

        for(auto &num : nums){
            sum += num; 
            squareSum += num * num ; 
        }

        int s = sum - totalSum ; 
        int q = squareSum - totalSquareSum;

        int p = (s * s - q)/2; 

        int x1 = (s - sqrt(s*s - 4 * p))/2; 
        int x2 = (s + sqrt(s *s - 4 * p ))/2; 

        return {x1, x2};
    }
};





//Approach 3
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() - 2;

        int xorr = 0 ;
        for(auto &num : nums){
            xorr ^= num; 
        }

        for(int i = 0 ; i  < n ; i++){
            xorr ^= i ; 
        }

        int trailingZeros = __builtin_ctz(xorr);
        int mask = 1 << trailingZeros; 

        int g1  = 0 ; 
        int g2 = 0 ; 

        for(auto &num : nums){
            if(num & mask){
                g1 ^= num; 
            }
            else g2 ^= num ; 
        }

        for(int i = 0 ; i < n; i++){
            if(i & mask){
                g1 ^= i; 
            }
            else g2 ^= i; 
        }
        return {g1, g2};
    }
};




//Approach 4 
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();

        vector<int>result(2, 0); 
        int j = 0 ; 
        for(int i = 0 ; i  < n; i++){
            int val = abs(nums[i]);
             if(val == 101){
                continue; 
             }
            if(nums[val] < 0){
               result[j++] = val; 
            }
            else if(nums[val] == 0 ){   
                nums[val] = -101;
            }
            else nums[val] = -nums[val];
        }
        return result; 
    }
    
};