// 3661. Maximum Walls Destroyed by Robots

class Solution {
public:
int n; 
vector<vector<int>>dp ;  
int count_walls(vector<int> &walls, int left, int right){
    int l = lower_bound(begin(walls), end(walls), left) - begin(walls);
    int r = upper_bound(begin(walls), end(walls), right) - begin(walls);

    return r - l;
}

int solve(vector<int> &walls , vector<pair<int, int>> &roboDist, vector<pair<int , int>> &range, int i , int prev_dir){
    if( i >= n ) return 0; 


    if(dp[i][prev_dir] != -1) return dp[i][prev_dir];

    int leftSt = range[i].first; 

    if(prev_dir == 1){
        leftSt = max(leftSt, range[i - 1].second + 1);
    }

    int take_left = count_walls(walls, leftSt, roboDist[i].first) + solve(walls, roboDist, range, i + 1, 0);

    int take_right = count_walls(walls, roboDist[i].first, range[i].second) + solve(walls, roboDist, range, i + 1, 1);

    return dp[i][prev_dir] = max(take_left, take_right);
}

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
       n = robots.size() ;

       vector<pair<int , int>>roboDist(n);
       for(int i = 0 ; i  < n; i++){
          roboDist[i] = {robots[i], distance[i]};
       }

       sort(begin(roboDist), end(roboDist));
       sort(begin(walls), end(walls));

       vector<pair<int , int>>range(n);
       for(int i = 0 ; i  < n; i++){
         int pos = roboDist[i].first; 
         int d = roboDist[i].second; 

        int leftLim =  (i == 0 ) ? 1 :  roboDist[i - 1].first + 1; 
        int rightLim = (i + 1 >= n) ? 1e9 :  roboDist[i + 1].first - 1; 

        int l = max(pos - d , leftLim);
        int r = min(pos + d, rightLim);

        range[i] = {l, r};

       }
       dp.assign(n + 1, vector<int> (2, -1));

       return solve(walls, roboDist, range , 0 , 0 );
    }
};