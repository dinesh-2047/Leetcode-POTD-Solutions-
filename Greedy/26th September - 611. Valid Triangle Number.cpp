// 611. Valid Triangle Number





// Approach 1 
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int result = 0 ; 
        for(int i = 0 ; i < n-2; i++){
            for(int j = i + 1 ; j < n-1; j++){
               for(int k = j + 1 ; k < n; k++){
                   int a = nums[i];
                   int b = nums[j];
                   int c = nums[k];

                   if(a+ b > c &&  a +c > b && b +c > a ){
                      result++;
                   }
               }
            }
        }
        return result; 
    }
};





//Approach 2 
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int result = 0 ; 
        sort(begin(nums), end(nums));
        for(int i = 0 ; i < n-2; i++){
            for(int j = i + 1 ; j < n-1; j++){
                int a = nums[i];
                int b = nums[j];
                 
               int c_idx = lower_bound(begin(nums) + j +1, end(nums), (a + b)) - begin(nums);

               result += (c_idx - j-1);
            }
        }
        return result; 
    }
};






//Approach 3
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int result = 0 ; 

        for(int k = n-1; k >= 0 ; k--){
            int i = 0 ; 
            int j = k - 1; 

            while(i < j ){
                if(nums[i] + nums[j] > nums[k]){
                    result += (j - i );
                    j--;
                }
                else i++;
            }
        }
        return result; 
    }
};