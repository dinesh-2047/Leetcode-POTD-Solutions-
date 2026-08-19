// 1386. Cinema Seat Allocation


class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int , array<bool, 11>> mp ; 

        for(auto &rs : reservedSeats){
            int row = rs[0];
            int seat = rs[1];

            mp[row][seat] = true; 
        }

        int result = 0 ; 

        for(auto &[row, v] : mp){
            //first group 
            bool fg = false; 
            if(!v[2] && !v[3] && !v[4] && !v[5]) {
                result++;
                fg = true; 
            }

            //second group 
            bool sg = false; 
            if(!fg && !v[4] && !v[5] && !v[6] &&!v[7])  {
                  result++;
                  sg = true; 
            }
            if(!sg && !v[6] && !v[7] && !v[8] && !v[9]) result++;
        }

        int rem = n - mp.size();
        result += (rem * 2);

        return result;
    }
};