// 657. Robot Return to Origin


class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0 ; 
        int y = 0 ; 

        for(auto &ch : moves){
            if(ch == 'U') y++;
            if(ch == 'D') y--;
            if(ch == 'L') x--;
            if(ch == 'R') x++;

        }
        return x == 0 && y == 0 ;
    }
};