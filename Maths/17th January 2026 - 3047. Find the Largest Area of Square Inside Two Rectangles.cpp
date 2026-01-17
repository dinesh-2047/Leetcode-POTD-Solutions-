// 3047. Find the Largest Area of Square Inside Two Rectangles


class Solution {
public:
using ll = long long ; 
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();

        ll result = 0 ; 
        for(int i = 0 ; i < n-1; i++){
            for(int j = i  + 1; j < n ; j++){
                int x1 = bottomLeft[i][0];
                int y1 = bottomLeft[i][1];
                int x2 = topRight[i][0];
                int y2 = topRight[i][1];

                int x3 = bottomLeft[j][0];
                int y3 = bottomLeft[j][1];
                int x4 = topRight[j][0];
                int y4 = topRight[j][1]; 

                int topRightx = min(x2, x4);
                int bottomLeftx = max(x1, x3);

                int w =topRightx - bottomLeftx; 

                int topRighty = min(y2, y4);
                int bottomLefty = max(y1, y3);

                int h = topRighty - bottomLefty ; 

                 if (w <= 0 || h <= 0) continue;

                int side = min(w, h);
                result = max(result, (ll) side * side);
            }
            
        }
        return result; 
    }
};