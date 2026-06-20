// 1840. Maximum Building Height


class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restr) {
        restr.push_back({1, 0});
        restr.push_back({n, n-1});
        sort(begin(restr), end(restr));

         int N = restr.size();
        // left to right 
        for(int i = 1 ; i  < N; i++){
            int diffDist = restr[i][0] - restr[i-1][0];
            restr[i][1] = min(restr[i][1], restr[i - 1][1] + diffDist);
        }

        //right to left
        for(int i = N - 2; i>= 0 ; i--){
             int diffDist = restr[i+1][0] - restr[i][0];
            restr[i][1] = min(restr[i][1], restr[i + 1][1] + diffDist);
        }

        int result = 0 ; 

        for(int i = 1; i < N; i++){
             int left_pos = restr[i-1][0];
             int left_h = restr[i - 1][1];

             int curr_pos = restr[i][0];
             int curr_h = restr[i][1];

              int d = curr_pos - left_pos; 
              int hDiff = abs(left_h - curr_h);
              int peak = max(left_h, curr_h)  + (d - hDiff)/2; 

             result = max(result, peak);
        }

        return result; 
    }
};