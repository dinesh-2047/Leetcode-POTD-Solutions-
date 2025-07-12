// 1900. The Earliest and Latest Rounds Where Players Compete


/*

⁉️ Problem Statement:
 🔸 There is a tournament with n players standing in a single row, numbered from 1 to n.
 🔸 In each round, the i-th player from the front competes against the i-th player from the back. If the number of players is odd, the middle player advances automatically.
 🔸 Two players firstPlayer and secondPlayer always win unless they play each other.
 🔸 Goal: Return the earliest and latest possible rounds in which these two players could compete.

🔎 Approach I Used: 
1️⃣Recursive Simulation with Position Mapping
🔹 Base Case: If firstPlayer already faces secondPlayer, return {1, 1}.
 🔹 Symmetry Handling:
 • Always keep firstPlayer < secondPlayer
 • Map both players to the front half using symmetry logic (n - x + 1)
 🔹 Recursive Transition:
 • Simulate all valid ways players can win and advance to the next round while preserving possible positions of firstPlayer and secondPlayer
 • If both players lie in the front half, loop over:
 ◦ remainLeft: Players before firstPlayer
 ◦ remainMid: Players between firstPlayer and secondPlayer
 • If secondPlayer lies in the back half, calculate:
 ◦ Symmetric opponent for secondPlayer
 ◦ Extra gap from symmetry
 ◦ Adjust next round positions accordingly
 🔹 Track and Update:
 • Minimum value of earliest and maximum of latest across all valid paths
 • Use (n+1)/2 to compute next round's player count
 🔹 Return: Recursively build results and return {earliest, latest} rounds.

*/


class Solution {
public:
vector<int> solve(int n , int firstPlayer , int secondPlayer ){
      if(firstPlayer == n- secondPlayer + 1) return {1, 1};

      if(firstPlayer  > n - secondPlayer  + 1){
        int temp = n - firstPlayer + 1; 
        firstPlayer = n - secondPlayer + 1; 
        secondPlayer = temp ; 
      }


      int earliest = n ; 
      int latest = 1 ; 
      int nextRoundPlayercnt = (n+1)/2; 


      if(secondPlayer <= nextRoundPlayercnt){
        

           for(int remainLeft = 0 ; remainLeft <= firstPlayer - 1; remainLeft++){
            for(int remainMid = 0 ; remainMid <= secondPlayer - firstPlayer - 1; remainMid++){
                 int firstPlayerPos = remainLeft +1 ; 
                 int secondPlayerPos = firstPlayerPos  + remainMid + 1; 
                 vector<int>tempResult = solve(nextRoundPlayercnt,firstPlayerPos, secondPlayerPos );

                 earliest = min(earliest , tempResult[0] + 1);
                 latest  = max(latest, tempResult[1] +1);
            }
           }
      }
           else{
                 int secondPlayerOpponent = n - secondPlayer + 1; 
                 int cntLeft = firstPlayer - 1; 
                 int midCount= secondPlayerOpponent - firstPlayer - 1;
                 int remainMidCount = secondPlayer - secondPlayerOpponent - 1; 


                 for(int remainLeft = 0 ; remainLeft <= firstPlayer - 1; remainLeft++){
            for(int remainMid = 0 ; remainMid <= secondPlayerOpponent - firstPlayer - 1; remainMid++){
                 int firstPlayerPos = remainLeft +1 ; 
                 int secondPlayerPos = firstPlayerPos  + remainMid + (remainMidCount+1)/2 +  1; 
                 vector<int>tempResult = solve(nextRoundPlayercnt,firstPlayerPos, secondPlayerPos );

                 earliest = min(earliest , tempResult[0] + 1);
                 latest  = max(latest, tempResult[1] +1);
            }
           }

        
      }
      return {earliest , latest };


}

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        return solve(n , firstPlayer , secondPlayer);
    }
};