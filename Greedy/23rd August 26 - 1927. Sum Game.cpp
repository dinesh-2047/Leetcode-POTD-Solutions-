// 1927. Sum Game

class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();

        int sum = 0 ; 
        int countq = 0 ; 

        for(int i = 0 ; i < n; i++){
            if(num[i] == '?') countq++;
            else sum  += (num[i] - '0');
        }

        if(countq%2 == 1) return true; 

        int countlq = 0 ; 
        int l = 0 ; 

        for(int i = 0 ; i < n/2; i++){
            if(num[i] == '?') countlq++;
            else l += (num[i] - '0');
        }

        int r = sum - l ; 
        int countrq = countq - countlq; 

        int left = 2*l+9*countlq; 
        int right = 2 * r + 9 * countrq; 

        return left != right; 


    }
};