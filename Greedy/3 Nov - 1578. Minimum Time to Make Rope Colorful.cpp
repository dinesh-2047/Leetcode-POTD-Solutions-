// 1578. Minimum Time to Make Rope Colorful



class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();

        int result = 0 ; 

        int prev = 0 ; 

        for(int i = 1; i  < n; i++){
            if(colors[i] == colors[prev]){
                if(neededTime[i] > neededTime[prev]){
                    result += neededTime[prev];
                    prev = i; 
                }
                else{
                     result += neededTime[i];
                }
            }
            else prev = i; 
        }
        return result; 
    }
};