// 909. Snakes and Ladders/

/*
✨ LeetCode POTD: Snakes and Ladders (909) 🎲🐍🪜
⁉️ Problem Statement
🔸You are given an n x n integer matrix board where the cells are labeled from 1 to n² in a Boustrophedon style starting from the bottom left of the board (i.e., board[n - 1][0]) and alternating direction each row.
🔸You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n²)]. This simulates the result of a standard 6-sided die roll.

If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.

The game ends when you reach the square n².
🔸A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n² do not have a snake or ladder.
🔸Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.
🔸Return the least number of moves required to reach the square n². If it is not possible to reach the square, return -1.

🔎 Approach Used:

1️⃣ BFS-Based Shortest Path on Virtual Board
🔹 We simulate the game as a graph where each square is a node. From every square, we can move to the next 6 squares depending on dice rolls.
🔹 We use BFS (Breadth-First Search) to find the shortest path from square 1 to square n².
🔹 We convert square numbers to their (row, col) coordinates using a helper function getCoord(num) to handle the zigzag pattern correctly.
🔹 A visited matrix tracks whether a cell has been explored to avoid cycles.
🔹 If a square has a snake or ladder (i.e., board[row][col] != -1), we enqueue the destination instead of the actual square.
🔹 Return the number of BFS levels (dice rolls) needed to reach the target.

*/




class Solution {
public:
int n ;
pair<int, int> getCoord(int num){
    int rowFromTop = (num - 1)/n;
    int rowFromBottom = (n-1) - rowFromTop ; 

    int col = (num-1)%n;

    if((n%2==1 && rowFromBottom %2 ==1) || (n%2==0 && rowFromBottom %2 ==0)) col = (n-1) - col; //right to left  

    return {rowFromBottom , col};
}

    int snakesAndLadders(vector<vector<int>>& board) {
         n = board.size();
          
        int moves = 0 ; 

        queue<int>q; 

        vector<vector<bool>>visited(n, vector<bool>(n, false));

        visited[n-1][0] = true; 

        q.push(1);

        while(!q.empty()){
            int N = q.size();
            while(N--){
                int x = q.front();
                q.pop();

                if(x == n * n) return moves ; 

                for(int k = 1 ;  k <= 6; k++){
                    int val = x + k ; 
                    if(val > n*n) break; 

                    pair<int , int> coord = getCoord(val);
                    int row = coord.first; 
                    int col = coord.second; 

                    if(visited[row][col]) continue; 
                    visited[row][col] = true; 

                    if(board[row][col] == -1) q.push(val);

                    else {
                        q.push(board[row][col]);
                    }
                }
            }
            moves++;
        }
        return -1;

    }
};