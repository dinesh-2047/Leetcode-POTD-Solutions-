// 3440. Reschedule Meetings for Maximum Free Time II




class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

       vector<int> gaps(n + 1);

        gaps[0] = startTime[0];
        for (int i = 1; i < n; i++) {
            gaps[i] = startTime[i] - endTime[i - 1];
        }

      gaps[n] = eventTime - endTime[n-1];
        vector<int>rightMaxGap(n+1,0);
        vector<int>leftMaxGap(n+1,0);



        for(int i = n-1; i >= 0 ;i--){
            rightMaxGap[i] = max(gaps[i+1], rightMaxGap[i+1]);
        }
       
       for(int i = 1; i <=n ; i++){
          leftMaxGap[i] = max(gaps[i-1], leftMaxGap[i-1]);
       }

       int result = *max_element(gaps.begin(), gaps.end()) ; 
       
        for(int i = 1 ; i <=n; i++){
            int currEventduration = endTime[i-1] - startTime[i-1];
            if(currEventduration <= rightMaxGap[i] ||   currEventduration  <= leftMaxGap[i-1] ){
                     int leftGap = gaps[i-1] ;
                int rightGap = gaps[i] ;

                  int case1 = leftGap + currEventduration + rightGap ;
                

                  result = max(result, case1);
                    
            }
            int case2 = gaps[i-1] + gaps[i];
            result = max(result, case2);
            
            
               
        }
        return result; 
    }
};