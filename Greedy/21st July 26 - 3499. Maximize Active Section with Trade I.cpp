// 3499. Maximize Active Section with Trade I

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();

        vector<int> inactiveCount; 
        int count0  =0 ; 
        int count1 = 0 ;
        for(int i = 0 ; i  < n; i++){
            if(s[i] == '0'){
                count0++;
            }
            else {
                count1++;
                if(count0 == 0 ) continue; 
                inactiveCount.push_back(count0);
                count0 = 0 ; 
            }
        }
        if(count0 > 0 ) inactiveCount.push_back(count0);
        
        int maxPairSum = 0 ; 
        for(int i = 1 ; i < inactiveCount.size(); i++){
            maxPairSum = max(maxPairSum, inactiveCount[i] + inactiveCount[i-1]);
        }
        return maxPairSum + count1; 
    }
};