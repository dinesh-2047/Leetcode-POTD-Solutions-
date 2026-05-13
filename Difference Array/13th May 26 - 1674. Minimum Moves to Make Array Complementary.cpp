// 1674. Minimum Moves to Make Array Complementary


class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> diff(2 * limit+2 , 0);
         
       
        for(int i = 0 ; i  < n/2; i++){
            int a = nums[i];
            int b = nums[n - i -1 ];

            diff[2] += 2; 
            diff[2 * limit + 1 ] -= 2; 
            diff[min(a, b) + 1]--;
            diff[max(a, b) + limit + 1]++;

            diff[a + b]-=1; 
            diff[a + b  + 1]+=1; 
            
        }
        int result = 1e9 ; 
        for(int i = 2 ; i <= 2 * limit  ; i++){
            diff[i] += diff[i -1 ];
            result = min(result, diff[i]);
           
        }
        return result; 
    }
};