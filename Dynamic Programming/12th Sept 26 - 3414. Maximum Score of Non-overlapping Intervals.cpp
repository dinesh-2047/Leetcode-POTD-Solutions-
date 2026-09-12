// 3414. Maximum Score of Non-overlapping Intervals

struct Node{
   long long score = -1; 
   vector<int> idxs; 
};

class Solution {
public:
int n ; 
vector<int> nextIdx; 
vector<vector<Node>> dp; 
int findIdx(vector<vector<int>> &intervals, int i){
    int st = 0; 
    int end = n - 1; 

    int j = n;
    while(st <= end){
        int mid = st + (end - st)/2; 
        if(intervals[mid][0] > intervals[i][1]){
            j = mid; 
            end = mid - 1; 
        }
        else {
            st = mid  + 1 ; 
        }
    }
    return j ;
}
Node solve(vector<vector<int>> &intervals, int i , int cnt){
    if(cnt == 0 || i >= n  ){
        return Node() ;
    }
     
    if(dp[i][cnt].score!=-1) return dp[i][cnt];

    long long wt = intervals[i][2];
    int idx = intervals[i][3];
    int j = nextIdx[i];

    Node not_take = solve(intervals, i + 1, cnt); //not_take 

    Node temp = solve(intervals, j, cnt - 1); // take 


    Node take ; 
    take.score = intervals[i][2] + temp.score; 
    take.idxs = temp.idxs; 
    take.idxs.push_back(idx);
    sort(begin(take.idxs), end(take.idxs));


    Node result;
    if(not_take.score > take.score){
        result = not_take; 
    }
    else if(not_take.score < take.score){
        result = take; 
    }
    else {
        result = (not_take.idxs < take.idxs) ? not_take : take; 
    }

    return dp[i][cnt] =  result; 

}

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();
        for(int i = 0 ; i < n ; i++){
            intervals[i].push_back(i);
        }

        sort(begin(intervals), end(intervals));

         nextIdx.resize(n);

         for(int i = 0 ; i  < n; i++){
            nextIdx[i] = findIdx(intervals, i);
         }
         dp.resize(n + 1, vector<Node> (5));
         return solve(intervals, 0, 4 ).idxs; 
    }
};