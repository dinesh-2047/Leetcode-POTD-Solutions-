// 3443. Maximum Manhattan Distance After K Changes


/*
✨ LeetCode POTD: Maximum Manhattan Distance After K Changes (3443) 🧭📏

⁉️ Problem Statement (LeetCode):
🔸 You are given a string s consisting of characters 'N', 'S', 'W', 'E', and an integer k.
🔸 You start at the origin (0,0) on an infinite grid and follow the steps in s sequentially.
🔸 You may change up to k characters in s to any direction before walking.
🔸 Return the maximum Manhattan distance (|x| + |y|) from the origin that can be achieved at any point during the walk
.

🔎 Approach I Used (C++):

▶️ Greedy Simulation with Direction Tracking
🔹 Maintain counters for N, S, E, and W as you process the string.
🔹 At every step, compute:
 • currDist = |east - west| + |north - south|
 • steps = i + 1 — how many moves taken so far
🔹 Calculate wasted = steps - currDist, representing the number of steps that didn’t contribute to the distance.
🔹 You can reassign up to k wasted steps, each offering up to +2 boost (from opposite to your direction).
🔹 Compute extra = min(2 * k, wasted) and update the result with currDist + extra.

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(1)

*/

class Solution {
public:
    int maxDistance(string s, int k) {
     

        int north = 0 ; 
        int south = 0 ; 
        int west = 0 ; 
        int east = 0 ; 

        int result = 0 ; 
        

        for(int i = 0 ;i <s.length(); i++){
              char ch = s[i];

              if(ch=='N') north++;

              if(ch=='S') south++;

              if(ch=='W') west++;

              if(ch=='E') east++;


           int  currDist = abs(east-west) + abs(north-south);
           int  currSteps = i + 1; 

            int wasted = currSteps - currDist;
            
            int extra = 0 ; 
            if(currDist != currSteps){
                extra = min(2 *k , wasted);
            }

            result = max(currDist + extra , result);
        }

        return result; 
    }
};