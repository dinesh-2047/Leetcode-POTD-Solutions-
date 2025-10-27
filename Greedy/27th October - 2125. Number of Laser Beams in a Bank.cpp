// 2125. Number of Laser Beams in a Bank/\


class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int result = 0 ; 
        int prevCount = 0 ; 

        for(int i = 0 ; i < n; i++){
            string s = bank[i];
            int currCount = 0 ; 
            for(auto &ch : s){
                if(ch == '1'){
                    currCount++;
                }
            }
            if(currCount != 0 ){
                result += (currCount * prevCount);
                prevCount = currCount; 
            }
        }
        return result; 
    }
};