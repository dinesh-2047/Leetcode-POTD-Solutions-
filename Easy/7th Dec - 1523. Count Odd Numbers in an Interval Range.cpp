// 1523. Count Odd Numbers in an Interval Range

class Solution {
public:
    int countOdds(int low, int high) {
       int diff = high - low; 
        diff/=2; 
        if(low % 2 == 1 || high % 2 == 1) diff++;
        return diff ;
    }
};