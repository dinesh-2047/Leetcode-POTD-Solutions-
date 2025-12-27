// 2402. Meeting Rooms III

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(begin(meetings), end(meetings));
        priority_queue<pair<long long, long long> , vector<pair<long long, long long>>, greater<>>pq; 
        priority_queue<long long , vector<long long>, greater<>>freeRoom; 
        vector<int>usedRoomCount(n , 0);

        for(int i= 0 ; i  < n; i++)
            freeRoom.push(i);

        for(auto &meeting : meetings){
            int start = meeting[0];
            int end = meeting[1];

            while(!pq.empty() && pq.top().first <= start){
                freeRoom.push(pq.top().second);
                pq.pop();
            }

            if(!freeRoom.empty()){
                int room = freeRoom.top();
                freeRoom.pop();

                usedRoomCount[room]++;
                pq.push({end , room});

            }
            else{
                long long delay = pq.top().first - start; 
                int room = pq.top().second ; 
                usedRoomCount[room]++;
                pq.pop();
                pq.push({end + delay , room});
            }
        }

        int result = 0 ; 
        long long val = 0 ; 

        for(int i = 0 ;i < n; i++){
            if(val < usedRoomCount[i] ){
                result = i ; 
                val = usedRoomCount[i];
            }
        }
        return result; 
    }
};