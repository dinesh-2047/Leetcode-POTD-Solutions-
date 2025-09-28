// 976. Largest Perimeter Triangle



// Approach 1 

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n  = nums.size();

        int perimeter = 0 ;
         sort(rbegin(nums), rend(nums));

         for(int i = 0 ; i < n-2; i++){
             double a = nums[i];
             double b = nums[i + 1];
             double c = nums[i + 2];

             if((a + b) <= c || (b + c ) <= a || ( a + c) <= b) continue; 

             double s = (a + b + c)/2; 

             double area = sqrtl(s * (s- a) * (s - b) * (s -c));

             if(area != 0){
                perimeter = max(perimeter, (int)(a+ b+ c));
             }
         }


       
        return perimeter; 
        
    }
};











//Approach 2 
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(rbegin(nums), rend(nums));

        for (int i = 0; i < n - 2; i++) {
            int a = nums[i];
            int b = nums[i + 1];
            int c = nums[i + 2];

            if (b + c > a)
                return a + b + c;
        }

        return 0;
    }
};