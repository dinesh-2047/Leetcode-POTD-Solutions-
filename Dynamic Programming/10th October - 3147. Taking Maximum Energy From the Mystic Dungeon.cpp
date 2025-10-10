// 3147. Taking Maximum Energy From the Mystic Dungeon


// Approach 1 Rec + memo
class Solution {
public:
int n ; 
vector<int>dp ;
int solve(vector<int> &energy, int i  , int k ){
    if(i >= n ) return 0 ; 
     if(dp[i]!= INT_MIN) return dp[i];
    return dp[i] =  energy[i] +  solve(energy, i + k , k);
}
    int maximumEnergy(vector<int>& energy, int k) {
         n = energy.size();
         int result = INT_MIN;
         dp.assign(n , INT_MIN);
        for(int i = 0 ; i  < n ; i++){
            result = max(result , energy[i] + solve(energy, i + k, k));
        }
        return result; 
    }
};


//Approach 2 bottom up 
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
         int n = energy.size();
      
        vector<int>dp(n , 0);
        for(int i = n-1; i >= 0 ; i--){
            if(i + k < n )
            dp[i] = energy[i] + dp[i + k ];
            else dp[i] = energy[i];
        }
        return *max_element(begin(dp), end(dp));
    }
};