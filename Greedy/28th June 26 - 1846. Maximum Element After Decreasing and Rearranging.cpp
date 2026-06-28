// 1846. Maximum Element After Decreasing and Rearranging

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();

        sort(begin(arr), end(arr));
        int result = 1;
        int prev = 1; 
        for(int i = 1; i  < n;  i++){
            if(arr[i] - prev > 1){
                prev = prev + 1 ; 
            }
            else prev = arr[i];
            result = max(result, prev);
           
        }
        return result; 


    }
};