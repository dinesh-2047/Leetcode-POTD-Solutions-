// 3363. Find the Maximum Number of Fruits Collected


/*

 ✨ LeetCode POTD: Find the Maximum Number of Fruits Collected (3363) 🧠

⁉️ Problem Statement:
🔸 You are given a square grid fruits[][] of size n x n.
🔸 Three children (Child1, Child2, and Child3) must each collect fruits along distinct triangular paths:
  1. Child1: Diagonal from top-left to bottom-right (i.e., cell [i][i])
  2. Child2: Top-left triangle excluding diagonal (moves down, down-left, or down-right)
  3. Child3: Bottom-right triangle excluding diagonal (moves right, up-right, or down-right)
🔸 Each child collects fruits along their valid paths. The sum of all collected fruits is the final result.
🔸 The paths must not overlap, except at the start [0][0] and end [n-1][n-1].

🔎 My Approach:

1️⃣ Recursive DP with Memoization

🔹 Child1 – Diagonal Collection
Traverse all cells where i == j to get the diagonal sum. Simple O(n) pass.

🔹 Child2 – Top-Left Triangle (Recursive DP)
Start from the top-left corner, recursively collect max fruits by moving:
  🔹 down → [i+1][j]
  🔹 down-left → [i+1][j-1]
  🔹 down-right → [i+1][j+1]
Use memoization to avoid recomputation. Skip invalid or overlapping zones (i >= j or i == n-1 && j == n-1).

🔹 Child3 – Bottom-Right Triangle (Recursive DP)
Start from bottom-left, recursively move:
  🔹 right → [i][j+1]
  🔹 up-right → [i-1][j+1]
  🔹 down-right → [i+1][j+1]
Avoid overlapping with diagonal or upper triangle (i <= j or i == n-1 && j == n-1).

🔹 Final Result = Child1 + Child2 + Child3 (non-overlapping)

2️⃣ Bottom-Up Iterative DP (Optimized)

🔹 Preprocessing the Grid
Set values to 0 for cells outside the valid triangle zones:
  🔹 i < j && i + j < n-1 → outside top-left triangle
  🔹 i > j && i + j < n-1 → outside bottom-right triangle
This ensures DP is only computed where fruits can actually be collected.

🔹 Child2 DP Fill – Downward Triangle
Start filling DP from second row onward (since diagonal is reserved):
  🔹 dp[i][j] = fruits[i][j] + max(dp[i-1][j], dp[i-1][j-1], dp[i-1][j+1])

🔹 Child3 DP Fill – Rightward Triangle
Process columns left-to-right:
  🔹 dp[i][j] = fruits[i][j] + max(dp[i][j-1], dp[i-1][j-1], dp[i+1][j-1])

🔹 Combine Results:
  Total = diagonalSum + dp[n-2][n-1] + dp[n-1][n-2]




*/



// Approach 1 rec + memo 
class Solution {
public:
int n ; 
vector<vector<int>>dp;
int solveC2(int i, int j , vector<vector<int>> &fruits ){

    if(i>=n || j < 0 || j >= n || (i==n-1 && j==n-1) || i >= j ) return 0; 
    
    if(dp[i][j]!=-1) return dp[i][j];

      int bottom = fruits[i][j] + solveC2(i + 1 , j, fruits );
      int bottomRight = fruits[i][j] + solveC2(i+1, j + 1, fruits);
      int bottomLeft = fruits[i][j] +solveC2(i + 1 , j -1, fruits);
     

      return dp[i][j] =  max({bottom , bottomRight , bottomLeft});
}

int solveC3(int i , int j , vector<vector<int>> &fruits){
    if(i < 0 || j >= n || i>=n || i <= j || (i==n-1 && j==n-1)) return 0; 
    if(dp[i][j]!=-1) return dp[i][j];

    int right = fruits[i][j] + solveC3(i, j + 1, fruits);
    int upRight = fruits[i][j] + solveC3(i-1, j + 1, fruits);
    int bottomRight = fruits[i][j] + solveC3(i+1, j + 1, fruits);

    return dp[i][j] =  max({right , upRight , bottomRight });
}

    int maxCollectedFruits(vector<vector<int>>& fruits) {
         n = fruits.size();

         int child1 = 0 ; 
         for(int i = 0 ; i  < n; i++){
            child1 += fruits[i][i];
         }
         dp.resize(n+1, vector<int>(n+1, -1));
         int child2 = solveC2(0 ,n-1, fruits);
         int child3 = solveC3(n-1, 0 , fruits);

         return child1+ child2 + child3;
         
    }
};








//Approach 2 bottom up 
class Solution {
public:
int n ; 
vector<vector<int>>dp;

    int maxCollectedFruits(vector<vector<int>>& fruits) {
         n = fruits.size();

         int child1 = 0 ; 
         for(int i = 0 ; i  < n; i++){
            child1 += fruits[i][i];
         }
         dp.resize(n, vector<int>(n, 0));
           

           for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < n; j++){
                if(i  < j && i + j < n-1){
                   dp[i][j] = 0;
                }
                else if(i > j && i + j < n-1){
                  dp[i][j] = 0 ;
                }
                else dp[i][j] = fruits[i][j];
            }
           }
        

         for(int i = 1; i < n; i++){
            for(int j = i + 1; j < n; j++){
                dp[i][j] +=  max({dp[i-1][j], dp[i-1][j-1],(j+1 < n )  ?dp[i-1][j+1] : 0} );
            }
         }

     
         for(int j = 1; j < n; j++){
            for(int i = j + 1; i < n; i++){
                dp[i][j] += max({dp[i][j-1], dp[i-1][j-1],(i+1 < n )  ?dp[i+1][j-1] : 0} );
            }
         }
       

       return child1 + dp[n-2][n-1]  + dp[n-1][n-2]; 
         
         
         
    }
};