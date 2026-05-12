// 1665. Minimum Initial Energy to Finish Tasks

class Solution {
public:
static bool cmp(vector<int> &a, vector<int> &b){
    return a[1] - a[0] > b[1] - b[0];
}
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();

        sort(begin(tasks), end(tasks), cmp);
        int result = tasks[0][1];

        int e = tasks[0][1] - tasks[0][0];

        for(int i = 1;  i < n; i++){
            int actual = tasks[i][0];
            int mini = tasks[i][1];

            if(e >= mini){
                e -= actual;
            }
            else if(e < mini){
                result += (mini - e);
                e = mini; 
                e -= actual; 
            }
        }

       
        return result; 
       
    }
};