// 3633. Earliest Finish Time for Land and Water Rides I

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();


        int result = 1e9; 
        for(int i = 0 ; i  < n; i++){
            for(int j = 0 ; j  < m; j++){
                  int sum = landStartTime[i] + landDuration[i];
                if(waterStartTime[j] <= sum){
                    sum += waterDuration[j]; 
                }
                else sum = waterStartTime[j] + waterDuration[j];

                result = min(result, sum);
            }
        }
        for(int i = 0 ; i  < m; i++){
            for(int j = 0 ; j  < n; j++){
                int sum = waterStartTime[i] + waterDuration[i];
                if(landStartTime[j] <= sum){
                    sum += landDuration[j]; 
                }
                else sum = landStartTime[j] + landDuration[j];

                result = min(result, sum);
            }
        }
        return result; 
    }
};