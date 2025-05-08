// 3342. Find Minimum Time to Reach Last Room II



#define p pair<int , pair<int , int>>
class Solution {
public:
vector<vector<int>>directions = {{0,1},{0,-1},{1,0},{-1,0}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();

        priority_queue<p, vector<p>, greater<>>pq; 
        vector<vector<int>>result(m , vector<int>(n , INT_MAX));
        result[0][0] = 0 ;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int currTime = curr.first ;
            int i = curr.second.first; 
            int j = curr.second.second ; 


            for(auto &dir : directions){
                int newi = i   +  dir[0];
                int newj = j  + dir[1];

                if(newi < m && newj <n && newi >= 0 && newj >= 0 ){
                    int waitingTime = max(moveTime[newi][newj] - currTime , 0 );
                    int finalTime = currTime  + waitingTime; 

                    if((i + j )%2==0) finalTime += 1;
                    else finalTime += 2;
                    if(result[newi][newj] > finalTime){
                        result[newi][newj] = finalTime; 
                        pq.push({finalTime, {newi, newj}});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};