// 1288. Remove Covered Intervals

class Solution {
public:
static bool cmp(vector<int> &a, vector<int> &b){
    if(a[0] == b[0]){
        return a[1] > b[1];
    }
    return a[0] < b[0];
}
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(begin(intervals), end(intervals), cmp);

        int result = 1 ; 

        int st = intervals[0][0];
        int end = intervals[0][1];

        for(int i = 1; i  < n ; i++){
            int a = intervals[i][0];
            int b = intervals[i][1];

            if(st <= a && end >= b){
                 continue; 
            }

           if(a > end){
              st = a; 
              end = b; 
           }
           else {
               st = min(a, st);
               end = max(b, st);
           }
           result++;

        }
        return result;
    }
};