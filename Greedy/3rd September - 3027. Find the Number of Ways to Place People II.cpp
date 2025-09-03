// 3027. Find the Number of Ways to Place People II

class Solution {
public:
static bool cmp(vector<int> &a, vector<int> &b){
    if(a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        int result = 0 ; 
        sort(begin(points), end(points), cmp);

        for(int i = 0 ; i < n; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];

            long long maxY = LLONG_MIN;
            for(int j = i + 1; j < n; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];

                if(y2 <= y1 && y2 > maxY){
                    result++;
                    maxY = y2 ; 
                }
            }
        }
        return result; 
    }
};