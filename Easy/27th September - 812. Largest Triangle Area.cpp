// 812. Largest Triangle Area


/*
✨ LeetCode POTD: Largest Triangle Area (812) 🔺

⁉️ Problem Statement:
🔸 You are given an array points where points[i] = [xi, yi] are distinct points in the plane.
🔸 Return the area of the largest triangle that can be formed by any 3 different points.
🔸 Answers within 10⁻⁵ of the correct value are accepted. 
LeetCode
+1

🔎 My Approaches:
1️⃣ Shoelace / Cross Product Formula
🔹 Iterate through all combinations of three points (i, j, k).
🔹 Use the formula
 area = | x1*(y2−y3) + x2*(y3−y1) + x3*(y1−y2) | / 2
 to compute the triangle area.
🔹 Update the maximum encountered area.

2️⃣ Heron’s Formula using Side Lengths
🔹 For each triplet, compute lengths a, b, c using hypot.
🔹 Compute semi-perimeter s = (a + b + c) / 2.
🔹 Area = sqrt(s * (s − a) * (s − b) * (s − c)).
🔹 Track max area across all triplets.


*/


// Approach 1: Shoelace / Cross Product Formula
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();

        double result  = 0 ; 
        for(int i = 0 ; i  < n-2; i++){
            for(int j = i +1 ; j < n-1; j++){
                for(int k = j + 1; k < n; k++){
                    double x1 = points[i][0];
                    double y1 = points[i][1];
                    double x2 = points[j][0];
                    double y2 = points[j][1];
                    double x3 = points[k][0];
                    double y3 = points[k][1];
                    
                    double area  = abs(x1 * (y2 - y3) + x2 * ( y3 - y1) + x3 * (y1 - y2))/2;

                    result = max(result , area);
                }
            }
        }
        return result; 
    }
};


// Approach 2: Heron's Formula using Side Lengths
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();

        double result  = 0 ; 
        for(int i = 0 ; i  < n-2; i++){
            for(int j = i +1 ; j < n-1; j++){
                for(int k = j + 1; k < n; k++){
                    double x1 = points[i][0];
                    double y1 = points[i][1];
                    double x2 = points[j][0];
                    double y2 = points[j][1];
                    double x3 = points[k][0];
                    double y3 = points[k][1];

                    double a = hypot(x2 - x1, y2 - y1);
                    double b = hypot(x2 - x3, y2 - y3);
                    double c = hypot(x3 - x1 , y3 - y1);

                    double s = (a + b + c)/2; 

                    double area = sqrt(s * (s-a) * (s -b ) * (s - c) );

                    result = max(result , area);
                }
            }
        }
        return result; 
    }
};