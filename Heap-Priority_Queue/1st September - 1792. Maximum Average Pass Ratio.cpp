// 1792. Maximum Average Pass Ratio

#define pi pair<double , int>
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<pi>pq; 
        for(int i = 0 ; i < n; i++){
            double curr_pass_ratio = (double)classes[i][0]/classes[i][1];
            double updated_pass_ratio = (double) (classes[i][0]+1)/( classes[i][1] + 1);
            double diff = updated_pass_ratio - curr_pass_ratio;
            pq.push({diff ,i});
        }

        while(extraStudents--){
            auto curr = pq.top();
            pq.pop();

            double diff = curr.first; 
            int idx = curr.second; 

            classes[idx][0]++;
            classes[idx][1]++;

             double curr_pass_ratio = (double)classes[idx][0]/classes[idx][1];
            double updated_pass_ratio = (double) (classes[idx][0]+1)/( classes[idx][1] + 1);
            double new_diff = updated_pass_ratio - curr_pass_ratio;
            pq.push({new_diff ,idx});
        }

        double result = 0.0;
        for(int i = 0 ; i < n; i++){
            result += (double)classes[i][0] / classes[i][1];

        }
        return result/n; 
    }
};