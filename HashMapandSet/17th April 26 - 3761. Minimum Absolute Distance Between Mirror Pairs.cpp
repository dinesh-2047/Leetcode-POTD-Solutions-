// 3761. Minimum Absolute Distance Between Mirror Pairs


class Solution {
public:
int get_rev(int x){
    int num = 0 ; 
    while(x){
        num = (num * 10 ) + (x%10);
        x/=10; 
    }
    return num ; 
}

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int , int>mp ; 
        int result = INT_MAX; 
        for(int i =0  ; i  < n; i++){
            int x = nums[i];
            int revx = get_rev(nums[i]);

            if(mp.count(x)){
                result = min(result, abs(mp[x] - i));
            }
            mp[revx] = i; 
        }
        return result == INT_MAX ? -1: result;  
    }
};