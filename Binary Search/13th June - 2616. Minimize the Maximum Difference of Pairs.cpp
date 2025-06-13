// 2616. Minimize the Maximum Difference of Pairs


class Solution {
public:
bool isPossible(vector<int> &nums, int mid , int p ){
    int count = 0 ; 
    int n = nums.size();

    for(int i = 0 ; i <n-1; i++){
        if(abs(nums[i]-nums[i+1]) <= mid){
            count++;
            i++;
        }
    }
    return  count >= p;
}

    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int result = 0 ; 
        int st = 0; 
        int end = abs(nums[0] - nums[n-1]);

        while(st <= end){
            int mid = st + (end - st)/2;

            if(isPossible(nums, mid, p)){
                result = mid ; 
                end = mid - 1; 
            }
            else st = mid + 1; 
        }
        return result ;
    }
};