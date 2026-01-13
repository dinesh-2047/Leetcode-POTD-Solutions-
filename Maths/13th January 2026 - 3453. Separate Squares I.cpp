// 3453. Separate Squares I


class Solution {
public:
double totalArea; 
bool check(vector<vector<int>> &squares, double mid_y){
    double bottomArea = 0.00000; 

    for(auto &square : squares){
        int bottom_y = square[1];
        int l = square[2];
        int top_y = bottom_y + l; 

        if(mid_y >= top_y){
            bottomArea += 1.0*l * l ;
        }
        else if(mid_y > bottom_y){
            bottomArea += l * (mid_y - bottom_y);
        }
    }

    return bottomArea >= totalArea/2.0;
}

    double separateSquares(vector<vector<int>>& squares) {
        totalArea = 0.00000;
         
        double l = INT_MAX ; 
        double r = INT_MIN;
        for(auto &square : squares){
            totalArea += 1.0 * square[2] * square[2];
            l = min(l , 1.0 * square[1]);
            r = max(r,1.0  * square[1] + square[2]);
        }
        
        double result = 0.00000;
        while(r - l > 1e-5){
            double mid_y = l + (r-l)/2.0;
             result = mid_y; 

            if(check(squares, mid_y)){
                r = mid_y; 
            }
            else l = mid_y; 
        }
        return result; 
        
    }
};