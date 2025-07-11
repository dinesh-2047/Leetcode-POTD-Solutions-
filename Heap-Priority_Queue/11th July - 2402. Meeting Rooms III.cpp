// 2402. Meeting Rooms III


class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(begin(meetings), end(meetings));
        vector<int>count(n, 0);
        priority_queue<pair<long long, long long> , vector<pair<long long, long long>>, greater<>>pq; 
        priority_queue<long long , vector<long long>, greater<>>freeRooms; 


        for(int i = 0;i <n; i++){
            freeRooms.push(i);
        }

        for(int i = 0 ; i <meetings.size(); i++){
             int startTime = meetings[i][0];
             int endTime = meetings[i][1];
             long long duration  = endTime - startTime; 

             while(!pq.empty() && pq.top().first<=startTime){
                 freeRooms.push(pq.top().second);
                  pq.pop();
                 
             }

             if(!freeRooms.empty()){
                int room = freeRooms.top();
                freeRooms.pop();
                count[room]++;
                pq.push({endTime, room});
             }

             else{
               long long earlyEndTime = pq.top().first; 
                int room = pq.top().second; 
                count[room]++;
                pq.pop();
                pq.push({earlyEndTime + duration , room});
             }

        }

        int result = 0 ; 
        int val = 0 ; 

        for(int i =0 ; i < n ;i++){
            if(count[i] > val){
                result = i; 
                val = count[i];
            }
        }
        return result; 

    }
};