// 757. Set Intersection Size At Least Two


class Solution {
public:
static bool cmp(vector<int> &a, vector<int> &b){
    if(a[1] == b[1]) return a[0] > b[0];
    return  a[1] < b[1];
}

    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(begin(intervals), end(intervals), cmp);

        int result = 0 ; 
        int first = -1 ; 
        int second = -1 ; 
        

        for(int i = 0; i < n; i++){
            int curr_st = intervals[i][0];
            int curr_end = intervals[i][1];
            if(curr_st <= first){
                continue; 
            }
          
           else if(curr_st > second){
              result +=2 ; 
              first = curr_end -1; 
              second = curr_end; 
           }

           else{
             result++;
             first = second ; 
             second = curr_end; 
           
           }
 
        }
        return result; 
    }
};