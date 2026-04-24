// 2833. Furthest Point From Origin


class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();

        int countl = 0 ; 
        int countr = 0 ; 

        for(auto &x : moves){
            if(x == 'L') countl++;
            if(x == 'R') countr++;
        }

        int dashes = n - countl - countr; 

        return abs(countl - countr) + dashes; 
    }
};