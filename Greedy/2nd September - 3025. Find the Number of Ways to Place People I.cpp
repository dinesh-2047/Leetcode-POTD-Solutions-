// 3025. Find the Number of Ways to Place People I

/*
✨ LeetCode POTD: Find the Number of Ways to Place People (3025) 📰

⁉️ Problem Statement:
🔸 You are given a set of points on a 2D plane.
🔸 A pair (i, j) is valid if x1 <= x2 and y2 <= y1, and no other point lies strictly inside the rectangle formed by them.
🔸 Goal → Count the total number of such valid pairs.

🔎 My Approaches:

1️⃣ Grid Simulation Approach
🔹 Represent the 2D plane as a grid of size 51 x 51.
🔹 Place each given point on the grid with a marker.
🔹 For every marked point (x, y), explore rightwards (increasing x) and downwards (increasing y) to find possible rectangles.
🔹 Keep track of the nearest blocking points to avoid invalid rectangles.
🔹 Count valid rectangles whenever a new valid pair is found. This simulates the problem geometrically.

2️⃣ Triple Loop Brute Force Validation
🔹 Iterate through every possible pair (i, j) of points.
🔹 Check if they satisfy x1 <= x2 and y2 <= y1.
🔹 For each pair, run another loop through all remaining points to check if any lies inside their rectangle.
🔹 If no extra point is found inside, count it as a valid pair.
🔹 Straightforward but has O(n³) complexity, so it’s slow for larger inputs.

3️⃣ Sorting + Greedy Optimization
🔹 Sort the points by their x-coordinate, and if x is equal, sort by y in descending order.
🔹 For each point (x1, y1), try to form pairs with points (x2, y2) that come later in sorted order.
🔹 Maintain the maximum y-value (maxY) encountered so far during iteration.
🔹 If y1 >= y2 and y2 > maxY, then this pair is valid and counted.
🔹 This reduces unnecessary checks and works efficiently in O(n²) time.



*/



// Appraoch  1
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = 51; 
       vector<vector<int>>vec(51, vector<int>(51, 0));
       for(auto &point : points){
          int x = point[0];
          int y = point[1];

          vec[n-1-x][y] = 1; 
       } 
       int result = 0 ; 

       for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j  < n; j++){
             if(vec[i][j] == 1){
                int col = n ; 

                for(int k = i ; k < n; k++){
                    if(k!=i && vec[k][j] == 1) {
                        result++;
                        break; 
                    }
                    for(int l = j ; l < col ; l++){
                        if(k==i && l==j) continue; 
                        if(vec[k][l] == 1){
                            col = l ;
                            result++;
                        }
                    }
                }
             }
        }
       }
       return result; 

    }
};







// Approach 2 
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        int result = 0 ; 

        for(int i = 0 ; i < n; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];

            for(int j = 0 ; j < n; j++){
                if(i==j) continue; 
                int x2= points[j][0];
                int y2 = points[j][1];

               if(x1 <= x2 && y2 <= y1){
                   bool valid = true; 
                   for(int k = 0 ; k < n; k++){
                    if(k==i|| k == j ) continue; 
                      
                      int x3 = points[k][0];
                      int y3 = points[k][1];

                      if(x3 <= x2 && y3 >= y2 && x3 >= x1 && y3 <= y1) {
                        valid = false; 
                        break; 
                      }
                   }
                   if(valid ) result++;
               }
            }
        }
        return result; 
    }
};




//Approach 3
class Solution {
public:
static bool cmp(vector<int> &a , vector<int> &b){
    if(a[0] == b[0]){
      return  a[1] > b[1];
    }
    return a[0] < b[0];
}

    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        sort(begin(points), end(points), cmp);

        int result = 0  ; 

        for(int i = 0 ; i  < n; i++){
            int x1= points[i][0];
            int y1= points[i][1];
            int maxY = -1;
            for(int j = i +1; j  < n; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];

                if(y1 >= y2 && y2 > maxY){

                    result++;
                   maxY = y2 ; 
                }
            }
        }
        return result; 
    }
};