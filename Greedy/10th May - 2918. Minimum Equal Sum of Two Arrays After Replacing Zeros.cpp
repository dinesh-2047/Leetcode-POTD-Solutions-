// 2918. Minimum Equal Sum of Two Arrays After Replacing Zeros 

// Greedy simple solution 
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        long long  zeroCountNums1 = 0;
        long long zeroCountNums2 = 0 ;
        long long sum1 = 0;
        long long sum2 = 0 ;

        for(int i = 0 ; i<n; i++) {
            if(nums1[i] == 0 ) zeroCountNums1++;
            sum1 += nums1[i];
        }
        sum1+=zeroCountNums1;
        for(int i = 0 ; i<m ; i++){
            if(nums2[i] == 0 ) zeroCountNums2++;
            sum2 += nums2[i];
        }

        sum2+=zeroCountNums2; 
    



    if(sum1 < sum2 && zeroCountNums1 == 0 ) return -1 ;
    if(sum2< sum1 && zeroCountNums2 == 0 ) return -1; 


    return max(sum1, sum2) ; 

 

 
    }
};