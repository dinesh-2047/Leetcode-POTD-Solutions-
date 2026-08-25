// 3718. Smallest Missing Multiple of K


class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
       vector<int> freq(201, 0);
       for(auto &x : nums) freq[x]++;

        for(int i = k ; i <= 200 ; i+=k){
            if(!freq[i]) return i ; 
        }
        return k ; 
    }
};