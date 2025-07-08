// 1751. Maximum Number of Events That Can Be Attended II


// Approach 1 -> Sorting  + DP + Linear Search Rec + memo

class Solution {
public:
int n ; 
vector<vector<int>> dp;


int solve(vector<vector<int>> &events , int k , int i){
    if(k==0 ) return 0 ;
    if(i>=n) return 0 ;

    if(dp[i][k]!=-1) return dp[i][k];
    
     int nextIndex =i+1;
     for(; nextIndex < n; nextIndex++ ){
        if(events[nextIndex][0] > events[i][1]) break; 
     }
    int take = events[i][2] + solve(events, k-1, nextIndex);

    int not_take = solve(events, k , i+1);

    return dp[i][k] = max(take , not_take);
}

    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        sort(begin(events), end(events));
        dp.resize(n+1 , vector<int> (k+1, -1));

        return solve(events , k , 0  );
    }
};






//Appraoch 2 -> sorting + DP + Binary Search Rec+ memo

class Solution {
public:
int n ; 
vector<vector<int>> dp;
int BS(vector<vector<int>> &events, int target){
    int st = 0 ; 
    int end = n- 1; 

    while(st <= end){
        int mid = st + (end - st)/2; 
        if(events[mid][0] <= target) {
            st = mid + 1;
        }
        else end = mid - 1; 
    }
    return st ; 
}

int solve(vector<vector<int>> &events , int k , int i){
    if(k==0 ) return 0 ;
    if(i>=n) return 0 ;

    if(dp[i][k]!=-1) return dp[i][k];
    
     int nextIndex = BS(events , events[i][1]);
    int take = events[i][2] + solve(events, k-1, nextIndex);

    int not_take = solve(events, k , i+1);

    return dp[i][k] = max(take , not_take);
}

    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        sort(begin(events), end(events));
        dp.resize(n+1 , vector<int> (k+1, -1));

        return solve(events , k , 0  );
    }
};












//Approach 3 Bottom Up + Binary Search
class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int BS(vector<vector<int>>& events, int target) {
        int st = 0;
        int end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (events[mid][0] <= target) {
                st = mid + 1;
            } else
                end = mid - 1;
        }
        return st;
    }

   

    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        sort(begin(events), end(events));
        dp.resize(n + 1, vector<int>(k + 1, 0));

        // return solve(events , k , 0  );

       for(int i = n-1 ; i >=0; i--) {
            for (int j = 1 ; j <= k; j++) {
                int nextIndex = BS(events, events[i][1]);
                int take = events[i][2] + dp[ nextIndex][ j-1];

                int not_take = dp[i+1][j];

                 dp[i][j] = max(take, not_take);
            }
        }
        return dp[0][k];
    }
};