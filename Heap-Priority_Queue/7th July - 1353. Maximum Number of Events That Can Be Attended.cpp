// 1353. Maximum Number of Events That Can Be Attended

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
          sort(events.begin(), events.end());
         int result = 0 ; 
         int i = 0 ; 
         int d = 0 ; 

         priority_queue<int , vector<int> , greater<>>pq; 

         while(!pq.empty() || i < n ){
          
            if(pq.empty()){
                d = events[i][0];
            }

            while(i < n && events[i][0] == d){
                pq.push(events[i][1]);
                i++;
            }

            if(!pq.empty()){
                pq.pop();
                result++;
            }

            d++;

            while(!pq.empty() && pq.top() < d){
                pq.pop();
            }
     

         }
         return result; 
    }
};