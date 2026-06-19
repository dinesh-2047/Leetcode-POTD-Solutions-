// 1732. Find the Highest Altitude

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();

        int prev = 0 ; 
        int result = 0 ; 

        for(int i = 0 ; i < n; i++){
           int alt = prev + gain[i];
           result = max(result, alt);
           prev = alt; 
        }
        return result; 
    }
};