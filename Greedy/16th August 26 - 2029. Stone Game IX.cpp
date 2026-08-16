// 2029. Stone Game IX

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();
        
        int cnt0 = 0 ; 
        int cnt1 = 0 ; 
        int cnt2 = 0 ; 

        for(int i = 0 ; i  < n  ; i++){
            if(stones[i]%3 ==  1) cnt1++;
            else if(stones[i]%3 == 2) cnt2++;
            else cnt0++;
        }
        if(cnt0%2 == 0 && cnt1 > 0 && cnt2 > 0 ) return true; 
        if(cnt0%2 == 1 && abs(cnt1 - cnt2) >= 3) return true; 
        return false; 
    }
};