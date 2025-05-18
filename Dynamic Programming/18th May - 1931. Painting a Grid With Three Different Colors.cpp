// 1931. Painting a Grid With Three Different Colors


class Solution {
public:
const int mod = 1e9 + 7;
vector<string>columnStates;
void generateColumnStates(string curr , char prevChar , int len , int m ){
    if(len==m){
       columnStates.push_back(curr);
       return ; 
    }

    for(char ch : {'R', 'G', 'B'}){
        if(ch == prevChar) continue; 

        generateColumnStates(curr+ch , ch , len+1, m);
    }
}


int solve(int remainingColumns, int prevIdx, int m, vector<vector<int>>&dp ){
    if(remainingColumns == 0 ) return 1; 

    if(dp[remainingColumns][prevIdx]!=-1) return dp[remainingColumns][prevIdx];

    int ways = 0 ; 
    string prevState = columnStates[prevIdx];

    for(int i = 0 ; i<columnStates.size(); i++){
        if(i == prevIdx) continue; 

        string currState = columnStates[i];

        bool valid = true; 
        for(int i = 0 ; i<m; i++){
              if(currState[i]==prevState[i]){
                  valid = false; 
                  break; 
              }
        }

        if(valid){
            ways = (ways + solve(remainingColumns-1, i ,m,dp ))%mod;
        }
    }
    return dp[remainingColumns][prevIdx] =  ways; 
}



    int colorTheGrid(int m, int n) {
          generateColumnStates("", '*', 0, m);

          int result = 0 ; 
          vector<vector<int>>dp(n+1, vector<int>(columnStates.size()+1,-1));
          for(int i = 0 ; i < columnStates.size(); i++){
            result = (result + solve(n-1,i,m,dp))%mod; 
          }
          return result; 
    }
};